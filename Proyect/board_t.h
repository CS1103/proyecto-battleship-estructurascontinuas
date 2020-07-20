#ifndef PROYECTO_BOARD_T_H
#define PROYECTO_BOARD_T_H

#include "common_types.h"
#include "cell_t.h"
#include "navy_t.h"

class navy_t;

using cells_t = vector<vector<cell_t>>;
using pCells_t = vector<vector<shared_ptr<cell_t>>>;
using pFleet_t = vector<shared_ptr<navy_t>>;

using namespace std;

class board_t {
private:
    path_t path_ = filesystem::current_path();
    letter_t cols_;
    size_t rows_;
    cells_t cells_;
    pCells_t pCells_;
    pFleet_t pFleet_ = {};
public:
    board_t();
    board_t(letter_t cols, size_t rows);
    pCells_t get_pCells();
    void add_fleet(shared_ptr<navy_t> navy);
    void pop_fleet(); // Borra el ultimo fleet
    pFleet_t get_fleet();
    letter_t get_cols();
    size_t get_rows();
    path_t get_path();
    bool isvalid(size_t row, size_t col);
};


#endif //PROYECTO_BOARD_T_H
