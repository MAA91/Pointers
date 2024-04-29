#include "stdafx.h"
#include "BaseFunction.h"
#include "BaseFunction.cpp"

int* PushBack(int* A, int& size_A, int element);

void main()
{
	setlocale(0, "");
	srand(time(NULL));

	int size_A{};
	cout << "Введите размер массива: "; cin >> size_A;
	int* A = new int[size_A];
	FillRand(A, size_A, 0, 10);
	Print(A, size_A);

	int veleu{};
	cout << "Введите значение переменной для добавления её "
		<< "в массив: "; cin >> veleu;
	A = PushBack(A, size_A, veleu);
	
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