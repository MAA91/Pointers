//PushAndPop.h
#pragma once
#include "stdafx.h"

template <typename T>
T* PushBack(T* A, int& size_A, T element);
template <typename T>
T* PushFront(T* A, int& size_A, T element);

template <typename T>
T* PopBack(T* A, int& size_A);
template <typename T>
T* PopFront(T* A, int& size_A);

template <typename T>
T* Insert(T* A, int& size_A, T element, int index);
template <typename T>
T* Erase(T* A, int& size_A, int index);

template <typename T>
T** Allocate(T** A, int rows_A, int cols_A);
template <typename T>
void Clear(T** A, int rows_A);

template <typename T>
T** PushRowBack(T** A, int& rows_A, int cols_A, T* B);
template <typename T>
T** PushRowFront(T** A, int& rows_A, int cols_A, T* B);
template <typename T>
T** InsertRow(T** A, int& rows_A, int cols_A, T* B, int index_Row);

template <typename T>
T** PopRowBack(T** A, int& rows_A);
template <typename T>
T** PopRowFront(T** A, int& rows_A);
template <typename T>
T** EraseRow(T** A, int& rows_A, int index_Row);

template <typename T>
T** PushColBack(T** A, int rows_A, int& cols_A, T* B);
template <typename T>
T** PushColFront(T** A, int rows_A, int& cols_A, T* B);
template <typename T>
T** InsertCol(T** A, int rows_A, int& cols_A, T* B, int index_Col);

template <typename T>
T** PopColBack(T** A, int rows_A, int& cols_A);
template <typename T>
T** PopColFront(T** A, int rows_A, int& cols_A);
template <typename T>
T** EraseCol(T** A, int rows_A, int& cols_A, int index_Col);