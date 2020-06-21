//
// Created by Acer on 21/06/2020.
//

#ifndef PROYECTO_BOARD_T_H
#define PROYECTO_BOARD_T_H

#include "common_types.h"
#include "cell_t.h"
#include "navy_t.h"

using cells_t = vector<vector<cell_t>>;
using pCells_t = vector<vector<cell_t*>>;

using namespace std;

class board_t {
private:
    letter_t cols_;
    size_t rows_;
    cells_t cells_;
    pCells_t pCells_;
public:
    board_t(letter_t cols, size_t rows);
    pCells_t get_pCells();
    void print() const;
};


#endif //PROYECTO_BOARD_T_H
