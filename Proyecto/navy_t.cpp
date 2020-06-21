//
// Created by Acer on 21/06/2020.
//

#include "navy_t.h"


layout_t calculate_layout(location_t location, orientation_t orientation, model_t model, board_t& board) {
    layout_t layout;
    status_t newStatus = "filled";
    switch(orientation){
        case 'H':
            switch(model) { //se podria resumir mejor cambiando la condicion?
                case 'A':
                    for (int i = 0; i < 4; i++) {
                        layout.push_back(board.get_pCells()[location.y][location.x+i]);
                        board.get_pCells()[location.y][location.x+i]->set_status(newStatus);
                    }
                    break;
                case 'B':
                    for (int i = 0; i < 3; i++) {
                        layout.push_back(board.get_pCells()[location.y][location.x+i]);
                        board.get_pCells()[location.y][location.x+i]->set_status(newStatus);
                    }
                    break;
                case 'S':
                    for (int i = 0; i < 2; i++) {
                        layout.push_back(board.get_pCells()[location.y][location.x+i]);
                        board.get_pCells()[location.y][location.x+i]->set_status(newStatus);
                    }
                    break;
                case 'T':
                    layout.push_back(board.get_pCells()[location.y][location.x]);
                    board.get_pCells()[location.y][location.x]->set_status(newStatus);
                    break;
                default:
                    cout << "Not valid model\n";
                    break;
            }
            break;
        case 'V':
            switch(model) {
                case 'A':
                    for (int i = 0; i < 4; i++) {
                        layout.push_back(board.get_pCells()[location.y+i][location.x]);
                        board.get_pCells()[location.y+i][location.x]->set_status(newStatus);
                    }
                    break;
                case 'B':
                    for (int i = 0; i < 3; i++) {
                        layout.push_back(board.get_pCells()[location.y+i][location.x]);
                        board.get_pCells()[location.y+i][location.x]->set_status(newStatus);
                    }
                    break;
                case 'S':
                    for (int i = 0; i < 2; i++) {
                        layout.push_back(board.get_pCells()[location.y+i][location.x]);
                        board.get_pCells()[location.y+i][location.x]->set_status(newStatus);
                    }
                    break;
                case 'T':
                    layout.push_back(board.get_pCells()[location.y][location.x]);
                    board.get_pCells()[location.y][location.x]->set_status(newStatus);
                    break;
                default:
                    cout << "Not valid model\n";
                    break;
            }
            break;
        default:
            cout << "Not valid oritenation\n";
            break;
    }
    return layout;
}

navy_t::navy_t(position_t x, position_t y, model_t model, orientation_t orientation, board_t& board) {
    location_.x = x;
    location_.y = y;
    model_ = model;
    orientation_ = orientation;
    layout_ = calculate_layout(location_, orientation_, model_, board);
}

status_t navy_t::get_status() {
    return status_;
}

void navy_t::set_status(status_t& status) {
    status_ = status;
}

layout_t navy_t::get_layout(){
    return layout_;
}

