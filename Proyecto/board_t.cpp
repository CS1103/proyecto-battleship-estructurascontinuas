//
// Created by Acer on 21/06/2020.
//

#include "board_t.h"

board_t::board_t() {
    cols_ = 0;
    rows_ = 0;
}

board_t::board_t(letter_t cols, size_t rows) {
    cols_ = cols;
    rows_ = rows;
    size_t nCols = cols_ - 65;
    //cells_t cells;

    cells_.resize(rows);
    pCells_.resize(rows);

    for (int j = 0; j < cells_.size(); j++) {
        cells_[j].resize(nCols);
        pCells_[j].resize(nCols);
        for (int i = 0; i < cells_[j].size(); i++) {
            cells_[j][i] = cell_t(i, j);
            pCells_[j][i] = &cells_[j][i];
        }
    }
}

pCells_t board_t::get_pCells() {
    return pCells_;
}

void board_t::print() const {
    for (int j = 0; j < cells_.size(); j++) {
        for (int i = 0; i < cells_[j].size(); i++){
            if (pCells_[j][i]->get_status() == "clear")
                cout << "...";
            else if (pCells_[j][i]->get_status() == "filled")
                cout << "[ ]";
        }
        cout << endl;
    }
}

void board_t::add_fleet(navy_t& navy) {
    fleet_.push_back(navy);
    pFleet_.push_back(&navy);
}

letter_t board_t::get_cols() {
    return cols_;
}

size_t board_t::get_rows() {
    return rows_;
}

bool board_t::isvalid(size_t row, size_t col){
    if (row<= rows_ && col <= cols_){
        if (pCells_[col][row]->get_status()=="clear"){
            return true;
        }
    }
    return false;
}
