#pragma once
#include <stdio.h>
int Max(int a, int b);
void OutputBigInt_(int** res, int len);
void BigIntInput_File(int** mass2, int* len, char* fName); 
void BigIntInput_Keyboard(int** mass2, int* len);
int Choice();
int* BigIntSum(int** a, int lenA, int** b, int lenB, int* len);
int* BigIntDiff(int** a, int lenA, int** b, int lenB, int* len);
int* BigIntMultiply(int** a, int lenA, int** b, int lenB, int* len);
int* BigIntDivision(int** a, int lenA, int** b, int lenB, int* len);
int* BigIntModulo(int** a, int lenA, int** b, int lenB, int* len);