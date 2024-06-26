﻿#include "stdafx.h"
#include "FillRand.h"
#include "BaseFunction.h"
#include "BaseFunction.cpp"
#include "PushAndPop.h"

//#define DINAMIK_MEMORY_1
#define DINAMIK_MEMORY_2

void main()
{
	setlocale(0, "");
	srand(time(NULL));
#ifdef DINAMIK_MEMORY_1
	int size_A{};
	cout << "Введите размер массива: "; cin >> size_A;
	int* A = new int[size_A];
	FillRand(A, size_A, 0, 10);
	Print(A, size_A);

	int element{};
	cout << "Введите значение переменной для добавления её "
		<< "в массив: "; cin >> element;
	A = PushBack(A, size_A, element);
	Print(A, size_A);

	A = PushFront(A, size_A, element);
	Print(A, size_A);

	A = PopBack(A, size_A);
	Print(A, size_A);

	A = PopFront(A, size_A);
	Print(A, size_A);

	cout << "Введите значение переменной для добавления её "
		<< "в массив: "; cin >> element;
	int index;
	cout << "Введите индекс по которому добавить элемент: ";
	cin >> index;
	A = Insert(A, size_A, element, index);
	Print(A, size_A);

	A = Erase(A, size_A, index);
	Print(A, size_A);

	delete[] A;
#endif //DINAMIK_MEMORY_1

#ifdef DINAMIK_MEMORY_2
	int rows_A, cols_A;
	cout << "Введите кол-во строк массива: "; cin >> rows_A;
	cout << "Введите кол-во столбцов массива: "; cin >> cols_A;

	int** A = Allocate(rows_A, cols_A);
	FillRand(A, rows_A, cols_A, 1, 10);
	Print(A, rows_A, cols_A);

	int* B = new int[cols_A];

	FillRand(B, cols_A, 1, 10);
	Print(B, cols_A); cout << endl;
	A = PushRowBack(A, rows_A, cols_A, B);
	Print(A, rows_A, cols_A);

	FillRand(B, cols_A, 1, 10);
	Print(B, cols_A); cout << endl;
	A = PushRowFront(A, rows_A, cols_A, B);
	Print(A, rows_A, cols_A);

	FillRand(B, cols_A, 1, 10);
	Print(B, cols_A); cout << endl;
	int index_Row;
	cout << "Введите индекс по которому добавить строку в массв: ";
	cin >> index_Row;
	A = InsertRow(A, rows_A, cols_A, B, index_Row);
	Print(A, rows_A, cols_A); cout << endl;

	A = PopRowBack(A, rows_A);
	A = PopRowFront(A, rows_A);
	Print(A, rows_A, cols_A); cout << endl;

	cout << "Введите индекс по которому удалить строку из массва: ";
	cin >> index_Row;
	A = EraseRow(A, rows_A, index_Row);
	Print(A, rows_A, cols_A); cout << endl;

	FillRand(B, rows_A, 1, 10);
	Print(B, rows_A);
	A = PushColBack(A, rows_A, cols_A, B);
	Print(A, rows_A, cols_A); cout << endl;

	FillRand(B, rows_A, 1, 10);
	Print(B, rows_A);
	A = PushColFront(A, rows_A, cols_A, B);
	Print(A, rows_A, cols_A); cout << endl;

	FillRand(B, rows_A, 1, 10);
	Print(B, rows_A);
	int index_Col;
	cout << "Введите индекс по которому добавить столбец в массв: ";
	cin >> index_Col;
	A = InsertCol(A, rows_A, cols_A, B, index_Col);
	Print(A, rows_A, cols_A); cout << endl;

	A = PopColBack(A, rows_A, cols_A);
	A = PopColFront(A, rows_A, cols_A);
	Print(A, rows_A, cols_A); cout << endl;

	cout << "Введите индекс по которому удалить столбец из массва: ";
	cin >> index_Col;
	A = EraseCol(A, rows_A, cols_A, index_Col);
	Print(A, rows_A, cols_A); cout << endl;

	Clear(A, rows_A);
#endif //DINAMIK_MEMORY_2
}