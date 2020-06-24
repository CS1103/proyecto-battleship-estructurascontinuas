#include "cell_t.h"

cell_t::cell_t() {
    coordinates_ = {};
}

cell_t::cell_t(position_t x, position_t y) {
    coordinates_ = {x, y};
}

status_t cell_t::get_status() {
    return status_;
}

void cell_t::set_status(status_t& status) {
    status_ = status;
}
