#pragma once
#include "Weather.h"
#include "Car.h"
class Volvo: public Car
{
public:

	Volvo()
	{
		typeofcar = "Volvo";
		fuel_capacity = 70;
		fuel_consumption = 15;
		average_speed[Weather::Rain] = 105;
		average_speed[Weather::Sunny] = 160.5;
		average_speed[Weather::Snow] = 90;

	}
	const char* returnTypeofcar()
	{
		return this->typeofcar;

	}
	void SetTypeofcar(const char* typeofcar)
	{
		this->typeofcar = typeofcar;

	}
};

