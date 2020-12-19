#include <iostream>
#include "BST.h"

int main() {
	BST bst;
	bst.insert(1);
	bst.insert(2);
	bst.insert(3);
	cout << bst.find(4) << endl;
	cout << bst.find(3) << endl;
	
	bst.erase(1);
	cout << bst.find(1) << endl;

	return 0;
}
