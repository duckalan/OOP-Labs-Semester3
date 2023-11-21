#pragma once
#include "AirlineTicket.h"
#include <iostream>
#include <string.h>

class InternationalTicket : public AirlineTicket
{
private:
	// Страна вылета
	char* departureCountry_;

	// Страна прилёта
	char* arrivalCountry_;

public:
	InternationalTicket(size_t ticketId, size_t flightId, tm departureTime, tm arrivalTime,
		FareClass fareClass, uint64_t price, const char* passengerName,
		const char* departureTown, const char* arrivalTown, 
		const char* departureCountry, const char* arrivalCountry, const char* issuingAirline)

		: AirlineTicket(ticketId, flightId, departureTime, arrivalTime,
			fareClass, price, passengerName, departureTown, arrivalTown, issuingAirline)
	{
		departureCountry_ = new char[strlen(departureCountry) + 1];
		strcpy(departureCountry_, departureCountry);

		arrivalCountry_ = new char[strlen(arrivalCountry) + 1];
		strcpy(arrivalCountry_, arrivalCountry);
	}

	~InternationalTicket()
	{
		delete[] departureCountry_;
		delete[] arrivalCountry_;
	}

	void PrintInfo() const
	{
		std::cout
			<< "Международный билет №" << ticketId_ << ", полёт №" << flightId_ << ", класс билета " << (char)fareClass_ << '\n'
			<< "Дата вылета: " << departureTime_.tm_hour << ":" << departureTime_.tm_min << " " << departureTime_.tm_mday << '.' << (departureTime_.tm_mon + 1) << '.' << departureTime_.tm_year << '\n'
			<< "Дата прилёта: " << arrivalTime_.tm_hour << ":" << arrivalTime_.tm_min << " " << arrivalTime_.tm_mday << '.' << (arrivalTime_.tm_mon + 1) << '.' << arrivalTime_.tm_year << '\n'
			<< "Имя пассажира: " << passengerName_ << '\n'
			<< "Город вылета/прилёта: " << departureTown_ << '/' << arrivalTown_ << ". Страна вылета/прилёта: " << departureCountry_ << '/' << arrivalCountry_ << '\n'
			<< "Авиакомпания-перевозчик: " << issuingAirline_ << ". Цена: " << price_ << '\n';
	}
};

