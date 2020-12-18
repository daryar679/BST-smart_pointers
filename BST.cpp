#include <iostream>
#include "BST.h"

int main() {
	BST n;
	for (int i = 0; i < 10; ++i)
	{
		n.insert(i);
	}
	n.print();

	for (int i = 8; i > 2; --i)
	{
		n.erase(i);
	}

	n.print();

	return 0;
}
