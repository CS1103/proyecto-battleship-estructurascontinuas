#include "board_t.h"

board_t::board_t() {
    cols_ = 0;
    rows_ = 0;
}

board_t::board_t(letter_t cols, size_t rows) {
    cols_ = cols-1;
    rows_ = rows-1;
    size_t nCols = cols_ - 65;
    //cells_t cells;

    cells_.resize(rows);
    pCells_.resize(rows);

    for (int j = 0; j < cells_.size(); j++) {
        cells_[j].resize(nCols+1);
        pCells_[j].resize(nCols+1);
        for (int i = 0; i < cells_[j].size(); i++) {
            cells_[j][i] = cell_t(i, j);
            pCells_[j][i] = make_shared<cell_t>(cells_[j][i]);
        }
    }
}

pCells_t board_t::get_pCells() {
    return pCells_;
}



void board_t::add_fleet(shared_ptr<navy_t> navy) {
    pFleet_.push_back(navy);
}

void board_t::pop_fleet() {
    for (auto& i: pFleet_.back()->get_layout()){
        i->set_status("clear");
    }
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

bool board_t::is_valid(size_t row, size_t col) {
    cout << "tratando de entrar a la celda: " << char(col + 65) << "(" << col << ")" << "-" << row << endl;
    if (row < pCells_.size() && col < pCells_[0].size()) {
        if (pCells_[row][col]->get_status() == "clear") {
            return true;
        } else {
            cout << "celda no valida\n";
        }
    } else {
        cout << "celda no valida\n";
    }
    return false;
}


path_t board_t::get_path() {
    return path_;
}
