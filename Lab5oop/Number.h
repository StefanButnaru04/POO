#pragma once
class Number
{      
	   char* value;
	   int base,nrbase10;
public:
	Number(const char* value, int base); // where base is between 2 and 16
	Number(int n);
	Number(const Number& other);//copy constructor
	Number(Number&& other);//move constructor
	~Number();

	// add operators and copy/move constructor

	Number& operator=(const Number& other);//copy
	Number& operator=(Number&& other);//move
	Number& operator=(const char* value);///n4="13579"

	friend Number operator+(const Number& n1, const Number& n2);
	friend Number operator-(const Number& n1, const Number& n2);
	friend Number operator+=(Number& n1,Number& n2);

    //operatori
	char& operator[](int index);
	bool operator>(const Number& other);
	bool operator<(const Number& other);
	bool operator>=(const Number& other);
	bool operator<=(const Number& other);
	bool operator==(const Number& other);
	bool operator!=(const Number& other);

	//op. de decrementare
	Number& operator--();//prefixat
	Number& operator--(int);//postfixat

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base

  private:
	static char* Convert(const char* val, int baza1, int baza2);
	static char* IntToChar(int nr);
};

