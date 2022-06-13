// Copyright 2022 qqq <polyakovdd@student.bmstu.ru>


#include "Bus.hpp"

std::ifstream &operator>>(std::ifstream &inf, Bus &bus) {
    inf >> bus._number >> bus._driverInfo >> bus._routeNumber;
    return inf;
}
