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
    cout << "------------------------------------\n";
    cout << "Creando barco\n";
    vector<char> orientaciones = {'H', 'V'};
    orientation = orientaciones[randint(0, 1)];
    size_t colt = randint(65, board.get_cols()) - 65;
    col_ = char(colt+65);
    row_ = randint(1, board.get_rows());
    cout << "Posible tipo:" << model << endl;
    cout << "Posible orientacion:" << orientation << endl;
    cout << "Posible posicion:" << col_ << "-" << row_ <<endl;
    size_t rowt = row_ -1;
    layout_t layout;
    status_t newStatus = "filled";
    status_t badStatus = "clear";
    vector<model_t> models = {'T', 'S', 'B', 'A'};
    switch(orientation){
        case 'H':
            for (int i = 0; i <= distance(models.begin(), find(models.begin(), models.end(), model)); i++) {
                if(!board.isvalid(rowt,colt+i)){
                    if (i > 0) {
                        for (int n = i - 1;n >= 0; n--){
                            layout.pop_back();

                            board.get_pCells()[rowt][colt+n]->set_status(badStatus);
                        }
                    }
                    orientation = orientaciones[randint(0, 1)];
                    cout << "fallo creacion\n";
                    return calculate_layout(location,orientation,model,board,row_, col_);
                }
                else {
                    layout.push_back(board.get_pCells()[rowt][colt+i]);
                    board.get_pCells()[rowt][colt+i]->set_status(newStatus);
                }
            }
            break;
        case 'V':
            for (int j = 0; j <= distance(models.begin(), find(models.begin(), models.end(), model)); j++) {

                if(!board.isvalid(rowt+j,colt)){
                    if (j > 0) {
                        for (int n = j - 1;n >= 0; n--){
                            layout.pop_back();
                            board.get_pCells()[rowt+n][colt]->set_status(badStatus);
                        }
                    }
                    orientation = orientaciones[randint(0, 1)];
                    cout << "fallo creacion\n";
                    return calculate_layout(location,orientation,model,board,row_, col_);
                }
                else {
                    layout.push_back(board.get_pCells()[rowt+j][colt]);
                    board.get_pCells()[rowt+j][colt]->set_status(newStatus);
                }
            }
            break;
        default:
            cout << "Not valid oritenation\n";
            break;
    }
    cout << "CREADO CON EXITO\n";
    cout << "------------------------------------\n";
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

