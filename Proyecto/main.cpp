#include <iostream>
#include <fstream>

using namespace std;

void out(const string& str) {
    ofstream file;
    file.open("../in/FirstPlayer.in");
    file << str;
}

string in () {
    ifstream file;
    string comando;
    string line;
    file.open("../out/FirstPlayer.out");
    if (file.is_open    ())
    {
        while ( getline (file,line) )
        {
            comando += line + '\n';
        }
        file.close();
    }
    else{cout << "no se puede abrir";}
    return line;
}

void handshake(const string& name) {
    string str = "HANDSHAKE=" + name;
    out(str);
}

int main() {
    handshake("dinamita team");
    cout << in();
}
