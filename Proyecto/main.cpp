#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;


// Para que funcione, corre el codigo, COPIA el .out del directorio dentro de out
//el programa esperara hasta que haya un .out en el la carpeta out, leera lo que esta dentro y dps eliminara el out


void out(const string& str) {
    ofstream file;
    file.open("../in/FirstPlayer.in");
    file << str;
}

string in () { // devuelve el comando que haya en el .out
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

void waitOut() {    // observer? espera hasta que exista un archivo.out
    ifstream file;
    file.open("../out/FirstPlayer.out");
    while (!file.is_open()) {
        file.open("../out/FirstPlayer.out");
    }
    cout << in() << endl; //guarda la informacion del .out
    remove("../out/FirstPlayer.out"); //borra el .out
}

int main() {
    handshake("dinamita team");
    waitOut();
    cout << "se encontro out";
}
