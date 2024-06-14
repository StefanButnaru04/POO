#include "Friend.h"

string Friend::getDateOfBirth() {
	return this->dateOfBirth;
}

void Friend::setDateOfBirth(string dateOfBirth) {
	this->dateOfBirth = dateOfBirth;
}

string Friend::getPhoneNumber() {
	return this->phoneNumber;
}

void Friend::setPhoneNumber(string phoneNumber) {
	this->phoneNumber = phoneNumber;
}

string Friend::getName()
{
	return name;
}

string Friend::getAddress() {
	return this->address;
}

void Friend::setAddress(string address) {
	this->address = address;
}

ContactType Friend::getType()
{
	return ContactType::FRIEND;
}

Friend::Friend(const string& name,const string& dateOfBirth,const string& phoneNumber,const string& address) 
{
	this->name = name;
	this->dateOfBirth = dateOfBirth;
	this->phoneNumber = phoneNumber;
	this->address = address;
}

