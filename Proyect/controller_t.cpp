#include "controller_t.h"

//global variable
//vector<char> modelsava = {'A','B','S','S','S','T','T','T','T'};
vector<char> modelsava = {'A', 'B', 'S', 'T'};


int n = 1;

controller_t::controller_t(text_t name) {
    name_ = name;
    if (!filesystem::exists(board_.get_path() / "in"))
        filesystem::create_directories(board_.get_path() / "in");
    if (!filesystem::exists(board_.get_path() / "out"))
        filesystem::create_directories(board_.get_path() / "out");
}

void controller_t::print_board() {
    int a =1;
    cout << setw(4);
    for (int i = 65; i <= board_.get_cols(); i++)
        cout << char(i) << " ";
    cout << endl;
    cout << setw(5) << "╔";
    for (int j = 0; j < board_.get_rows()*2; j++)
    {
        cout << "=";
    }
    cout << "╗"<<endl;
    for (int j = 0; j < board_.get_rows(); j++) {
        if (a > 9)
            cout<< a++;
        else
            cout<< a++ << " ";
        for (int i = 0; i <= board_.get_cols()-65; i++){
            if (i==0) cout<< "║" << " ";
            if (board_.get_pCells()[j][i]->get_status() == "clear")
                cout << "°"<< " ";
            else if (board_.get_pCells()[j][i]->get_status() == "filled")
                cout << "█"<<" ";
            if (i==board_.get_pCells()[j].size()+1)
                cout<<"║";
        }
        cout << endl;
    }
    cout << setw(5) << "╚";
    for (int k = 0; k < board_.get_rows()*2; k++) {
        cout << "=";
    }
    cout << "╝";
    cout << endl;
}



string controller_t::place_fleet(model_t& model){ // recibe el primer statement y
    string str = "TOKEN=" + token_ + "\n";
    char cols;
    size_t rows;
    char orientacion;
    navy_t navy = navy_t(cols, rows, model, orientacion, board_ ,rows,cols); //no importan los primeros dos

    board_.add_fleet(make_shared<navy_t>(navy));

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

void controller_t::handshakeIn(text_t name) {
    string str = "HANDSHAKE=" + name;
    load_tokens(str);
}

void controller_t::execute() {

    bool hPassed = false;

    handshakeIn("BattleBot");
    statements_.push(save_tokens());
    while(!statements_.empty()){
        while( statements_.front().parameter != "WINNER" || statements_.front().parameter != "GAMEOVER") {
            cout << "El .out fue recibido c: \n";
            while(statements_.front().status == "REJECTED\r" && !hPassed) {
                handshakeIn("BattleBot");
                break;
            }
            while( statements_.front().action == "PLACEFEET" || ((statements_.front().parameter == "CONTINUE") && !hPassed)) {
                cout << "Entro a fase de construccion \n";
                if (!hPassed) {
                    set_board(statements_.front().scope);
                    cout << "Board inicializado con:\n";
                    cout << board_.get_rows() <<" rows\n";
                    cout << board_.get_cols() <<" cols\n";
                    set_token(statements_.front().token);
                    cout << "token: " << token_ <<"\n";
                }
                if (statements_.front().status == "REJECTED" && statements_.front().parameter == "OUTSIDE"){
//                    for (auto& cell: (board_.get_fleet().back())->get_layout()) {
//                        cell->set_status("clear");
//                    }
                    board_.pop_fleet();
                }
                hPassed = true;
                build( statements_.front());
                break;
            }
            while( statements_.front().action == "ATTACK" || statements_.front().parameter == "FULL" || modelsava.empty()) {
                string path;
                path += board_.get_path();
                path += "/out";
                if (statements_.front().parameter == "NO OPONENT") {

                    this_thread::sleep_until(chrono::system_clock::now() + chrono::seconds(4));
                }
                attack( statements_.front());

                break;
            }
            statements_.pop();
            statements_.push(save_tokens());
        }
    }
}

void controller_t::load_tokens(string& str) {
    ofstream file;
    string path;
    path += board_.get_path();
    if (path.find("first") != string::npos) {
        path += "/in/FirstPlayer";
    }
    else if (path.find("second") != string::npos) {
        path += "/in/SecondPlayer";
    }
    path += to_string(n);
    path += ".in";
    //cout << "se abrio: " << path << endl;
    file.open(path);
    file << str <<endl;
    file.close();
}

statement_t controller_t::save_tokens() {
    ifstream file;
    string path;

    path += board_.get_path();
    if (path.find("first") != string::npos){
        path += "/out/FirstPlayer";
    }
    else if (path.find("second") != string::npos) {
        path += "/out/SecondPlayer";
    }

    path += to_string(n);
    path +=".out";
    n++;

    while (!file.is_open()) {
        this_thread::sleep_until(chrono::system_clock::now() + chrono::seconds(1)); //El servidor no soporta el pusheo instantaneo de archivos
        file.open(path);
    }
    statement_t statement;
    string line;

    getline (file,line);
    if (line == "HANDSHAKE"){
        //cout << "entro handshake\n";
        statement.action = line;
        getline (file,line);

        int pos = line.find('=')+1;
        statement.status = line.substr(pos);
        getline (file,line);
        pos = line.find('=')+1;
        statement.token = line.substr(pos);
        getline (file,line);
        pos = line.find('=')+1;
        statement.scope = line.substr(pos);
        getline (file,line);
        pos = line.find('=')+1;
        statement.parameter = line.substr(pos);

        cout << "   action: " << statement.action << "\n";
        cout << "   status: " << statement.status << "\n";
        cout << "   token: " << statement.token << "\n";
        cout << "   scope: " << statement.scope << "\n";
        cout << "   parameter: " << statement.parameter << "\n";
    }
    else {
        //cout << "entro else\n";
        statement.action = line;

        getline (file,line);
        int pos = line.find('=')+1;
        statement.status = line.substr(pos);

        getline (file,line);
        pos = line.find('=')+1;
        statement.parameter = line.substr(pos);

        cout << "   action: " << statement.action << "\n";
        cout << "   status: " << statement.status << "\n";
        cout << "   parameter: " << statement.parameter << "\n";
    }

    file.close();

    //cout << "se borro: " << path << endl;
    filesystem::remove(path); //borra el .out
    return statement;
}



void controller_t::set_board(parameter_t scope) {
    auto cols = scope[0];
    auto rows = stoi(scope.substr(2));
    board_ = board_t(cols, rows);
}

void controller_t::build(const statement_t &item) {
    auto model = modelsava.back();
    if (modelsava.empty()){
        cout << "FLOTA COMPLETA" << endl;
        return;
    }
    if (find(modelsava.begin(),modelsava.end(),model)!=modelsava.end()){
        modelsava.erase(find(modelsava.begin(),modelsava.end(),model));
        cout << "Entrando a creacion de barco \n";
        auto str =  place_fleet(model);
        cout << "------------------------------------\n";
        cout << "TABLERO \n";
        print_board();
        load_tokens(str);

    }
    else{
        build(item);
    }
}

void controller_t::attack(const statement_t &item) {
    char letra = randint(65,board_.get_cols());
    string numero = to_string(randint(0,board_.get_rows()));
    string coordenada = letra + numero;
    //simplemente es random, implementar forma mas "inteligente"

    string str = "TOKEN=" + token_ + "\n";

    str += "ATTACK=" + coordenada;
    load_tokens(str);
}

void controller_t::set_token(const text_t& token) {
    token_ = token;
}

board_t controller_t::get_board() {
    return board_t();
}