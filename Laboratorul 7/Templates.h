#pragma once
#include <iostream>
using namespace std;

template<typename T>
int compare(T val1,T val2) 
{
	if (val1 > val2) return 1;
	if (val1 < val2) return -1;
	return 0;

}

template<typename T>
bool compareifequal(T val1, T val2)
{
	if (val1 == val2) return 1;
	return 0;

}

template<class T>
class Nod
{
private:
	T val;
	Nod<T>** fii;
	int marime;
	int capacitate;
	int nr_fii;


	void completare(int capacitate_actualizata)
	{
		Nod<T>** buff = new Nod<T>*[capacitate_actualizata];
		memcpy(buff, this->fii, this->marime * sizeof(Nod<T>*));
		delete[] this->fii;
		this->fii = buff;
		this->capacitate = capacitate_actualizata;

	}

public:
	T get_val() const {
		return val;
	}
	int get_nr_fii() const {
		return nr_fii;
	}
	Nod() :val(), fii(new Nod<T>* [30]), marime(0), capacitate(30), nr_fii(0){};
	void add_fii(Nod<T>* nod)
	{
		if (this->marime == this->capacitate) completare(2 * this->capacitate);
		this->fii[this->marime] = nod;
		this->marime++;

	}
	void add_fii_lapoz(Nod<T>* nod, int poz)
	{   
		int i;
		if (this->marime == this->capacitate) completare(2 * this->capacitate);
		for (i = this->marime; i > poz; i--)
			this->fii[i] = this->fii[i - 1];
		this->fii[poz] = nod;
		this->nr_fii++;
	}

	Nod<T>* get_fiu(int poz)
	{
		return this->fii[poz];

	}

	void set_val(T value) {
		val = value;
	}

	int NumarareFii()
	{
		int ct = this->marime, i;
		/*for (i = 0; i < this->marime; i++)
		{
			ct += this->fii[i]-;

		}*/
		return ct;

	}


};

template<class T>
class Tree
{
private:
	Nod<T>* radacina;
public:
	Nod<T>* get_root() const { return radacina; }
	Nod<T>* add_node(Nod<T>* parinte, T val)
	{
		Nod<T>* aux = new Nod<T>;
		aux->set_val(val);
		if (parinte == nullptr) radacina = aux;
		else parinte->add_fii(aux);
		return aux;

	}
	Nod<T>* get_node(Nod<T>* parinte, int poz)
	{
		return parinte->get_fiu(poz);

	}
	void insert(Nod<T>* parinte,T val, int poz)
	{
		Nod<T>* aux = new Nod<T>;
		aux->set_val(val);
		parinte->add_fii_lapoz(aux,poz);

	}
	int count(Nod<T>* parinte)
	{
		if (parinte == nullptr) return radacina->NumarareFii();
		return parinte->NumarareFii();

	}

	void sort(Nod<T>* parinte, int(*comparare)(T, T))
	{
		int nr_fii = parinte->NumarareFii();
		int i, j;
		for(i=0;i<parinte->nr_fii;i++)
			for (j = i + 1; j < parinte->nr_fii; j++)
			{
				if (comparare(parinte->fii[i]->val, parinte->fii[j]->val) > 0)
				{
					T aux;
					aux = parinte->fii[i]->val;
					parinte->fii[i]->val = parinte->fii[j]->val;
					parinte->fii[j]->val = aux;


			    }
			}
	}

	void Print(Nod<T>* parinte)
	{
		int nr_fii =parinte->get_nr_fii();
		int i;
		for (i = 0; i < nr_fii; i++) cout << parinte->get_fiu(i)->get_val() << " ";

	}
};