//FillRand.cpp
#include "FillRand.h"

void FillRand(int A[], int size, int min_zn, int max_zn)
{
	for (int i = 0; i < size; i++)
		A[i] = min_zn + rand() % (max_zn - min_zn + 1);
}
void FillRand(double A[], int size, double min_zn, double max_zn)
{
	for (int i = 0; i < size; i++)
		A[i] = (double)(rand() % 1000) / 1000 + min_zn + rand() % (int)(max_zn - min_zn);
}
void FillRand(char A[], int size)
{
	for (int i = 0; i < size; i++)
		A[i] = rand();
}

void FillRand(int** A, int ROW, int COL, int min_zn, int max_zn)
{
	for (int i = 0; i < ROW; i++) FillRand(A[i], COL, min_zn, max_zn);
}
void FillRand(double** A, int ROW, int COL, double min_zn, double max_zn)
{
	for (int i = 0; i < ROW; i++) FillRand(A[i], COL, min_zn, max_zn);
}
void FillRand(char** A, int ROW, int COL)
{
	for (int i = 0; i < ROW; i++) FillRand(A[i], COL);
}