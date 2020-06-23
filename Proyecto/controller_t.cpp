//
// Created by Acer on 21/06/2020.
//

#include "controller_t.h"

int randint(int a, int b){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(a,b);
    return dist6(rng);
}

void out(const string& str) {
    ofstream file;
    file.open("../out/FirstPlayer.out");
    file << str;
}

statement_t in () { // devuelve el comando del .in
    ifstream file;
    statement_t statement;
    string line;
    int idx = 0;
    file.open("../in/FirstPlayer.in");
    if (file.is_open    ())
    {
        getline (file,line);
        if (line == "HANDSHAKE\r"){
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
        }

        else {
            statement.action = line;

            getline (file,line);
            int pos = line.find('=')+1;
            statement.status = line.substr(pos);

            getline (file,line);
            pos = line.find('=')+1;
            statement.parameter = line.substr(pos);
        }
        file.close();
    }
    else{cout << "no se puede abrir";}
    return statement;
}

statement_t waitIn() {    // observer? espera hasta que exista un archivo.in
    ifstream file;
    file.open("../in/FirstPlayer.in");
    while (!file.is_open()) {
        file.open("../in/FirstPlayer.in");
    }
    statement_t statement = in();
    remove("../in/FirstPlayer.in"); //borra el .out
    return statement;
}//guarda la informacion del .in

string controller_t::placeFleet(model_t& model){ // recibe el primer statement y
    string str = "TOKEN=" + token_ + "\n";
    cout << "token: " << token_ << "\n";
    char cols = char(randint(65, board_.get_cols()));
    size_t rows = randint(1, board_.get_rows());
    cout << "coor: " << cols << "-" << rows << "\n";
    vector<char> orientaciones = {'H', 'V'};
    char orientacion = orientaciones[randint(0, 1)];
    cout << "orientation: " << orientacion << "\n";
    navy_t navy = navy_t(cols-65, rows, model, orientacion, board_);
    //creacion del string
    string coordinates;
    coordinates += cols;
    coordinates += to_string(rows);
    str += "PLACEFLEET=";
    str += model;
    str += "-" + coordinates + "-" + orientacion;
    return str; // Devuelve un string para hacer push en el .out
}

void controller_t::handshakeIn(const string& name) {
    string str = "HANDSHAKE=" + name;
    out(str);
}

void controller_t::execute() {
    bool hPassed = false;

    handshakeIn("BattleBot");
    statements_.push(waitIn());
    while(!statements_.empty()){
        //statement_t ste = statements_.front();
        cout << statements_.front().action << endl;
        cout << statements_.front().status << endl;
        cout << statements_.front().parameter << endl;

        while( statements_.front().parameter != "WINNER\r") {
        cout << "paso 1 \n";
            while(statements_.front().status == "REJECTED\r") {
                handshakeIn("BattleBot");
                break;
            }
            while( statements_.front().action == "PLACEFLEET\r" || ( statements_.front().status == "ACCEPTED\r" && !hPassed)) {
                cout << "paso 2 \n";
                if (!hPassed) {
                    setBoard(statements_.front().parameter);
                    setToken(statements_.front().token);
                }
                hPassed = true;
                build( statements_.front());
                break;
            }
            while( statements_.front().action == "ATTACK\r" || statements_.front().parameter == "FULL\r") {
                attack( statements_.front());
                break;
            }
            statements_.pop();
            statements_.push(waitIn());
        }
    }

}

void controller_t::load_tokens() {

}

void controller_t::save_tokens() {

}

controller_t::controller_t(text_t& name) {
    name_ = name;
}

void controller_t::setBoard(parameter_t scope) {
    auto cols = scope[0];
    auto rows = stoi(scope.substr(2));
    board_ = board_t(cols, rows);
}

void controller_t::build(const statement_t &item) {

    vector<model_t> models_t = {'A', 'B', 'S', 'T'};
    auto model = models_t[randint(0, 3)];
    cout << "paso 3 \n";
    //cout << placeFleet(model);
    out(placeFleet(model));
    getBoard().print();
}

void controller_t::attack(const statement_t &item) {

}

void controller_t::setToken(const text_t& token) {
    token_ = token;
}

board_t controller_t::getBoard() {
    return board_t();
}
