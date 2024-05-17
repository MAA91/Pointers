﻿#include "stdafx.h"
#include "FillRand.h"
#include "BaseFunction.h"
#include "BaseFunction.cpp"
#include "PushAndPop.h"
#include "PushAndPop.cpp"

#define DINAMIK_MEMORY_1
//#define DINAMIK_MEMORY_2

void main()
{
	setlocale(0, "");
	srand(time(NULL));

	typedef int DataType;
#ifdef DINAMIK_MEMORY_1
	int size_A{};
	cout << "Введите размер массива: "; cin >> size_A;
	DataType* A = new DataType[size_A];
	FillRand(A, size_A);
	Print(A, size_A); cout << endl;

	DataType element{};
	cout << "Введите значение переменной для добавления её "
		<< "в массив: "; cin >> element;
	A = PushBack(A, size_A, element);
	Print(A, size_A); cout << endl;

	A = PushFront(A, size_A, element);
	Print(A, size_A); cout << endl;

	A = PopBack(A, size_A); 
	Print(A, size_A); cout << endl;

	A = PopFront(A, size_A);
	Print(A, size_A); cout << endl;

	cout << "Введите значение переменной для добавления её "
		<< "в массив: "; cin >> element;
	int index;
	cout << "Введите индекс по которому добавить элемент: ";
	cin >> index;
	A = Insert(A, size_A, element, index);
	Print(A, size_A); cout << endl;

	A = Erase(A, size_A, index);
	Print(A, size_A); cout << endl;

	delete[] A;
#endif //DINAMIK_MEMORY_1

#ifdef DINAMIK_MEMORY_2
	int rows_A, cols_A;
	cout << "Введите кол-во строк массива: "; cin >> rows_A;
	cout << "Введите кол-во столбцов массива: "; cin >> cols_A;

	DataType** A = Allocate<DataType>(rows_A, cols_A);
	FillRand(A, rows_A, cols_A);
	Print(A, rows_A, cols_A); cout << endl;

	DataType* B = new DataType[cols_A];

	FillRand(B, cols_A);
	Print(B, cols_A); cout << endl;
	A = PushRowBack(A, rows_A, cols_A, B);
	Print(A, rows_A, cols_A); cout << endl;

	FillRand(B, cols_A);
	Print(B, cols_A); cout << endl;
	A = PushRowFront(A, rows_A, cols_A, B);
	Print(A, rows_A, cols_A); cout << endl;

	FillRand(B, cols_A);
	Print(B, cols_A); cout << endl;
	int index_Row;
	cout << "Введите индекс по которому добавить строку в массив: ";
	cin >> index_Row;
	A = InsertRow(A, rows_A, cols_A, B, index_Row);
	Print(A, rows_A, cols_A); cout << endl;

	A = PopRowBack(A, rows_A);
	A = PopRowFront(A, rows_A);
	Print(A, rows_A, cols_A); cout << endl;

	cout << "Введите индекс по которому удалить строку из массива: ";
	cin >> index_Row;
	A = EraseRow(A, rows_A, index_Row);
	Print(A, rows_A, cols_A); cout << endl;

	FillRand(B, rows_A);
	Print(B, rows_A); cout << endl;
	A = PushColBack(A, rows_A, cols_A, B);
	Print(A, rows_A, cols_A); cout << endl;

	FillRand(B, rows_A);
	Print(B, rows_A);
	A = PushColFront(A, rows_A, cols_A, B);
	Print(A, rows_A, cols_A); cout << endl;

	FillRand(B, rows_A);
	Print(B, rows_A); cout << endl;
	int index_Col;
	cout << "Введите индекс по которому добавить столбец в массив: ";
	cin >> index_Col;
	A = InsertCol(A, rows_A, cols_A, B, index_Col);
	Print(A, rows_A, cols_A); cout << endl;

	A = PopColBack(A, rows_A, cols_A);
	A = PopColFront(A, rows_A, cols_A);
	Print(A, rows_A, cols_A); cout << endl;

	cout << "Введите индекс по которому удалить столбец из массива: ";
	cin >> index_Col;
	A = EraseCol(A, rows_A, cols_A, index_Col);
	Print(A, rows_A, cols_A); cout << endl;

	Clear(A, rows_A);
#endif //DINAMIK_MEMORY_2
}