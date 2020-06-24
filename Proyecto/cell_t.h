//
// Created by Acer on 21/06/2020.
//

#ifndef PROYECTO_CELL_T_H
#define PROYECTO_CELL_T_H

#include "common_types.h"

class cell_t {
private:
    coordinates_t coordinates_; //vector de posiciones = size_t
    status_t status_ = "clear";
public:
    cell_t();
    cell_t(position_t x, position_t y);
    status_t get_status();
    void set_status(status_t& status);

};




#endif //PROYECTO_CELL_T_H
