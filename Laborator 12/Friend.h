#pragma once
#include <string>
#ifndef FRIEND_H
#define FRIEND_H
#include "Contact.h"
using namespace std;

class Friend : public Contact {

private:
	string dateOfBirth;
	string phoneNumber;
	string address;

public:
	string getDateOfBirth();

	void setDateOfBirth(string dateOfBirth);

	string getPhoneNumber();

	void setPhoneNumber(string phoneNumber);
	string getName();

	string getAddress();

	void setAddress(string address);
	ContactType getType();

	Friend(const string& name, const string& dateOfBirth, const string& phoneNumber, const string& address);

	Friend(string name);
};

#endif
