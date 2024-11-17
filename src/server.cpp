#include "server.h"

using namespace std;

string init_server(int argc, char **argv) {
    if (argc != 5) {
        return "Usage: " + string(argv[0]) + " <client file> <resources file> <approval file> <token validity>\n";
    }
    return "";
}