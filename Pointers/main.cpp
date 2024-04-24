#include <iostream>

using namespace std;

void main()
{
	setlocale(0, "");
	const int SIZE = 5;
	int A[SIZE]{ 5, 3, 9, 1, 0 };
	for (int i = 0; i < SIZE; i++)
	{
		cout << *(A + i) << endl;
	}
}