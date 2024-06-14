#include "Colleague.h"

string Colleague::getPhoneNumber() {
	return this->phoneNumber;
}

void Colleague::setPhoneNumber(string phoneNumber) {
	this->phoneNumber = phoneNumber;
}

string Colleague::getCompany() {
	return this->company;
}

void Colleague::setCompany(string company) {
	this->company = company;
}

string Colleague::getAddress() {
	return this->address;
}

void Colleague::setAddress(string address) {
	this->address = address;
}
/*
string Colleague::getAttribute() {
	return this->a
}

void Colleague::setAttribute(int attribute) {
	// TODO - implement Colleague::setAttribute
	throw "Not yet implemented";
}*/

Colleague::Colleague(const string& name,const string& phoneNumber,const string& company,const string& address) 
{
	this->name = name;
	this->phoneNumber = phoneNumber;
	this->company = company;
	this->address = address;
}

ContactType Colleague::getType()
{

	return ContactType::COLLEAGUE;
}

string Colleague::getName()
{
	return name;

}