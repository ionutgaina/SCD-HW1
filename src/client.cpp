#include "client.h"

MyClient client;

std::string init_client(int argc, char **argv) {
    if (argc != 3) {
        return "Usage: " + std::string(argv[0]) + " <server_host> <input file>\n";
    }

    std::cout << "Starting client..." << std::endl;
    std::cout << "Input file: " << argv[2] << std::endl;

    client = MyClient(argv[2]);

    if (client.requests.empty()) {
        return "Error: Unable to load data.\n";
    }

    return "";
}
