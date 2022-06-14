// Copyright 2022 qqq <polyakovdd@student.bmstu.ru>


#ifndef CODE_BUS_HPP
#define CODE_BUS_HPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Bus {
    std::string _number = "11111";
    std::string _driverInfo = "wqeeqwe";
    std::string _routeNumber = "q123";

public:
    Bus() = default;

    Bus(std::string number, std::string driver, std::string route) : _number(number), _driverInfo(driver),
                                                                     _routeNumber(route){};


    inline std::string GetNumber() {
        return _number;
    }

    inline std::string GetDriver() {
        return _driverInfo;
    }

    inline std::string GetRoute() {
        return _routeNumber;
    }

    friend std::ofstream &operator<<(std::ofstream &, Bus &);

    friend std::ifstream &operator>>(std::ifstream &, Bus &);

    friend std::istream &operator>>(std::istream &, Bus &);

};


#endif //CODE_BUS_HPP
