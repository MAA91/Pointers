//PushAndPop.h
#pragma once
#include "stdafx.h"

int* PushBack(int* A, int& size_A, int element);
int* PushFront(int* A, int& size_A, int element);

int* PopBack(int* A, int& size_A);
int* PopFront(int* A, int& size_A);

int* Insert(int* A, int& size_A, int index, int element);
int* Erase(int* A, int& size_A, int index);

int** Allocate(int rows_A, int cols_A);
void Clear(int** A, int rows_A);

int** PushRowBack(int** A, int& rows_A, int cols_A, int* B);
int** PushRowFront(int** A, int& rows_A, int cols_A, int* B);
int** InsertRow(int** A, int& rows_A, int cols_A, int* B, int index_Row);

int** PopRowBack(int** A, int& rows_A);
int** PopRowFront(int** A, int& rows_A);
int** EraseRow(int** A, int& rows_A, int index_Row);

int** PushColBack(int** A, int rows_A, int& cols_A, int* B);
int** PushColFront(int** A, int rows_A, int& cols_A, int* B);
int** InsertCol(int** A, int rows_A, int& cols_A, int* B, int index_Col);

int** PopColBack(int** A, int rows_A, int& cols_A);
int** PopColFront(int** A, int rows_A, int& cols_A);
int** EraseCol(int** A, int rows_A, int& cols_A, int index_Col);