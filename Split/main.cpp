#include "stdafx.h"
#include "BaseFunction.h"
#include "BaseFunction.cpp"

void Split(int* A, int size_A, int* even, int* odd);

void main()
{
	setlocale(0, "");
	srand(time(NULL));

	int size_A = 10;
	int* A = new int[size_A];
	FillRand(A, size_A, 0, 10);
	Print(A, size_A);

	int size_even{}, size_odd{};
	for (int i = 0; i < size_A; i++)
		(*(A + i) % 2 == 0 ? size_even : size_odd)++;
	
	int* even = new int[size_even];
	int* odd = new int[size_odd];
	Split(A, size_A, even, odd);
	
	cout << "Even: ";
	Print(even, size_even);

	cout << "Odd: ";
	Print(odd, size_odd);

	delete[] A;
	delete[] even;
	delete[] odd;
}

void Split(int* A, int size_A, int* even, int* odd)
{
	int* p_even = even, * p_odd = odd;

	for (int i = 0; i < size_A; i++)
		(*(A + i) % 2 == 0 ? *p_even++ : *p_odd++) 
		= *(A + i);
}