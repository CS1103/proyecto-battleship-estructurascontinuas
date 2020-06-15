#include <iostream>
#include <fstream>

using namespace std;

void out(const string& str) {
    ofstream file;
    file.open("../in/FirstPlayer.in");
    file << str;
}

int main() {
    out("ga");
}
