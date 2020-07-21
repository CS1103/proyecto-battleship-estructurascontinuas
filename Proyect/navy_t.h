#ifndef PROYECTO_NAVY_T_H
#define PROYECTO_NAVY_T_H

#include "common_types.h"
#include "cell_t.h"
#include "board_t.h"

using layout_t = vector<shared_ptr<cell_t>>;

using namespace std;

class board_t; // forward declaration

class navy_t {
private:
    location_t location_ = {};
    model_t model_; // (A)ircraft_Carrier, (B)attlecruiser, (S)ubmarine, (T)orpedo_boat
    orientation_t orientation_; // V, H
    layout_t layout_;
public:
    //Constructor
    navy_t(position_t x, position_t y, model_t model, orientation_t& orientation, board_t& board,size_t& row_, char& col_);

    //Getters
    layout_t get_layout();
    model_t get_model();

};


int randint(int a, int b);


#endif //PROYECTO_NAVY_T_H

