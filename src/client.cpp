#include "client.h"

using namespace std;

string init_client(int argc, char **argv) {
    if (argc != 3) {
        return "Usage: " + string(argv[0]) + "<server_host> <input file>\n";
    }
    
    cout << "Starting client..." << endl;
    cout << "Input file: " << argv[2] << endl;

    Client client(argv[2]);

    if (client.requests.empty()) {
        return "Error: Unable to load data.\n";
    }
    
    return "";
}