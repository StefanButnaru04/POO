#include "Friend.h"
#include "Contact.h"
#include "ContactType.h"
#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H
#include <list>
using namespace std;

class AddressBook : public Contact {

public:

	list<Contact*> contacts;

	Contact* searchContactByName(string name);

	list<Friend*> getListOfFriends(string objectAddressBook);

	void DeleteContactByName(string name);

	void addContact(Contact* contact);

	AddressBook();
};

#endif
