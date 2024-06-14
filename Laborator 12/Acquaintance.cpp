#include "Acquaintance.h"
#include "Contact.h"
#include <string>
using namespace std;

string Acquaintance::getPhoneNumber() {
	return this->phoneNumber;
}

void Acquaintance::setPhoneNumber(string phoneNumber) {
	this->phoneNumber = phoneNumber;
}

Acquaintance::Acquaintance(const string& name, const string& phoneNumber) 
{ 
	this->name = name;
	this->phoneNumber = phoneNumber;
}

ContactType Acquaintance::getType()
{
	return ContactType::ACQUAINTANCE;

}
string Acquaintance::getName()
{
	return this->name;
}