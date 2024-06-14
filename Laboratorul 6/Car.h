#pragma once
class Car
{
public:
	double fuel_capacity;
	double fuel_consumption;
	double average_speed[3];

	const char* typeofcar;

	virtual const char* returnTypeofcar() = 0;
	virtual void SetTypeofcar(const char* typeofcar) = 0;


};

