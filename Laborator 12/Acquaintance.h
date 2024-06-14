#ifndef ACQUAINTANCE_H
#define ACQUAINTANCE_H
#include "Contact.h"
#include "ContactType.h"
using namespace std;

class Acquaintance : public Contact {

private:
	string phoneNumber;

public:
	
	string getPhoneNumber();

	void setPhoneNumber(string phoneNumber);

	Acquaintance(const string& name,const string& phoneNumber);
	ContactType getType();
	string getName();
};

#endif
