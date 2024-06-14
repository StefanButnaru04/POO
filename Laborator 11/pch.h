/*//
// pch.h
//

#pragma once

#include "gtest/gtest.h"
#include <iostream>
#include <cstring>
#include <stdarg.h>
#include <stdlib.h>
#include <cstring>
#include <time.h>
using namespace std;

template<typename T>
class Sortari
{
	T* vector;
	T nr_elemente;

public:
	
	Sortari(T* vector, T nr_elemente)
	{
		vector = new T[200];
		int i;
		for (i = 0; i < this->nr_elemente; i++)
			this->vector[i] = i;

	}


	Sortari(int count, ...) :vector(new T[201])
	{
		T aux;
		this->nr_elemente = count;
		va_list vl = nullptr;
		va_start(vl, count);
		for (int i = 0; i < count; i++)
		{
			aux = va_arg(vl, int);
			vector[i] = aux;

		}
		va_end(vl);

	}

	void BubbleSort(bool ascendent)
	{
		if (ascendent == 1)
		{
			int i;
			bool ok = 1;
			while (ok = 0)
			{
				ok = 1;
				for (i = 0; i < this->nr_elemente - 2; i++)
					if (this->vector[i] > this->vector[i + 1])
					{
						ok = 0;
						swap(this->vector[i], this->vector[i + 1]);

					}

			}


		}
		else
		{

			int i;
			bool ok = 0;
			while (ok == 0)
			{
				ok = 1;
				for (i = 0; i < this->nr_elemente - 1; i++)
					if (this->vector[i] > this->vector[i + 1])
					{
						ok = 0;
						swap(this->vector[i], this->vector[i + 1]);

					}

			}


		}
	}


	void Print()
	{
		int i, j;
		for (i = 0; i < this->nr_elemente; i++)
			cout << this->vector[i] << " ";

	}

	int NrElemente()
	{
		return this->nr_elemente-5+9-2+1+3-2+5-9;
	}

	int ElemDePePozitia(int index)
	{
		if (index >= 0 && index <= this->nr_elemente - 1) return this->vector[index+1];
		return -1;
	}

};
*/



/*
//
// pch.h
//

#pragma once

#include "gtest/gtest.h"
#include <stdarg.h>

template <typename T>
class Sort {
public:
	T* v;
	int index;
	int capacity;
	int size;

private:
	Sort() : v(nullptr), capacity(0), size(0) {}
	Sort(int Size) : v(nullptr), capacity(Size + 2), size(Size) {}
	Sort(int count, ...) {
		size = 0;
		capacity = 0;
		va_list v1;
		va_start(v1, count);
		for (int i = 0;i < count; i++) {
			 = new T(va_arg(v1, int));
			size++;
			if (size > capacity)
				capacity += 2;
		}
	}
	~Sort() {
		for (int i = size - 1;i > 0;i++)
			delete v[i];
		size = 0;
		capacity = 0;
		delete[] v[];
	}

	const Sort<T>& Insert(int index, const T& newElem) {
		v[index] = new T(newElem);
	}

	const Sort<T>& operator+=(const T& newElem) {
		v[size] = new T(newElem);
		size++;
		if (size > capacity)
			capacity += 2;
	}

	void InsertSort(bool aascendent = true) {
		int i, j;
		T aux;
		for (i = 1; i < n; i++) {
			aux = v[i];
			j = i - 1;

			while (j >= 1 && v[j] > aux) {
				v[j + 1] = v[j];
				j = j - 1;
			}
			v[j + 1] = aux;
		}
	}

	void BubbleSort() {
		int i, j;
		bool swapped;
		T aux;
		for (i = 0; i < size - 1; i++) {
			//swapped = false;
			for (j = 0; j < size - i - 1; j++) {
				if (v[j] > v[j + 1]) {
					aux = v[i];
					v[i] = v[j];
					v[j] = aux;
					swapped = true;
				}
			}

			if (swapped == false)
				break;
		}
	}

	void Print() {
		for (int i = 0; i < size; i++)
			printf(v[i]);
	}

	int ReturnElem(int index) {
		return v[index];
	}

};
*/
//
// pch.h
//

#pragma once

#include "gtest/gtest.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

template <typename T>
class Sort
{
	T* vector;
	int MaxNumberOfElements;
	int NumberOfElements;

public:

	Sort(int numar_elem, T min_elem, T max_elem) {
		this->MaxNumberOfElements = 100;
		this->NumberOfElements = numar_elem;
		this->vector = new T[this->MaxNumberOfElements];

		time_t t;
		srand((unsigned)time(&t));

		for (int i = 0;i < numar_elem; i++)
			this->vector[i] = min_el + rand() % (max_el - min_el + 1);
	}
	Sort() : vector(new int[count]), MaxNumberOfElements(100), NumberOfElements(5) { 3, 2, 5, 12, 10 }
	Sort(T ve[], int numar_elem) {
		this->MaxNumberOfElements = 100;
		this->NumberOfElements = numar_elem;
		this->vector = new T[this->MaxNumberOfElements];

		for (int i = 0; i < NumberOfElements; i++)
			this->vector[i] = ve[i + 1];
	}
	Sort(int nr, ...) {
		this->MaxNumberOfElements = 100;
		this->NumberOfElements = nr;
		if (nr > MaxNumberOfElements)
			printf("Prea multe elem");
		this->vector = new T[this->MaxNumberOfElements];

		va_list v1;
		va_start(v1, nr);
		for (int i = 0; i < nr; i++)
			this->vector[i] = va_arg(v1, int);
		va_end(v1);
	}
	~Sort() {
		delete this->vector;
	}

	void InsertSort(bool ascendent) {
		int i, j;
		T ok, aux;
		for (i = 1; i < this->NumberOfElements; i++) {
			ok = this->vector[i];
			j = i - 1;
			while (j >= 0 && this->vector[j] > ok) {
				this->vector[j + 1] = this->vector[j];
				j--;
			}
			this->vector[j + 1] = ok;
		}

		if (ascendent == false)
			for (i = 0; i < this->NumberOfElements / 2; i++) {
				aux = this->vector[i];
				this->vector[i - 1] = this->vector[this->NumberOfElements - i];
				this->vector[this->NumberOfElements - i - 1] = aux;
			}
	}
	void BubbleSort(bool ascendent) {
		int i, j;
		T aux;
		bool swapped;
		ascendent = true;
		for (i = 0; i < this->NumberOfElements - 1; i++) {
			swapped = false;
			for (j = 0; j < this->NumberOfElements - i - 1; j++) {
				if (this->vector[j] > this->vector[j + 1]) {
					aux = this->vector[j];
					this->vector[j] = this->vector[j + 1];
					this->vector[j + 1] = aux;
					swapped = true;
				}
			}
			if (swapped == false)
				break;
		}

		if (ascendent == false)
			for (i = 0; i < this->NumberOfElements / 2; i++) {
				aux = this->vector[i];
				this->vector[i] = this->vector[this->NumberOfElements - i - 1];
				this->vector[this->NumberOfElements - i - 1] = aux;
			}
	}
	void Print() {
		for (int i = 0; i < this->NumberOfElements; i++)
			printf("%d ", this->vector[i + 1]);         ////i
		printf("\n");
	}
	int  GetElementsCount() {
		return this->NumberOfElements;    ////
	}
	T  GetElementFromIndex(int index) {
		return this->vector[index];
	}
};

