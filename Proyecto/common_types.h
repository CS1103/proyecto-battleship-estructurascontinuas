//
// Created by Acer on 21/06/2020.
//

#ifndef PROYECTO_COMMON_TYPES_H
#define PROYECTO_COMMON_TYPES_H

#include <map>
#include <vector>
#include <queue>
#include <string>
#include <string_view>
#include <memory>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <filesystem>
#include <numeric>
#include <random>
#include <sstream>
#include <future>
#include <optional>
#include <regex>
#include <utility>

using namespace std;

using position_t = size_t;
using status_t = string;
using model_t = char;
using orientation_t = char;
using letter_t = char;

struct location_t {
    position_t x;
    position_t y;
};

using coordinates_t = vector<position_t>;
#endif //PROYECTO_COMMON_TYPES_H
