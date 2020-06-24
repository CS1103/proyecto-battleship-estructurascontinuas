//
// Created by Acer on 21/06/2020.
//

#ifndef PROYECTO_BOARD_T_H
#define PROYECTO_BOARD_T_H

#include "common_types.h"
#include "cell_t.h"
#include "navy_t.h"

class navy_t;

using cells_t = vector<vector<cell_t>>;
using pCells_t = vector<vector<cell_t*>>;
using fleet_t = vector<navy_t>;
using pFleet_t = vector<navy_t*>;

using namespace std;

class board_t {
private:
    letter_t cols_;
    size_t rows_;
    cells_t cells_;
    pCells_t pCells_;
    fleet_t fleet_ = {};
    pFleet_t pFleet_ = {};
public:
    board_t();
    board_t(letter_t cols, size_t rows);
    pCells_t get_pCells();
    void add_fleet(navy_t& navy);
    void print() const;
    letter_t get_cols();
    size_t get_rows();
    bool isvalid(size_t row, size_t col);
};


#endif //PROYECTO_BOARD_T_H