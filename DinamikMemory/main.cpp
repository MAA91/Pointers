#include "stdafx.h"
#include "BaseFunction.h"
#include "BaseFunction.cpp"

//#define DINAMIK_MEMORY_1
#define DINAMIK_MEMORY_2

int* PushBack(int* A, int& size_A, int element);
int* PushFront(int* A, int& size_A, int element);

int* PopBack(int* A, int& size_A);
int* PopFront(int* A, int& size_A);

int* Insert(int* A, int& size_A, int index, int element);
int* Erase(int* A, int& size_A, int index);

int** Allocate(int rows_A, int cols_A);
void Clear(int** A, int rows_A);

int** PushRowFront(int** A, int& rows_A, int cols_A, int* B);
int** InsertRow(int** A, int& rows_A, int cols_A, int* B, int index_Row);

int** PopRowBack(int** A, int& rows_A);
int** PopRowFront(int** A, int& rows_A);
int** EraseRow(int** A, int& rows_A, int index_Row);

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

	cout << "Введите индекс по которому удалить строку в массв: ";
	cin >> index_Row;
	A = EraseRow(A, rows_A, index_Row);
	Print(A, rows_A, cols_A); cout << endl;

	Clear(A, rows_A);
#endif //DINAMIK_MEMORY_2
	

	
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
int* PushFront(int* A, int& size_A, int element)

{
	int* Buf = new int[++size_A];
	*Buf = element;
	for (int i = 1; i < size_A; i++)
		*(Buf + i) = *(A + i - 1);
	delete[] A;
	return Buf;
}

int* PopBack(int* A, int& size_A)
{
	int* Buf = new int[--size_A];
	for (int i = 0; i < size_A; i++) *(Buf + i) = *(A + i);
	delete[] A;
	return Buf;
}
int* PopFront(int* A, int& size_A)
{
	int* Buf = new int[--size_A];
	for (int i = 0; i < size_A; i++) *(Buf + i) = *(A + i + 1);
	delete[] A;
	return Buf;
}

int* Insert(int* A, int& size_A, int element, int index)
{
	int* Buf = new int[++size_A];
	for (int i = 0; i < size_A; i++)
		*(Buf + i) = (i < index ? *(A + i) :
			(i > index ? *(A + i - 1) : element));
	return Buf;
}
int* Erase(int* A, int& size_A, int index)
{
	int* Buf = new int[size_A - 1];
	for (int i = 0; i < size_A; i++)
		*(Buf + i) = (i < index ? *(A + i) : *(A + i + 1));
	size_A--;
	return Buf;
}

int** Allocate(int rows_A, int cols_A)
{
	int** A = new int* [rows_A];
	for (int i = 0; i < rows_A; i++)
		A[i] = new int[cols_A];
	return A;
}
void Clear(int** A, int rows_A)
{
	for (int i = 0; i < rows_A; i++)
		delete[] A[i];
	delete[] A;
}

int** PushRowFront(int** A, int& rows_A, int cols_A, int* B)
{
	int** Buf = new int* [++rows_A];
	Buf[0] = new int[cols_A];
	for (int j = 0; j < cols_A; j++)
		Buf[0][j] = B[j];
	for (int i = 1; i < rows_A; i++)
		Buf[i] = A[i - 1];
	delete[] A;
	return Buf;
}
int** InsertRow(int** A, int& rows_A, int cols_A, int* B, int index_Row)
{
	int** Buf = new int* [++rows_A];
	Buf[index_Row] = new int[cols_A];
	for (int j = 0; j < cols_A; j++)
		Buf[index_Row][j] = B[j];
	for (int i = 0; i < rows_A; i++)
		if (i != index_Row)
			Buf[i] = (i < index_Row ? A[i] : A[i - 1]);
			
	delete[] A;
	return Buf;
}

int** PopRowBack(int** A, int& rows_A)
{
	int** Buf = new int* [--rows_A];
	for (int i = 0; i < rows_A; i++)
		Buf[i] = A[i];
	delete[] A[rows_A];
	delete[] A;
	return Buf;
}
int** PopRowFront(int** A, int& rows_A)
{
	int** Buf = new int* [--rows_A];
	for (int i = 0; i < rows_A; i++)
		Buf[i] = A[i + 1];
	delete[] A[0];
	delete[] A;
	return Buf;
}
int** EraseRow(int** A, int& rows_A, int index_Row)
{
	int** Buf = new int* [rows_A - 1];
	for (int i = 0; i < rows_A; i++)
		if (i < index_Row)
			Buf[i] = A[i];
		else if(i > index_Row)
			Buf[i - 1] = A[i];
	rows_A--;
	delete[] A[index_Row];
	delete[] A;
	return Buf;
}