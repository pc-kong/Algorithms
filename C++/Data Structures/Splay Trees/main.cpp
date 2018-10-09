#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

#include "SplayTree.cpp"

using namespace std;

int main()
{

	srand(time(NULL));

	SplayTree slappy;
	cout << "\nInitial tree" << endl;
	slappy.to_string();

	/* This demo is not robust, so provide valid inputs. */
	while (true) 
	{
		std::string escape;
		cout << "-------------- Splay Trees ----------------" << endl;

		int action;
		cout << "\n1. Insert" << endl;
		cout << "2. Search" << endl;
		cout << "3. Remove" << endl;
		cout << "4. Exit" << endl;
		cout << "Select an option: ";
		cin >> action;

		if (action == 4)
			break;

		int input;
		cout << "\tElement: ";
		cin >> input;

		if (action ==  1)
			slappy.insert(input);
		else if (action ==  2)
			slappy.search(input);
		else
			slappy.remove(input);
		

		if (action == 2)
		{
			if (slappy.is_empty())
				cout << "\nThere are no elements yet :(" << endl;
			else if (slappy.get_root_data() == input)
				cout << "\nI've found the element (:" << endl;
			else {
				cout << "\nThis element doesn't exist, " << 
						"but I brought the closest :(:" << endl;
			}
		}
		cout << "\nTree after operation: " << endl;
		slappy.to_string();
	}

	return 0;
}
