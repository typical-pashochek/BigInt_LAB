#include <stdio.h>
#include "_LAB_6.h"
#include "String.h"

typedef struct {
	int* digit;
	int len;
} BigInt_;


int main(int argc, char* argv[]) {
	BigInt_ a, b;

	int way = Choice();
	//puts(argv[1]);

	switch (way) {
	case 1:
		getchar();
		BigIntInput_Keyboard(&(a.digit), &(a.len));
		BigIntInput_Keyboard(&(b.digit), &(b.len));
		OutputBigInt_(&(a.digit), a.len);
		printf("\n");
		OutputBigInt_(&(b.digit), b.len);
		break;
	case 2:			
		BigIntInput_File(&(a.digit), &(a.len), "a.txt");
		BigIntInput_File(&(b.digit), &(b.len), "b.txt");
		OutputBigInt_(&(a.digit), a.len);
		printf("\n");
		OutputBigInt_(&(b.digit), b.len);
		break;
	}
	BigInt_ res;
	/*res.digit = BigIntSum(&(a.digit), a.len, &(b.digit), b.len, &(res.len));
	printf("\n");
	printf("Amount\n");
	OutputBigInt_(&(res.digit), res.len);
	printf("\n");
	printf("Difference\n");
	res.digit = BigIntDiff(&(a.digit), a.len, &(b.digit), b.len, &(res.len));
	OutputBigInt_(&(res.digit), res.len);
	printf("\n");
	printf("Multiplication\n");
	res.digit = BigIntMultiply(&(a.digit), a.len, &(b.digit), b.len, &(res.len));
	OutputBigInt_(&(res.digit), res.len);
	printf("\n");
	printf("Division\n");
	res.digit = BigIntDivision(&(a.digit), a.len, &(b.digit), b.len, &(res.len));
	OutputBigInt_(&(res.digit), res.len);*/
	printf("\n");
	printf("Modulo\n");
	res.digit = BigIntModulo(&(a.digit), a.len, &(b.digit), b.len, &(res.len));
	OutputBigInt_(&(res.digit), res.len);
	printf("\n");
	system("pause");
	return 0;
}