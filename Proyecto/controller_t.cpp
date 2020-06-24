//
// Created by Acer on 21/06/2020.
//

#include "controller_t.h"
//global variable
vector<char> modelsava = {'A','B','B','S','S','S','T','T','T','T'};

void controller_t::printBoard(){

    for (int j = 0; j < board_.get_rows(); j++) {

        for (int i = 0; i < board_.get_cols()-65; i++){
            if (board_.get_pCells()[j][i]->get_status() == "clear")
            cout << "...";

            else if (board_.get_pCells()[j][i]->get_status() == "filled")
                cout << "[ ]";
        }
        cout << endl;
    }
    cout << "\n";
}

void out(const string& str) {
    ofstream file;
    file.open("../in/FirstPlayer.in");
    file << str;
}

statement_t in () { // devuelve el comando del .out
    ifstream file;
    statement_t statement;
    string line;
    int idx = 0;
    file.open("../out/FirstPlayer.out");
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
    return statement;
}

statement_t waitIn() {    // observer? espera hasta que exista un archivo.out
    ifstream file;
    file.open("../out/FirstPlayer.out");
    while (!file.is_open()) {
        file.open("../out/FirstPlayer.out");
    }
    statement_t statement = in();
    remove("../out/FirstPlayer.out"); //borra el .out
    return statement;
}//guarda la informacion del .in

string controller_t::placeFleet(model_t& model){ // recibe el primer statement y
    string str = "TOKEN=" + token_ + "\n";
    char cols;
    size_t rows;
    char orientacion;
    navy_t navy = navy_t(cols, rows, model, orientacion, board_ ,rows,cols); //no importan los primeros dos
    //char cols = char(randint(65, board_.get_cols()));
    //size_t rows = randint(1, board_.get_rows());
    cout << "model " << model << "\n";
    cout << "coor: " << cols << "-" << rows << "\n";
    cout << "orientation " << orientacion << "\n";
    //creacion del string
    string coordinates;
    coordinates += cols;
    coordinates += to_string(rows);
    str += "PLACEFLEET=";
    str += model;
    str += "-" + coordinates + "-" + orientacion;
    return str; // Devuelve un string para hacer push en el .out - working
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
        while( statements_.front().parameter != "WINNER\r") {
            //cout << "El .out fue recibido c: \n";
            while(statements_.front().status == "REJECTED\r") {
                handshakeIn("BattleBot");
                break;
            }
            while( statements_.front().action == "PLACEFLEET\r" || (statements_.front().status == "ACCEPTED\r" && !hPassed)) {

                if (!hPassed) {
                    setBoard(statements_.front().parameter);
                    cout << "Board inicializado con:\n";
                    cout << board_.get_rows() <<" rows\n";
                    cout << board_.get_cols() <<" cols\n";
                    setToken(statements_.front().token);
                    cout << "Controller inicializado con:\n";
                    cout << "token: " << token_ <<"\n";
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
    if (modelsava.empty()){
        cout << "Flota completa" << endl;
        return;
    }
    if (find(modelsava.begin(),modelsava.end(),model)!=modelsava.end()){
        modelsava.erase(find(modelsava.begin(),modelsava.end(),model));
        cout << "Entrando a creacion de barco \n";
        auto str =  placeFleet(model);
        printBoard();
        out(str);

    }
    else{
        build(item);
    }
}

void controller_t::attack(const statement_t &item) {

}

void controller_t::setToken(const text_t& token) {
    token_ = token;
}

board_t controller_t::getBoard() {
    return board_t();
}
