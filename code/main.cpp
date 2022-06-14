#include <iostream>
#include <vector>
#include "DataBase.hpp"

void PrintMenu() {
    std::vector<std::string> menuHeaders = {"Перезаполнить список маршрутов",
                                            "Добавить автобус в парк",
                                            "Удалить автобус из парка",
                                            "Выезд автобуса на маршрут",
                                            "Въезд автобуса в парк",
                                            "Список автобусов по номеру",
                                            "Список автобусов по маршруту",
                                            "Выход"};
    std::cout << '\n';
    for (size_t i = 0; i < menuHeaders.size(); ++i) {
        std::cout << i + 1 << '.' << menuHeaders[i] << '\n';
    }
    std::cout << "Введите необходимый вам пункт меню:\n";
}

enum MenuPouints {
    FEEL_BUSES = 1,
    ADD_BUS,
    DELETE_BUS,
    OUT_BUS,
    ENTER_BUS,
    BUSES_BY_NUMBER,
    BUSES_BY_ROUTE,
    EXIT
};
enum SortedBy {
    NUMBERS,
    ROUTES
};

int main() {
    bool contqqq = true;
    std::map<std::string, Bus> onRoute, inPark;
    fillData(inPark, onRoute);
    while (contqqq) {
        PrintMenu();
        size_t menuPoint;
        std::cin >> menuPoint;
        switch (menuPoint) {
            case FEEL_BUSES:
                SeedData(inPark);
                onRoute.clear();
                break;
            case ADD_BUS:
                AddBus(inPark);
                break;
            case DELETE_BUS:
                DeleteBus(inPark);
                break;
            case OUT_BUS:
                OutBus(inPark, onRoute);
                break;
            case ENTER_BUS:
                EnterBus(inPark, onRoute);
                break;
            case BUSES_BY_NUMBER:
                PrintBuses(inPark, onRoute, NUMBERS);
                break;
            case BUSES_BY_ROUTE:
                PrintBuses(inPark, onRoute, ROUTES);
                break;
            case EXIT:
                updateDB(inPark, onRoute);
                contqqq = false;
                break;
            default:
                break;
        }
    }
    updateDB(inPark, onRoute);
    return 0;
}
