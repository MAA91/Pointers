//PushAndPop.cpp
#include "PushAndPop.h"

template <typename T> T* Insert(T* A, int& size_A, T element, int index)
{
	T* Buf = new T[++size_A];
	for (int i = 0; i < size_A; i++)
		*(Buf + i) = (i < index ? *(A + i) : 
			(i > index ? *(A + i - 1) : element));
	delete[] A;
	return Buf;
}
template <typename T> T* Erase(T* A, int& size_A, int index)
{
	T* Buf = new T[size_A - 1];
	for (int i = 0; i < size_A; i++)
		*(Buf + i) = (i < index ? *(A + i) : *(A + i + 1));
	size_A--;
	delete[] A;
	return Buf;
}

template <typename T> T* PushBack(T* A, int& size_A, T element)
{
	return Insert(A, size_A, element, size_A);
}
template <typename T> T* PushFront(T* A, int& size_A, T element)
{
	return Insert(A, size_A, element, 0);
}

template <typename T> T* PopBack(T* A, int& size_A)
{
	return Erase(A, size_A, size_A - 1);
}
template <typename T> T* PopFront(T* A, int& size_A)
{
	return Erase(A, size_A, 0);
}


template <typename T> T** Allocate(int rows_A, int cols_A)
{
	T** Buf = new T * [rows_A];
	for (int i = 0; i < rows_A; i++)
		Buf[i] = new T[cols_A];
	return Buf;
}
template <typename T> void Clear(T** A, int rows_A)
{
	for (int i = 0; i < rows_A; i++)
		delete[] A[i];
	delete[] A;
}

template <typename T> T** InsertRow(T** A, int& rows_A, int cols_A, T* B, int index_Row)
{
	T** Buf = new T * [++rows_A];
	Buf[index_Row] = new T[cols_A];
	for (int j = 0; j < cols_A; j++)
		Buf[index_Row][j] = B[j];
	for (int i = 0; i < rows_A; i++)
		if (i != index_Row)
			Buf[i] = (i < index_Row ? A[i] : A[i - 1]);

	delete[] A;
	return Buf;
}
template <typename T> T** PushRowBack(T** A, int& rows_A, int cols_A, T* B)
{
	return InsertRow(A, rows_A, cols_A, B, rows_A);
}
template <typename T> T** PushRowFront(T** A, int& rows_A, int cols_A, T* B)
{
	return InsertRow(A, rows_A, cols_A, B, 0);
}

template <typename T> T** EraseRow(T** A, int& rows_A, int index_Row)
{
	delete[] A[index_Row];
	return Erase(A, rows_A, index_Row);
}
template <typename T> T** PopRowBack(T** A, int& rows_A)
{
	delete[] A[rows_A - 1];
	return PopBack(A, rows_A);
}
template <typename T> T** PopRowFront(T** A, int& rows_A)
{
	delete[] A[0];
	return PopFront(A, rows_A);
}

template <typename T> T** InsertCol(T** A, int rows_A, int& cols_A, T* B, int index_Col)
{
	T** Buf = new T * [rows_A];
	cols_A++;
	for (int i = 0; i < rows_A; i++)
	{
		Buf[i] = Insert(A[i], cols_A, B[i], index_Col);
		cols_A--;
		//delete[] A[i];
	}
	delete[] A;
	return Buf;
}
template <typename T> T** PushColBack(T** A, int rows_A, int& cols_A, T* B)
{
	return InsertCol(A, rows_A, cols_A, B, cols_A);
}
template <typename T> T** PushColFront(T** A, int rows_A, int& cols_A, T* B)
{
	return InsertCol(A, rows_A, cols_A, B, 0);
}

template <typename T> T** EraseCol(T** A, int rows_A, int& cols_A, int index_Col)
{
	T** Buf = new T * [rows_A];
	for (int i = 0; i < rows_A; i++)
	{
		Buf[i] = Erase(A[i], cols_A, index_Col);
		++cols_A;
		//delete[] A[i];
	}
	cols_A--;
	//delete[] A;
	return Buf;
}
template <typename T> T** PopColBack(T** A, int rows_A, int& cols_A)
{
	return EraseCol(A, rows_A, cols_A, cols_A - 1);
}
template <typename T> T** PopColFront(T** A, int rows_A, int& cols_A)
{
	return EraseCol(A, rows_A, cols_A, 0);
}