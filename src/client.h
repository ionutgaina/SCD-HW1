#ifndef CLIENT_H
#define CIENT_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <tuple>
#include <string>

class Client;

extern Client client;

std::string init_client(int argc, char **argv);

class Client {
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
                int value;

                std::stringstream ss(line);
                std::getline(ss, id, ',');
                std::getline(ss, action, ',');
                ss >> value;

                requests.push(std::make_tuple(id, action, value));
            }
        }

    public:
        std::queue<std::tuple<std::string, std::string, int>> requests;

        Client(const std::string& input_file) {
            load_input(input_file);
            print_all();
        }

        ~Client() = default;

        void print_all() {
            std::cout << "Client Input:" << std::endl;
            std::queue<std::tuple<std::string, std::string, int>> requests_copy = requests;
            while (!requests_copy.empty()) {
                std::cout << std::get<0>(requests_copy.front()) << " " << std::get<1>(requests_copy.front()) << " " << std::get<2>(requests_copy.front()) << std::endl;
                requests_copy.pop();
            }
        }



};


#endif /* CLIENT_H */
