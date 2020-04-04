#ifndef STRING
#define STRING
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int length(char str[]);
void StrCopy(char** mass1, char** mass2);
int Inclusion(char MainStr[], char SubStr[], int begin);
int IncCount(char MainStr[], char SubStr[]);
char* strChange(char MainStr[], char SubStr[], char change[]);
char** str_split(char MainStr[], char delimiter, int* count);
#endif