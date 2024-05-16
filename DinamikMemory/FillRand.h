//FillRand.h
#pragma once
#include "stdafx.h"

void FillRand(int A[], int size, int min_zn = 0, int max_zn = 100);
void FillRand(double A[], int size, double min_zn = 0, double max_zn = 100);
void FillRand(char A[], int size);

void FillRand(int** A, int ROW, int COL, int min_zn = 0, int max_zn = 100);
void FillRand(double** A, int ROW, int COL, double min_zn = 0, double max_zn = 100);
void FillRand(char** A, int ROW, int COL);