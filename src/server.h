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

std::string init_server(int argc, char **argv);

struct ClientData {
    std::string access_token;
    std::string refresh_token;
    std::string perms;
    int ttl;
};

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
            save_client(lines[i], "", "");
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

        if (lines.empty()) {
            std::cerr << "Error: Approvals file is empty." << std::endl;
            return;
        }

        for (const auto& line : lines) {
            approvals.push(line);
        }
    }

public:
    std::unordered_map<std::string, ClientData> clients;
    std::unordered_map<std::string, std::string> client_tokens_approval;
    std::unordered_set<std::string> resources;
    std::queue<std::string> approvals;
    int token_validity;

    DB(const std::string& client_file, const std::string& resources_file, const std::string& approval_file, int token_validity)
        : token_validity(token_validity)
    {
        load_clients(client_file);
        load_resources(resources_file);
        load_approvals(approval_file);
    }

    DB() = default;
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
        std::queue<std::string> temp = approvals;
        while (!temp.empty()) {
            std::cout << temp.front() << std::endl;
            temp.pop();
        }
    }

    bool is_client(const std::string& id) {
        return clients.find(id) != clients.end();
    }

    void save_client(const std::string& id, const std::string& access_token, const std::string& refresh_token) {
        clients[id].access_token = access_token;
        clients[id].refresh_token = refresh_token;
        clients[id].ttl = token_validity;
    }
};

#endif // SERVER_H
