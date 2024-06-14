#pragma once
#include "Car.h"
#include "Weather.h"
class RangeRover:public Car
{
 public:
  RangeRover()
  {
	  typeofcar = "RangeRover";
	  fuel_capacity = 100;
	  fuel_consumption = 20;
	  average_speed[Weather::Rain] = 110.7;
	  average_speed[Weather::Sunny] = 200;
	  average_speed[Weather::Snow] = 105;
  
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

