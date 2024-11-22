#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <tuple>
#include <string>
#include <vector>
#include <unordered_map>

struct Token{
    std::string access_token;
    std::string refresh_token;
};

class MyClient {
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

        void load_input(const std::string& input_file) {
            std::vector<std::string> lines;
            if (!read_file(input_file, lines)) return;

            for (const auto& line : lines) {
                std::string id;
                std::string action;
                std::string value;

                std::stringstream ss(line);
                std::getline(ss, id, ',');
                std::getline(ss, action, ',');
                std::getline(ss, value, ',');

                requests.push(std::make_tuple(id, action, value));
            }
        }

    public:
        std::queue<std::tuple<std::string, std::string, std::string>> requests;
        std::unordered_map<std::string, Token> tokens;

        MyClient() = default;

        explicit MyClient(const std::string& input_file) {
            load_input(input_file);
        }

        ~MyClient() = default;

        void print_all() const {
            std::cout << "Client Input:" << std::endl;
            std::queue<std::tuple<std::string, std::string, std::string>> requests_copy = requests;
            while (!requests_copy.empty()) {
                std::cout << std::get<0>(requests_copy.front()) << " " 
                          << std::get<1>(requests_copy.front()) << " "
                          << std::get<2>(requests_copy.front()) << std::endl;
                requests_copy.pop();
            }
        }
};

extern MyClient client;

std::string init_client(int argc, char **argv);

#endif /* CLIENT_H */
