#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>

using namespace std;


// Para que funcione, corre el codigo, COPIA el .out del directorio dentro de out
//el programa esperara hasta que haya un .out en el la carpeta out, leera lo que esta dentro y dps eliminara el out


void out(const string& str) {
    ofstream file;
    file.open("../in/FirstPlayer.in");
    file << str;
}

vector<string> in () { // devuelve el comando que haya en el .out
    ifstream file;
    vector<string> comando(10);
    string line;
    int idx = 0;
    file.open("../out/FirstPlayer.out");
    if (file.is_open    ())
    {
        while ( getline (file,line) )
        {
            comando[idx] = line;

            idx++;
        }
        file.close();
    }
    else{cout << "no se puede abrir";}
    return comando;
}

void handshakeIn(const string& name) {
    string str = "HANDSHAKE=" + name;
    out(str);
}

void waitOut() {    // observer? espera hasta que exista un archivo.out
    ifstream file;
    file.open("../out/FirstPlayer.out");
    while (!file.is_open()) {
        file.open("../out/FirstPlayer.out");
    }
    vector<string> command = in();
    if (command[0] == "HANDSHAKE\r") {
        string status =  command[1].substr(7);
        if (status == "ACCEPTED\r") {
            string token = command[2].substr(6);
            cout << token <<endl;
        }
        else if (status == "REJECTED\r") {

        }
    }
    else if (command[0] == "PLACEFLEET\r") {

    }
    else if (command[0] == "ATTACK\r") {

    }//guarda la informacion del .out
    //remove("../out/FirstPlayer.out"); //borra el .out
}

int main() {
    //handshakeIn("dinamita team");
    waitOut();
}
