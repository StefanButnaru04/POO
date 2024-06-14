#pragma once
#include "Weather.h"
#include "Car.h"
#include "Car.h"
class Fiat:public Car
{
public:

	Fiat()
	{
		typeofcar = "Fiat";
		fuel_capacity = 50;
		fuel_consumption = 5;
		average_speed[Weather::Rain] = 80;
		average_speed[Weather::Sunny] = 120.6;
		average_speed[Weather::Snow] = 60;

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

