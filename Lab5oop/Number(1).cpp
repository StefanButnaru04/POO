#include "Number.h"
#include <iostream>
using namespace std;


Number::Number(const char* value, int base)
{
	this->base = base;
	this->nrbase10 = 0;
	int lg = 0;
	while (value[lg] != 0) lg++;
	this->value = new char[lg + 1];
	memcpy(this->value, value, lg + 1);
	for (int i = 0; i < lg; i++)
		if ('0' <= this->value[i] && this->value[i] <= '9')
			this->nrbase10 = this->nrbase10 * base + this->value[i]-'0';
		else this->nrbase10 = this->nrbase10 * base + this->value[i] - 'A'+10;

}
 
Number::Number(int n)
{
	int N = n, ct = 0, i;
	this->base = 10;
	this->nrbase10 = n;
	while (N != 0)
	{
		ct++;
		N /= 10;

	}
	this->value = new char[ct + 1];
	this->value[ct] = 0;
	for (i = ct - 1; i >= 0; i--)
	{		
	   this->value[i] = (N % 10) + '0';
	   N = N / 10;
   } 
	this->value[ct] = '\0';
}

Number::Number(const Number& other)//constructor de copiere din other in this
{
	this->base = other.base;
	this->nrbase10 = other.nrbase10;
	int lg = 0;
	while (other.value[lg] != '\0') lg++;
	this->value = new char[lg + 1];
	memcpy(this->value, other.value, lg + 1);


}

Number::Number(Number&& other)//constructorul de mutare si stergere other
{ 
	this->base = other.base;
	this->nrbase10 = other.nrbase10;
	other.base = 0;
	other.nrbase10 = 0;
	int lg = 0;
	while (other.value[lg] != '\0') lg++;
	this->value = new char[lg + 1];
	memcpy(this->value, other.value, lg + 1);
	other.value = nullptr;
}

Number::~Number()
{
	delete[] this->value;
}

Number& Number::operator=(const Number& other)//de copiere
{
	if (this != &other)//daca tb sa ii dam lui this ceva de la alta adresa facem atribuire
	{
		delete[] this->value;//stergem ce era inainte de this
		this->base = other.base;
		this->nrbase10 = other.nrbase10;
		int lg = 0;
		while (other.value[lg] != '\0') lg++;
		this->value = new char[lg + 1];
		memcpy(this->value, other.value, lg + 1);
	}
	return *this;
}

Number& Number::operator=(Number&& other)//de mutare
{
	if (this != &other)//daca tb sa ii dam lui this ceva de la alta adresa facem atribuire
	{
		delete[] this->value;//stergem ce era inainte de this
		this->base = other.base;
		this->nrbase10 = other.nrbase10;
		int lg = 0;
		while (other.value[lg] != '\0') lg++;
		this->value = new char[lg + 1];
		memcpy(this->value, other.value, lg + 1);
		//stergem din other
		other.base = 0;
		other.nrbase10 = 0;
		other.value = nullptr;

	}
	return *this;
}

Number& Number::operator=(const char* value)
{
	//baza nu se schimba,transformam sirul din b10 in baza lui
	char* rez = Number::Convert(value, 10, this->base);
	int lg = 0;
	while (rez[lg] != '\0') lg++;
	delete[] this->value;
	this->value = new char[lg + 1];
	memcpy(this->value, rez, lg + 1);
	this->nrbase10 = 0;
	for (int i = 0; value[i] != 0; i++)
		this->nrbase10 = this->nrbase10 * this->base + value[i] - '0';
	return *this;
}

void Number::Print()
{
	cout << "Numar: " << this->value << " " << " Baza: " << " " << this->base << " In Baza10: " << this->nrbase10;
	cout << "\n";
}

int Number::GetDigitsCount()
{
	int lg = 0;
	while (this->value[lg] != 0) lg++;
	return lg;
}

int Number::GetBase()
{   
	return this->base;
}

char* Number::Convert(const char* val, int baza1, int baza2)
{  //din baza1 in baza 10
	int lg = 0,i,cifra,cifInChar;
	while (val[lg] != '\0') lg++;
	int rez = 0;
	for (i = 0; i < lg; i++)
	{
		cifra = 0;
		if ('0' <= val[i] && val[i] <= '9') cifra = val[i] - '0';
		if ('A' <= val[i] && val[i] <= 'F') cifra = val[i] - 'A' + 10;
		rez = rez * baza1 + cifra;

	}

	//din baza 10 in baza 2
	//folosim un vector char pt ca avem si litere
	char* nou = new char[30];
	i = 0;
	while (rez != 0)
	{
		cifra = rez % baza2;
		if (cifra < 10) cifInChar = cifra + '0';
		else cifInChar = cifra + 'A' - 10;
		nou[i++] = cifInChar;
		rez /= baza2;

	}

	if (i == 0) //daca nr era 0
		nou[i++] = '0';
	nou[i] = '\0';
	// in nou cifrele sunt puse invers asa ca inversam
	for (int j = 0; j < i / 2; j++)
	{
		char aux;
		aux = nou[j];
		nou[j] = nou[i - j - 1];
		nou[i - j - 1] = aux;

	}

	return nou;
}

