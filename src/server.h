#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <queue>
#include <vector>

class DB;

extern DB db;

std::string init_server(int argc, char **argv);

class DB {
private:
    bool read_file(const std::string& filename, std::vector<std::string>& lines) {
        std::ifstream file_stream(filename);
        if (!file_stream.is_open()) {
            std::cerr << "Error: Unable to open " << filename << std::endl;
            return false;
        }

        std::string line;
        while (std::getline(file_stream, line)) {
            lines.push_back(line);
        }

        return true;
    }

    void load_clients(const std::string& client_file) {
        std::vector<std::string> lines;
        if (!read_file(client_file, lines)) return;

        if (lines.empty()) {
            std::cerr << "Error: Client file is empty." << std::endl;
            return;
        }

        int num_clients = std::stoi(lines[0]);
        if (num_clients != lines.size() - 1) {
            std::cerr << "Warning: Client count mismatch." << std::endl;
        }

        for (int i = 1; i <= num_clients; i++) {
            clients[lines[i]] = "default_value";
        }
    }

    void load_resources(const std::string& resources_file) {
        std::vector<std::string> lines;
        if (!read_file(resources_file, lines)) return;

        if (lines.empty()) {
            std::cerr << "Error: Resources file is empty." << std::endl;
            return;
        }

        int num_resources = std::stoi(lines[0]);
        if (num_resources != lines.size() - 1) {
            std::cerr << "Warning: Resource count mismatch." << std::endl;
        }

        for (int i = 1; i <= num_resources; i++) {
            resources.insert(lines[i]);
        }
    }

    void load_approvals(const std::string& approval_file) {
        std::vector<std::string> lines;
        if (!read_file(approval_file, lines)) return;

        for (const auto& line : lines) {
            std::stringstream ss(line);
            std::string item;
            std::vector<std::string> items;

            while (std::getline(ss, item, ',')) {
                items.push_back(item);
            }

            if (items.size() % 2 != 0) {
                std::cerr << "Warning: Approval data format error in line: " << line << std::endl;
                continue;
            }

            for (size_t i = 0; i < items.size() - 1; i += 2) {
                approvals.push(std::make_pair(items[i], items[i + 1]));
            }
        }
    }

public:
    std::unordered_map<std::string, std::string> clients;
    std::unordered_set<std::string> resources;
    std::queue<std::pair<std::string, std::string>> approvals;
    int token_validity;

    DB(const std::string& client_file, const std::string& resources_file, const std::string& approval_file, int token_validity)
        : token_validity(token_validity)
    {
        load_clients(client_file);
        load_resources(resources_file);
        load_approvals(approval_file);
    }

    ~DB() = default;

    void print_all() {
        std::cout << "Clients:" << std::endl;
        for (const auto& client : clients) {
            std::cout << client.first << std::endl;
        }

        std::cout << "Resources:" << std::endl;
        for (const auto& resource : resources) {
            std::cout << resource << std::endl;
        }

        std::cout << "Approvals:" << std::endl;
        std::queue<std::pair<std::string, std::string>> approvals_copy = approvals;
        while (!approvals_copy.empty()) {
            std::cout << approvals_copy.front().first << " " << approvals_copy.front().second << std::endl;
            approvals_copy.pop();
        }
    }
};

#endif // SERVER_H
