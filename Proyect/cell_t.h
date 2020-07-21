#ifndef PROYECTO_CELL_T_H
#define PROYECTO_CELL_T_H

#include "common_types.h"

class cell_t {
private:
    coordinates_t coordinates_; //vector de posiciones = size_t
    status_t status_ = "clear";
public:
    //Constructores
    cell_t();
    cell_t(position_t x, position_t y);

    //Getter
    status_t get_status();

    //Setter
    void set_status(status_t status);
};




#endif //PROYECTO_CELL_T_H
