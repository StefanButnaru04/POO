#include <iostream>
#include "Templates.h"
using namespace std;

int main()
{
	Tree<int> copac;
	Nod<int>* radacina = copac.add_node(nullptr, 1);
	copac.add_node(copac.get_root(), 2);
	copac.add_node(copac.get_root(), 3);
	copac.add_node(copac.get_root(), 4);
	copac.insert(copac.get_root(), 5, 0);
	copac.Print(copac.get_root());
	return 0;
}