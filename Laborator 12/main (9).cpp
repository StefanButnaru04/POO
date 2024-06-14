#include <iostream>
#include "Friend.h"
#include "Contact.h"
using namespace std;

int main()
{
	Friend* cat=new Friend("puiu","12.02.2022","545512","dkdlkd");
	//cat.setName("motanu tanu");
	cout << cat->getName()<<"\n";
	cout << cat->getDateOfBirth();

}