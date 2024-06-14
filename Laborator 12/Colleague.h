#pragma once
#include <string>
//#ifndef COLLEAGUE_H
//#define COLLEAGUE_H
#include "Contact.h"
#include "ContactType.h"

using namespace std;

class Colleague : Contact {

private:
	string phoneNumber;
	string company;
	string address;

public:
	string getPhoneNumber();

	void setPhoneNumber(string phoneNumber);

	string getCompany();

	void setCompany(string company);

	string getAddress();

	void setAddress(string address);
	string getName();
	ContactType getType();

	/*string getAttribute();

	void setAttribute(int attribute);*/

	Colleague(const string& name, const string& phoneNumber, const string& company, const string& address);
};

//#endif
