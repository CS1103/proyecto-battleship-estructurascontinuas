//
// Created by Acer on 21/06/2020.
//

#include "board_t.h"

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
