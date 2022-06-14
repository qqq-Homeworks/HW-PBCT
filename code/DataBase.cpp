// Copyright 2022 qqq <polyakovdd@student.bmstu.ru>


#include "DataBase.hpp"


void print(std::map<std::string, Bus> &buses) {
    for (auto &bus: buses) {
        std::cout << bus.second.GetNumber() << ' ' << bus.second.GetDriver() << ' ' << bus.second.GetRoute() << '\n';
    }
}

void print(std::vector<Bus> &buses) {
    for (auto &bus: buses) {
        std::cout << bus.GetNumber() << ' ' << bus.GetDriver() << ' ' << bus.GetRoute() << '\n';
    }
}

void SeedData(std::map<std::string, Bus> &park) {
    std::map<std::string, Bus> inPark = {std::make_pair("к181ко32", Bus("к181ко32", "Поляков_Д.Д.", "32А")),
                                         std::make_pair("л228ох222", Bus("л228ох222", "Журмилов_В.Д.", "11")),
                                         std::make_pair("н540ск32", Bus("н540ск32", "Поляков_Д.В.", "19Б")),
                                         std::make_pair("и264иу69", Bus("и264иу69", "Валова_С.В.", "3.14YES")),
                                         std::make_pair("о222чк01", Bus("о222чк01", "Скиба_Г.С.", "123")),
                                         std::make_pair("с013мм197", Bus("с013мм197", "Камушкин_П.Н.", "5")),
                                         std::make_pair("с105рф122", Bus("с105рф122", "Попов_С.Д.", "324Б")),
                                         std::make_pair("п233мп32", Bus("п233мп32", "Рябец_А.Д.", "32Б"))
    };
    park = inPark;

    std::ofstream outFilePark("InParkDatabase.db");
    std::ofstream outFileRoute("OnRouteDatabase.db");
    outFilePark.clear();
    outFileRoute.clear();
    outFileRoute << "0\n";
    outFileRoute.close();

    outFilePark << inPark.size() << '\n';
    for (auto busPair: inPark) {
        outFilePark << busPair.second.GetNumber() << ' ' << busPair.second.GetDriver() << ' '
                    << busPair.second.GetRoute() << '\n';
    }
    outFilePark.close();

    std::cout << "Данные обновлены\n";
}

void AddBus(std::map<std::string, Bus> &park) {
    std::cout << "Введите данные об автобусе через пробел (Номер, Инициалы водителя, Номер маршрута):\n";
    Bus tempBus;
    std::cin >> tempBus;
    park.insert(std::make_pair(tempBus.GetNumber(), tempBus));
    std::cout << "Автобус добавлен в парк\n";
}

void DeleteBus(std::map<std::string, Bus> &park) {
    print(park);
    std::cout << "Введите номер автобуса, который желаете удалить из парка:\n";
    std::string tempNumber;

    bool entering = true;
    while (entering) {
        std::cin >> tempNumber;
        if (park.find(tempNumber) != park.end()) {

            park.erase(tempNumber);
            std::cout << "Автобус удалён\n";
            entering = false;
        } else {
            std::cout << "Автобуса с таким номером не найдено, повторите ввод:\n";
        }
    }
}

void OutBus(std::map<std::string, Bus> &park, std::map<std::string, Bus> &route) {
    if (park.empty()) {
        std::cout << "Сейчас в парке нет автобусов\n";
        return;
    }
    std::cout << "Список автобусов в парке:\n";
    print(park);
    std::cout << "Введите номер автобуса, который желаете вывести на линию:\n";
    std::string number;
    bool entering = true;
    while (entering) {
        std::cin >> number;
        if (park.find(number) != park.end()) {
            entering = false;
            route.insert(std::make_pair(number, park[number]));
            park.erase(number);
            std::cout << "Автобус успешно выведен на линию\n";
        } else {
            std::cout << "Автобуса с таким номером нет, введите снова:\n";
        }
    }
}

void EnterBus(std::map<std::string, Bus> &park, std::map<std::string, Bus> &route) {
    if (route.empty()) {
        std::cout << "Сейчас на маршруте нет автобусов\n";
        return;
    }
    std::cout << "Список автобусов на маршруте:\n";
    print(route);
    std::cout << "Введите номер автобуса, который желаете снять с линии:\n";
    std::string number;
    bool entering = true;
    while (entering) {
        std::cin >> number;
        if (route.find(number) != route.end()) {
            entering = false;
            park.insert(std::make_pair(number, route[number]));
            route.erase(number);
            std::cout << "Автобус успешно снят с линии\n";
        } else {
            std::cout << "Автобуса с таким номером нет, введите снова:\n";
        }
    }
}

void PrintBuses(std::map<std::string, Bus> &park, std::map<std::string, Bus> &route, bool key) {
    std::vector<Bus> prikolPark;
    for (auto bus: park) {
        prikolPark.push_back(bus.second);
    }
    std::vector<Bus> prikolRoute;
    for (auto bus: route) {
        prikolRoute.push_back(bus.second);
    }
    if (!key) {
        std::sort(prikolPark.begin(), prikolPark.end(), [](Bus &bus1, Bus &bus2) {
            return bus1.GetNumber() > bus2.GetNumber();
        });
        std::sort(prikolRoute.begin(), prikolRoute.end(), [](Bus &bus1, Bus &bus2) {
            return bus1.GetNumber() > bus2.GetNumber();
        });
    } else {
        std::sort(prikolPark.begin(), prikolPark.end(), [](Bus &bus1, Bus &bus2) {
            return bus1.GetRoute() > bus2.GetRoute();
        });
        std::sort(prikolRoute.begin(), prikolRoute.end(), [](Bus &bus1, Bus &bus2) {
            return bus1.GetRoute() > bus2.GetRoute();
        });
    }
    std::cout << "Список автобусов в парке:\n";
    print(prikolPark);
    std::cout << "Список автобусов на линии:\n";
    print(prikolRoute);

}

void updateDB(std::map<std::string, Bus> &park, std::map<std::string, Bus> &route) {
    std::ofstream outFilePark("InParkDatabase.db");
    std::ofstream outFileRoute("OnRouteDatabase.db");
    outFilePark.clear();
    outFileRoute.clear();


    outFilePark << park.size() << '\n';
    for (auto busPair: park) {
        outFilePark << busPair.first << ' ' << busPair.second.GetDriver() << ' ' << busPair.second.GetRoute() << '\n';
    }
    if (park.size() == 0) {
        outFilePark << 0;
    }
    outFilePark.close();

    outFileRoute << route.size() << '\n';
    for (auto busPair: route) {
        outFileRoute << busPair.first << ' ' << busPair.second.GetDriver() << ' ' << busPair.second.GetRoute()
                     << '\n';
    }
    if (route.size() == 0) {
        outFileRoute << 0;
    }
    outFileRoute.close();
}

void fillData(std::map<std::string, Bus> &park, std::map<std::string, Bus> &route) {
    std::ifstream inFilePark("InParkDatabase.db");
    std::ifstream inFileRoute("OnRouteDatabase.db");
    size_t count;
    inFilePark >> count;
    Bus tempBus;
    for (size_t i = 0; i < count; ++i) {
        inFilePark >> tempBus;
        park.insert(std::make_pair(tempBus.GetNumber(), tempBus));
    }
    inFilePark.close();

    inFileRoute >> count;
    for (size_t i = 0; i < count; ++i) {
        inFileRoute >> tempBus;
        route.insert(std::make_pair(tempBus.GetNumber(), tempBus));
    }
    inFileRoute.close();
}