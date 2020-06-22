//
// Created by Acer on 21/06/2020.
//

#ifndef PROYECTO_CONTROLLER_T_H
#define PROYECTO_CONTROLLER_T_H

#include "board_t.h"
#include "common_types.h"


struct statement_t {
    string action;
    string token;
    string status;
    string parameter;
};

using statements_list = queue<statement_t>;

class controller_t {
private:
    text_t name_;
    text_t token_;
    board_t board_;
    statements_list statements_;
    void handshakeIn(const string& name);
    //void start(const statement_t& item);
    void build(const statement_t& item);
    void attack(const statement_t& item);
public:
    string placeFleet(model_t& model);
    explicit controller_t(text_t& name);
    void setBoard(letter_t cols, size_t rows);
    void execute();
    void load_tokens();
    void save_tokens();
};


#endif //PROYECTO_CONTROLLER_T_H
