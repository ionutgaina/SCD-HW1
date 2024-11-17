#include "server.h"

using namespace std;

string init_server(int argc, char **argv) {
    if (argc != 5) {
        return "Usage: " + string(argv[0]) + " <client file> <resources file> <approval file> <token validity>\n";
    }
    
    cout << "Starting server..." << endl;
    cout << "Client file: " << argv[1] << endl;
    cout << "Resources file: " << argv[2] << endl;
    cout << "Approval file: " << argv[3] << endl;
    cout << "Token validity: " << argv[4] << endl;

    DB db(argv[1], argv[2], argv[3], stoi(argv[4]));

    if (db.clients.empty() || db.resources.empty() || db.approvals.empty()) {
        return "Error: Unable to load data.\n";
    }
    
    return "";
}