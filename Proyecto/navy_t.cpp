//
// Created by Acer on 21/06/2020.
//

#include "navy_t.h"
//innecesario, pero me da medio llamar al h

int randint(int a, int b){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(a,b);
    return dist6(rng);
}

layout_t calculate_layout(location_t location, orientation_t& orientation, model_t model, board_t& board, size_t& row_, char& col_) {
    vector<char> orientaciones = {'H', 'V'};
    orientation = orientaciones[randint(0, 1)];
    size_t colt = randint(65, board.get_cols()) - 65;
    col_ = char(colt+65);
    row_ = randint(1, board.get_rows());
    size_t rowt = row_ -1;
    layout_t layout;
    status_t newStatus = "filled";
    status_t badStatus = "clear";
    switch(orientation){
        case 'H':
            switch(model) { //se podria resumir mejor cambiando la condicion?
                case 'A':
                    for (int i = 0; i < 4; i++) {
                        if (!board.isvalid(rowt+i,colt)){
                            if (i>0){
                                for (int j=i-1;j>=0;j--){
                                    layout.pop_back();
                                    board.get_pCells()[colt][rowt+j]->set_status(badStatus);
                                }
                            }
                            orientation = orientaciones[randint(0, 1)];
                            return calculate_layout(location,orientation,model,board,row_, col_);
                        }
                        else{
                            layout.push_back(board.get_pCells()[colt][rowt+i]);
                            board.get_pCells()[colt][rowt+i]->set_status(newStatus);
                        }
                    }
                    break;
                case 'B':
                    for (int i = 0; i < 3; i++) {
                        if (!board.isvalid(rowt+i,colt)){
                            if (i>0){
                                for (int j=i-1;j>=0;j--){
                                    layout.pop_back();
                                    board.get_pCells()[colt][rowt+j]->set_status(badStatus);
                                }
                            }
                            orientation = orientaciones[randint(0, 1)];
                            return calculate_layout(location,orientation,model,board,row_, col_);
                        }
                        else{
                            layout.push_back(board.get_pCells()[colt][rowt+i]);
                            board.get_pCells()[colt][rowt+i]->set_status(newStatus);
                        }
                    }
                    break;
                case 'S':
                    for (int i = 0; i < 2; i++) {
                        if (!board.isvalid(rowt+i,colt)){
                            if (i>0){
                                for (int j=i-1;j>=0;j--){
                                    layout.pop_back();
                                    board.get_pCells()[colt][rowt+j]->set_status(badStatus);
                                }
                            }
                            orientation = orientaciones[randint(0, 1)];
                            return calculate_layout(location,orientation,model,board,row_, col_);
                        }
                        else{
                            layout.push_back(board.get_pCells()[colt][rowt+i]);
                            board.get_pCells()[colt][rowt+i]->set_status(newStatus);
                        }
                    }
                    break;
                case 'T':
                    if (!board.isvalid(rowt,colt)){
                        orientation = orientaciones[randint(0, 1)];
                        return calculate_layout(location,orientation,model,board,row_, col_);
                    }
                    else{
                        layout.push_back(board.get_pCells()[colt][rowt]);
                        board.get_pCells()[colt][rowt]->set_status(newStatus);
                        break;
                    }
                default:
                    cout << "Not valid model\n";
                    break;
            }
            break;
        case 'V':
            switch(model) {
                case 'A':
                    for (int i = 0; i < 4; i++) {
                        if (!board.isvalid(rowt,colt+i)){
                            if (i>0){
                                for (int j=i-1;j>=0;j--){
                                    layout.pop_back();
                                    board.get_pCells()[colt+j][rowt]->set_status(badStatus);
                                }
                            }
                            orientation = orientaciones[randint(0, 1)];
                            return calculate_layout(location,orientation,model,board,row_, col_);
                        }
                        else{
                            layout.push_back(board.get_pCells()[colt+i][rowt]);
                            board.get_pCells()[colt+i][rowt]->set_status(newStatus);
                        }
                    }
                    break;
                case 'B':
                    for (int i = 0; i < 3; i++) {
                        if (!board.isvalid(rowt,colt+i)){
                            if (i>0){
                                for (int j=i-1;j>=0;j--){
                                    layout.pop_back();
                                    board.get_pCells()[colt+j][rowt]->set_status(badStatus);
                                }
                            }
                            orientation = orientaciones[randint(0, 1)];
                            return calculate_layout(location,orientation,model,board,row_, col_);
                        }
                        else{
                            layout.push_back(board.get_pCells()[colt+i][rowt]);
                            board.get_pCells()[colt+i][rowt]->set_status(newStatus);
                        }
                    }
                    break;
                case 'S':
                    for (int i = 0; i < 2; i++) {
                        if (!board.isvalid(rowt,colt+i)){
                            if (i>0){
                                for (int j=i-1;j>=0;j--){
                                    layout.pop_back();
                                    board.get_pCells()[colt+j][rowt]->set_status(badStatus);
                                }
                            }
                            orientation = orientaciones[randint(0, 1)];
                            return calculate_layout(location,orientation,model,board,row_, col_);
                        }
                        else{
                            layout.push_back(board.get_pCells()[colt+i][rowt]);
                            board.get_pCells()[colt+i][rowt]->set_status(newStatus);
                        }
                    }
                    break;
                case 'T':
                    if (!board.isvalid(rowt,colt)){
                        orientation = orientaciones[randint(0, 1)];
                        return calculate_layout(location,orientation,model,board,row_, col_);
                    }
                    else{
                        layout.push_back(board.get_pCells()[colt][rowt]);
                        board.get_pCells()[colt][rowt]->set_status(newStatus);
                        break;
                    }
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

navy_t::navy_t(position_t x, position_t y, model_t model, orientation_t& orientation, board_t& board, size_t& row_, char& col_) {
    model_ = model; //no se randomea cancelaria varias cosas si lo hace
    layout_ = calculate_layout(location_, orientation, model_, board,row_,col_);
    location_.x = row_;
    location_.y = col_-65;
    orientation_ = orientation; //los tres se randomean por eso se ponen despues del calculate layout - x e y son inservibles porque son estaticos borrar
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

