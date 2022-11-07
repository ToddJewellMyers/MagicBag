#include <iostream>
#include "MagicBag.h"

int main() {

	MagicBag<int> mb;
	mb.insert(2);
	mb.insert(4);
	mb.insert(6);
	MagicBag<int> mb2(mb);
	MagicBag<int> mb3;
	mb3 = mb;

	cout << mb << endl;
	cout << mb2 << endl;
	cout << mb3 << endl << endl;

	mb.draw();
	cout << mb << endl;
	cout << mb2 << endl;
	cout << mb3 << endl << endl;


	cout << mb.peek(2) << endl;
	cout << mb << endl;
	cout << mb.draw() << endl;
	cout << mb << endl;
	cout << mb.peek(2) << endl;
	cout << mb.draw() << endl;

	MagicBag<char> mbChar;
	mbChar.insert('a');
	mbChar.insert('b');
	mbChar.insert('c');
	cout << mbChar << endl;

}
