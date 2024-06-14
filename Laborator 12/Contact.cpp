#include "Contact.h"
#include <string>
#include "ContactType.h"
string Contact::getName() {
	return this->name;
}

void Contact::setName(string name) {
	this->name = name;
}

/*Contact::Contact(const string& name) {
	this->name = name;
}
*/