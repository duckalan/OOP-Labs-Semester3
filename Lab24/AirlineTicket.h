#pragma once

#include <cstdint>
#include <ctime>

class AirlineTicket
{
public:
	// Класс авиационного билета
	enum class FareClass : char
	{
		// Эконом-класс
		Economy = 'E',

		// Эконом-премиум класс
		PremiumEconomy = 'W',

		// Бизнес-класс
		Busines = 'J',

		// Первый класс
		First = 'F'
	};

	virtual void PrintInfo() const = 0;
protected:

	size_t ticketId_;

	// Номер полёта
	size_t flightId_;

	// Дата и время вылета
	tm departureTime_;

	// Дата и время прибытия
	tm arrivalTime_;

	FareClass fareClass_;

	uint64_t price_;

	char* passengerName_;

	// Город вылета
	char* departureTown_;

	// Город прилёта
	char* arrivalTown_;

	// Название авиакомпании, самолёт которой выполняет полёт
	char* issuingAirline_;

	AirlineTicket(size_t ticketId, size_t flightId, tm departureTime, tm arrivalTime,
		FareClass fareClass, uint64_t price, const char* passengerName,
		const char* departureTown, const char* arrivalTown, const char* issuingAirline)
	{
		ticketId_ = ticketId;
		flightId_ = flightId;
		departureTime_ = departureTime;
		arrivalTime_ = arrivalTime;
		fareClass_ = fareClass;
		price_ = price;
		
		passengerName_ = new char[strlen(passengerName) + 1];
		strcpy(passengerName_, passengerName);

		departureTown_ = new char[strlen(departureTown) + 1];
		strcpy(departureTown_, departureTown);

		arrivalTown_ = new char[strlen(arrivalTown) + 1];
		strcpy(arrivalTown_, arrivalTown);

		issuingAirline_ = new char[strlen(issuingAirline) + 1];
		strcpy(issuingAirline_, issuingAirline);
	}

	virtual ~AirlineTicket()
	{
		delete[] passengerName_;
		delete[] departureTown_;
		delete[] arrivalTown_;
		delete[] issuingAirline_;
	}
};

