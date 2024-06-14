#include "AddressBook.h"
#include "ContactType.h"
#include "Contact.h"
#include <list>
#include "Friend.h"
#pragma once
using namespace std;

Contact* AddressBook::searchContactByName(string name) {
	for (auto contact : contacts)
	{
		if (contact->getName() == name) return contact;

	}
	return nullptr;
}

list<Friend*> AddressBook::getListOfFriends(string objectAddressBook) {
	list<Friend*> friends;
	for (auto contact : contacts)
	{
		if (contact->getType() == ContactType::FRIEND)
			friends.push_back(static_cast<Friend*>(contact));

	}
	return friends;
}

void AddressBook::DeleteContactByName(string name) {
	list<string>::iterator it;
	for(auto it=contacts.begin();it!=contacts.end();it++)
		if (name == (*it)->getName())
		{
			contacts.erase(it);
			break;
		}
}

void AddressBook::addContact(Contact* contact) {
	contacts.push_back(contact);
}

AddressBook::AddressBook() {
	// TODO - implement AddressBook::AddressBook
	throw "Not yet implemented";
}
