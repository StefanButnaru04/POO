#pragma once
#include <string>
#include "ContactType.h"
#ifndef CONTACT_H
#define CONTACT_H
using namespace std;

class Contact {

public:
	string name;
	virtual string getName()=0;

	void setName(string name);

	virtual ContactType getType() = 0;
	///Contact(const string& name);
};

#endif
