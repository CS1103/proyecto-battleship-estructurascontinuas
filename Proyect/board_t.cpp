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
        cells_[j].resize(nCols+1);
        pCells_[j].resize(nCols+1);
        for (int i = 0; i < cells_[j].size(); i++) {
            cells_[j][i] = cell_t(i, j);
            pCells_[j][i] = &cells_[j][i];
        }
    }
}

pCells_t board_t::get_pCells() {
    return pCells_;
}



void board_t::add_fleet(navy_t& navy) {
    pFleet_.push_back(&navy);
}

void board_t::pop_fleet() {
    pFleet_.pop_back();
}

pFleet_t board_t::get_fleet(){
    return pFleet_;
}

letter_t board_t::get_cols() {
    return cols_;
}

size_t board_t::get_rows() {
    return rows_;
}

bool board_t::isvalid(size_t row, size_t col) {
    cout << "tratando de entrar a la celda: " << char(col + 65) << "(" << (col) << ")" << "-" << row << endl;
    //cout << pCells_[row-1][col]->get_status();
    if (row < rows_ && col < cols_ - 2) {
        //pCells_[row-1][col]->get_status();
        if (pCells_[row][col]->get_status() == "clear") {
            return true;
        } else {
            cout << "algo falla";
        }
    } else {
        cout << "algo falla";
    }
    return false;
}

path_t board_t::get_path() {
    return path_;
}
