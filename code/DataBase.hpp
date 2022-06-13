// Copyright 2022 qqq <polyakovdd@student.bmstu.ru>


#ifndef CODE_DATABASE_HPP
#define CODE_DATABASE_HPP

#include <fstream>
#include <map>
#include <algorithm>
#include "Bus.hpp"

void SeedData(std::map<std::string, Bus> &);

void OutBus(std::map<std::string, Bus> &, std::map<std::string, Bus> &);

void EnterBus(std::map<std::string, Bus> &, std::map<std::string, Bus> &);

void PrintBuses(std::map<std::string, Bus> &, std::map<std::string, Bus> &, bool);

void updateDB(std::map<std::string, Bus> &, std::map<std::string, Bus> &);

void fillData(std::map<std::string, Bus> &, std::map<std::string, Bus> &);



#endif //CODE_DATABASE_HPP
