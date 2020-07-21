#ifndef PROYECTO_CONTROLLER_T_H
#define PROYECTO_CONTROLLER_T_H

#include "board_t.h"
#include "common_types.h"


struct statement_t {
    text_t action;
    text_t token;
    text_t scope;
    text_t status;
    parameter_t parameter;
};

using statements_list = queue<statement_t>;

class controller_t {
private:
    text_t name_;
    text_t token_;
    board_t board_;
    statements_list statements_;
    void handshakeIn(text_t name);
    void build(const statement_t& item);
    void attack(const statement_t& item);
public:
    //Constructor
    controller_t(text_t name);
    
    //Setters
    void set_board(parameter_t scope);
    void set_token(const text_t& token);

    //Getters
    board_t get_board();

    //Funciones
    string place_fleet(model_t& model);
    void execute();
    void print_board();

    //Manejo de archivos
    void load_tokens(string& str);
    statement_t save_tokens();
};


#endif //PROYECTO_CONTROLLER_T_H
