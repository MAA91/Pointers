#include "stdafx.h"
#include "BaseFunction.h"
#include "BaseFunction.cpp"

int* PushBack(int* A, int& size_A, int element);

void main()
{
	setlocale(0, "");
	srand(time(NULL));

	int size_A{};
	cout << "¬ведите размер массива: "; cin >> size_A;
	int* A = new int[size_A];
	FillRand(A, size_A, 0, 10);
	Print(A, size_A);

	A = PushBack(A, size_A, 5);
	/*int veleu{};
	cout << "¬ведите значение переменной дл€ добавлени€ еЄ "
		<< "в массив: "; cin >> veleu;

	int* Buf = A;
	A = new int[size_A + 1];
	for (int i = 0; i < size_A; i++)
		*(A + i) = *(Buf + i);
	delete[] Buf;
	*(A + size_A++) = veleu;*/
	Print(A, size_A);

	delete[] A;
}

int* PushBack(int* A, int& size_A, int element)
{
	int* Buf = new int[size_A + 1];
	for (int i = 0; i < size_A; i++)
		*(Buf + i) = *(A + i);
	*(Buf + size_A) = element;
	size_A++;
	delete[] A;
	return Buf;
}