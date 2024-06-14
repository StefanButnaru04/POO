#pragma once
#include "Weather.h"
#include "Car.h"
class Seat:public Car
{
public:
	Seat()
	{
		typeofcar = "Seat";
		fuel_capacity = 60;
		fuel_consumption = 9;
		average_speed[Weather::Rain] = 95;
		average_speed[Weather::Sunny] = 115.9;
		average_speed[Weather::Snow] = 76;

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

