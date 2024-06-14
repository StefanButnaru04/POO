#include "Circuit.h"
#include "Car.h"
#include <iostream>
using namespace std;

bool Circuit::SortRaceTime(RaceTimes& st, RaceTimes& dr)
{
        if (dr.race_time > st.race_time) return true;
		return false;

}

Circuit::Circuit()
{
		length = 0;
		weather = Weather::Sunny;
		race_time = new RaceTimes[100];
		nr_cars = 0;	
}

void Circuit::SetLength(int length)
{
	this->length=length;
}

void Circuit::SetWeather(Weather weather)
{
	this->weather = weather;
}

void Circuit::AddCar(Car* car)
{
	race_time[nr_cars].car = car;
	race_time[nr_cars].race_time = 0;
	nr_cars++;

}


void Circuit::Sortare(RaceTimes v[], int n, bool ascendent)
{
	if (ascendent == 1)
	{
		int i;
		int var;
		if (ascendent == 0) var = 1;
		else var = -1;
		bool ok = 0;
		while (ok == 0)
		{
			ok = 1;
			for (i = 0; i < n - 1; i++)
				if (v[i].race_time * var > v[i + 1].race_time * var)
				{
					ok = 0;
					swap(v[i].race_time, v[i + 1].race_time);

				}

		}


	}


}


void Circuit::Race()
{
	int  i;
	double time, weather_speed, fuel_consumption, fuel_capacity, fuel_consumed;
	for (i = 0; i < nr_cars; i++)
	{
		weather_speed = race_time[i].car->average_speed[this->weather];
		fuel_consumption = race_time[i].car->fuel_consumption;
		fuel_capacity = race_time[i].car->fuel_capacity;
		time = (double)this->length / weather_speed;
		fuel_consumed = this->length / 100 * fuel_consumption;
		if (fuel_consumed > fuel_capacity) time = -1;
		this->race_time[i].race_time = time;
		Sortare(race_time, nr_cars, SortRaceTime);
	}

}

void Circuit::ShowFinalRanks()
{
	int i;
	for (i = nr_cars-1; i >=0; i--)
	{
		if (race_time[i].race_time != -1) 
		{
			cout << "Locul " <<nr_cars-i << " castigat de " << race_time[i].car->returnTypeofcar() << " timp " << race_time[i].race_time;
			cout << "\n";

		}
	}
}

void Circuit::ShowWhoDidNotFinish()
{
	int i;
	for (i = 0; i < nr_cars; i++)
	{
		if (race_time[i].race_time == -1)
			cout << race_time[i].car->returnTypeofcar() << "nu a terminat cursa" << "\n";

	}


}