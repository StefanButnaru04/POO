#pragma once
#include "Weather.h"
#include "Car.h"

class Circuit
{ 
	int length;
	Weather weather;
	struct RaceTimes
	{
		Car* car;
		double race_time;
	};
	RaceTimes* race_time;
	int nr_cars;
	static bool SortRaceTime(RaceTimes& st, RaceTimes& dr);


public:
	Circuit();
	void SetLength(int length);
	void SetWeather(Weather weather);
	void AddCar(Car* car);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
	void Sortare(RaceTimes v[],int n,bool ascendent);

};

