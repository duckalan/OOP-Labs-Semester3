#include <iostream>
#include <fstream>

#include "IntertownTicket.h"
#include "InternationalTicket.h"

void PolymorphismTest(const AirlineTicket& ticket)
{
    ticket.PrintInfo();
    std::cout << '\n';
}

int main()
{
    tm departureDate{};
    departureDate.tm_year = 2004;
    departureDate.tm_mon = 11;
    departureDate.tm_mday = 30;
    departureDate.tm_hour = 12;
    departureDate.tm_min = 30;

    tm arrivalDate{};
    arrivalDate.tm_year = 2004;
    arrivalDate.tm_mon = 11;
    arrivalDate.tm_mday = 30;
    arrivalDate.tm_hour = 23;
    arrivalDate.tm_min = 10;

    IntertownTicket t1(2227ull, 122ull, departureDate, arrivalDate, AirlineTicket::FareClass::Busines,
        2578, "Иванов И.И.", "Москва", "Владивосток", "Рога и копыта");

    InternationalTicket t2(235ull, 1435ull, departureDate, arrivalDate, AirlineTicket::FareClass::Economy,
        54645, "Иванов И.И.", "Москва", "Нью-Йорк", "Россия", "США", "Рога и копыта");

    PolymorphismTest(t1);
    PolymorphismTest(t2);
}