char* Number::IntToChar(int nr)
{
	int aux = nr, lg = 0;
	while (aux != 0)
	{
		lg++;
		aux /= 10;

	}
	char* val = new char[lg + 1];
	for (int i = lg - 1; i >= 0; i--)
	{
		val[i] = (nr % 10) + '0';
		nr /= 10;
	}
	val[lg] = '\0';
	return val;
}

char& Number::operator[](int index)
{
	return this->value[index];
}

bool Number::operator>(const Number& other)
{
	if (this->nrbase10 >other.nrbase10) return 1;
	return 0;
}

bool Number::operator<(const Number& other)
{
	if (this->nrbase10 < other.nrbase10) return 1;
	return 0;

}

bool Number::operator>=(const Number& other)
{
	if (this->nrbase10 >= other.nrbase10) return 1;
	return 0;

}

bool Number::operator<=(const Number& other)
{
	if (this->nrbase10 <= other.nrbase10) return 1;
	return 0;

}

bool Number::operator==(const Number& other)
{
	if (this->nrbase10 == other.nrbase10) return 1;
	return 0;

}

bool Number::operator!=(const Number& other)
{
	if (this->nrbase10 != other.nrbase10) return 1;
	return 0;

}

Number& Number::operator--()///prefixat
{
	///eliminam bitul din stanga
	int lg = 0;
	while (this->value[lg] != '\0') lg++;
	if (lg == 0) return *this;//daca are 0 cifre nu avem ce elimina
	                          //*this-> este referinta la obiectul curent

	//mutam spre stanga
	for (int i = 0; i < lg; i++)
		this->value[i] = this->value[i + 1];
	this->nrbase10 = 0;
	for (int i = 0; i < lg - 1; i++)
		if ('0' <= this->value[i] && this->value[i] <= '9')
			this->nrbase10 = this->nrbase10 * this->base + this->value[i] - '0';
		else this->nrbase10 = this->nrbase10 * this->base + this->value[i] - 'A'+10;
	return *this;

}

Number& Number::operator--(int)///postfixat
{
	int lg = 0;
	while (this->value[lg] != '\0') lg++;
	this->value[lg - 1] = '\0';
	this->nrbase10 = 0;
	for(int i=0;i<lg-1;i++)
		if('0'<=this->value[i] && this->value[i] <= '9')
			this->nrbase10 = this->nrbase10 * this->base + this->value[i] - '0';
		else this->nrbase10 = this->nrbase10 * this->base + this->value[i] - 'A' + 10;
	return *this;
}


void Number::SwitchBase(int newBase)
{
	if (this->base == newBase) return;
	char* nr = Number::Convert(this->value, this->base, newBase);
	this->base = newBase;
	delete[] this->value;
	int lg = 0;
	while (nr[lg] != '\0') lg++;
	this->value = new char[lg + 1];
	memcpy(this->value, nr, lg + 1);//copiem nr in value
	delete[] nr;
}

Number operator+(const Number& n1, const Number& n2)
{   //det b mai mare
	int baza = n1.base;
	if (n2.base > baza) baza = n2.base;
	int sum = n1.nrbase10 + n2.nrbase10;
	char* rez = Number::IntToChar(sum);//trecem suma intr un sir de caract. pe care
	                                    //il convertim din b10 in base
	rez = Number::Convert(rez, 10, baza);
	Number n(rez, baza);//creem un obiect nou care este rez adunarii,apelam constr1
	//n.nrbaze10=sum
	delete[] rez;
	return n;

}

Number operator-(const Number& n1, const Number& n2)
{  
	//det b mai mare
	int baza = n1.base;
	if (n2.base > baza) baza = n2.base;
	int dif = n1.nrbase10 - n2.nrbase10;
	char* rez = Number::IntToChar(dif);//trecem dif intr un sir de caract. pe care
	//il convertim din b10 in base
	rez = Number::Convert(rez, 10, baza);
	Number n(rez, baza);//creem un obiect nou care este rez adunarii,apelam constr1
	//n.nrbaze10=sum
	delete[] rez;
	return n;
}

Number operator+=(Number& n1, Number& n2)
{
	n1.nrbase10 = n1.nrbase10 + n2.nrbase10;
	char* rez = Number::IntToChar(n1.nrbase10);
	rez = Number::Convert(rez, 10, n1.base);
	int lg = 0;
	while (rez[lg] != '\0') lg++;
	delete[] n1.value;
	n1.value = new char[lg + 1];
	memcpy(n1.value, rez, lg + 1);
	delete[] rez;
	return n1;//ob. care e rez sumei
}
