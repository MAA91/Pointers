#include <iostream>

using namespace std;

void main()
{
	setlocale(0, "");
	srand(time(NULL));

	int size_A = 10;
	int size_even{}, size_odd{};
	int* A = new int[size_A];

	for (int i = 0; i < size_A; i++)
	{
		*(A + i) = rand() % 100;
		cout << *(A + i) << "\t";
		if (*(A + i) % 2 == 0)
			size_even++;
		else
			size_odd++;
	}
	cout << endl;

	int* even = new int[size_even];
	int* odd = new int[size_odd];
	int even_t{}, odd_t{};
	for (int i = 0; i < size_A; i++)
		if (*(A + i) % 2 == 0)
			*(even + even_t++) = *(A + i);
		else
			*(odd + odd_t++) = *(A + i);

	cout << "Even: ";
	for (int i = 0; i < size_even; i++)
		cout << *(even + i) << "\t";
	cout << endl;

	cout << "Odd: ";
	for (int i = 0; i < size_odd; i++)
		cout << *(odd + i) << "\t";
	cout << endl;

	delete A;
	delete even;
	delete odd;
}