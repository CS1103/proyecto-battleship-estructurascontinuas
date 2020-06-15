#include <iostream>
#include <fstream>

using namespace std;

void out(const string& str) {
    ofstream file;
    file.open("../in/FirstPlayer.in");
    file << str;
}

void handshake(const string& name) {
    string str = "HANDSHAKE=" + name;
    out(str);
}

int main() {
    handshake("dinamita team");
}
