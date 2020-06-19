#include <map>
#include <vector>
#include <queue>
#include <string>
#include <string_view>
#include <memory>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <filesystem>
#include <numeric>
#include <random>
#include <sstream>
#include <future>
#include <optional>
#include <regex>
#include <utility>

using namespace std;


// Para que funcione, corre el codigo, COPIA el .out del directorio dentro de out
//el programa esperara hasta que haya un .out en el la carpeta out, leera lo que esta dentro y dps eliminara el out

int randint(int a, int b){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(a,b);
    return dist6(rng);
}

class player_t {

};

struct statement_t {
    string action;
    string token;
    string status;
    string parameter;
};

using statement_item_t = std::pair<size_t, statement_t>;

class controller_t {
private:
    string columns_;
    size_t rows_;
    filesystem::path player_;
    queue<statement_item_t> statements_;
    optional<size_t> winner_;

    void start(const statement_item_t &item) {

    }

    void build(const statement_item_t &item) {

    }

    void attack(const statement_item_t &item) {

    }

public:
    controller_t(size_t rows, std::string_view columns, std::string_view first) {
        player_ = filesystem::current_path() / first, "FirstPlayer";
        if (!filesystem::exists(player_.root_path() / "in"))
            filesystem::create_directories(player_.root_path() / "in");
        if (!filesystem::exists(player_.root_path() / "out"))
            filesystem::create_directories(player_.root_path() / "out");
    }

    void load_tokens() {

    }
};
    /*void save_tokens(){
        while (true) {
            try {
                while (!statements_.empty()) {
                    auto item_ = statements_.front();
                    statements_.pop();
                    switch (item_.second.action) {
                        case action_t::start:
                            start(item_);
                            break;
                        case action_t::build:
                            build(item_);
                            break;
                        case action_t::attack:
                            attack(item_);
                            break;
                    }
                }
            }
            catch (const std::exception& e) {
                std::cerr << e.what();
            }
        }
    }
    void execute() {
        auto load_ = std::async([&] { load_tokens(); });
        auto save_ = std::async([&] { save_tokens(); });
    }
};*/


void out(const string& str) {
    ofstream file;
    file.open("../out/FirstPlayer.out");
    file << str;
}

statement_t in () { // devuelve el comando que haya en el .in
    ifstream file;
    statement_t statement;
    string line;
    int idx = 0;
    file.open("../in/FirstPlayer.in");
    if (file.is_open    ())
    {
        getline (file,line);
        statement.action = line;

        getline (file,line);
        int pos = line.find('=')+1;
        statement.status = line.substr(pos);

        getline (file,line);
        pos = line.find('=')+1;
        statement.token = line.substr(pos);

        getline (file,line);
        pos = line.find('=')+1;
        statement.parameter = line.substr(pos);

        file.close();
    }
    else{cout << "no se puede abrir";}
    return statement;
}

void handshakeIn(const string& name) {
    string str = "HANDSHAKE=" + name;
    out(str);
}

string placeFleet(statement_t* FirstStatement, string& type){ // recive el primer statement y
    int Wbound = FirstStatement->parameter[0];                // el tipo de nave a colocar
    cout << Wbound << " ";
    int pos = FirstStatement->parameter.find('-')+1;
    int Nbound = stoi(FirstStatement->parameter.substr(pos));
    cout << Nbound << " ";
    string str = "TOKEN=" + FirstStatement->token + "\n";
    string coordinates;
    coordinates += char(randint(65, Wbound));
    coordinates += to_string(randint(1, Nbound));
    vector<char> orientaciones = {'H', 'V'};
    char orientacion = orientaciones[randint(0, 1)];
    str += "PLACEFLEET=" + type + "-" + coordinates + "-" + orientacion;
    return str; // Devuelve un string para hacer push en el .out
}

statement_t waitIn() {    // observer? espera hasta que exista un archivo.in
    ifstream file;
    file.open("../in/FirstPlayer.in");
    while (!file.is_open()) {
        file.open("../in/FirstPlayer.in");
    }
    statement_t statement = in();
    return statement;
    //remove("../out/FirstPlayer.out"); //borra el .out
}//guarda la informacion del .in



int main() {
    //handshakeIn("dinamita team");
    statement_t st = waitIn();
    statement_t* pst = &st;
    //cout << st.token << endl;
    string type = "A";
    out(placeFleet(pst, type));
    return 0;
}