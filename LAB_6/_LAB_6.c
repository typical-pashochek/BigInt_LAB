#include "_LAB_6.h"
#include "String.h"

int Max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

void OutputBigInt_(int** res, int len) {
	int i = 0;
	/*while ((*res)[i] == 0) {
		i++;
	}*/
	for (int j = i; j < len; j++) {
		printf("%d", (*res)[j]);
	}
}

void BigIntInput_File(int** mass2, int* len, char* fName) {
	FILE* input;
	fopen_s(&input, fName, "r");
	if (input == NULL) {
		printf("File doesn't exist.\n");
		system("pause");
		exit(1);
	}
	if (getc(input) == EOF) {
		printf("File is empty.\n");
		system("pause");
		exit(1);
	}
	fseek(input, 0, SEEK_SET);
	char* mass = (char*)malloc(1000 * sizeof(char));
	char sym = fgetc(input);
	if (!isdigit(sym)) {
		printf("Incorrect input. Only digits elements!\n");
		exit(1);
	}
	mass[0] = sym;
	int i = 1;
	sym = fgetc(input);
	while (!feof(input)) {
		if (!isdigit(sym)) {
			printf("Incorrect input\n");
			exit(1);
		}
		mass[i] = sym;
		i += 1;
		sym = fgetc(input);
	}
	mass[i] = 0;
	*mass2 = (int*)malloc(length(mass) * sizeof(int));
	for (int i = 0; i < length(mass); i++) {
		(*mass2)[i] = (int)mass[i] - 48;
	}
	*len = length(mass);
	free(mass);

}

void BigIntInput_Keyboard(int** mass2, int* len) {
	char* mass = (char*)malloc(1000 * sizeof(char));
	char sym = getchar();
	if (!isdigit(sym)) {
		printf("Incorrect input. Only digits elements!\n");
		exit(1);
	}
	mass[0] = sym;
	int i = 1;
	sym = getchar();
	while (sym != '\n') {
		if (!isdigit(sym)) {
			printf("Incorrect input\n");
			exit(1);
		}
		mass[i] = sym;
		i += 1;
		sym = getchar();
	}
	mass[i] = 0;
	*mass2 = (int*)malloc(length(mass) * sizeof(int));
	for (int i = 0; i < length(mass); i++) {
		(*mass2)[i] = (int)mass[i] - 48;
	}
	*len = length(mass);
	free(mass);
}

int Choice() {
	printf("Chose how to input matrix:\n 1 - From the keyboard\n 2 - From the file\n");
	int way;
	scanf_s("%d", &way);
	while (way < 1 || way > 2) {
		printf("There is no such option. Repeat please.\n");
		scanf_s("%d", &way);
	}
	return way;
}

int* BigIntSum(int** a,int lenA, int** b, int lenB, int* len) {
	int* res_ = (int*)malloc((Max(lenA, lenB)+1)*sizeof(int));
	int lenRes = Max(lenA, lenB) + 1;
	for (int i = 0; i < lenRes; i++) {
		res_[i] = 0;
	}
	int count = 1;
	while (count <= lenA && count <= lenB) {
		int A = ((*a)[lenA - count]);
		int B = ((*b)[lenB - count]);
		int sum = A + B + res_[lenRes - count];
		res_[lenRes - count] = sum  % 10;
		res_[lenRes - count - 1] = sum / 10;
		count += 1;
	}
	if (lenA > lenB) {
		while (count <= lenA) {
			int A = ((*a)[lenA - count]);
			int sum = A + res_[lenRes - count];
			res_[lenRes - count] = sum % 10;
			res_[lenRes - count - 1] = sum / 10;
			count += 1;
		}
	}
	else {
		while (count <= lenB) {
			int B = ((*b)[lenB - count]);
			int sum = B + res_[lenRes - count];
			res_[lenRes - count] = sum % 10;
			res_[lenRes - count - 1] = sum / 10;
			count += 1;
		}

	}
	int* res;
	*len = 0;
	for (int i = 0; i < lenRes; i++) {
		if (res_[i] != 0) {
			*len = lenRes - i;
			break;
		}
	}
	if (*len == 0) {
		*len = 1;
	}
	res = (int*)malloc(*len * sizeof(int));
	for (int i = lenRes - *len; i < lenRes; i++) {
		res[i - lenRes + *len] = res_[i];
	}
	free(res_);
	return res;
}


int* BigIntDiff(int** a, int lenA, int** b, int lenB, int* len) {
	int* res_ = (int*)malloc((Max(lenA, lenB)) * sizeof(int));
	int flag = 0;
	if (lenA < lenB) {
		flag = 1;
	}
	else if (lenA == lenB) {
		for (int i = 0; i < lenA; i++) {
			if ((*a)[i] < (*b)[i]) {
				flag = 1;
				break;
			}
		}
	}
	int* res;
	int count = 1;
	if (flag == 0) {
		for (int i = 0; i < lenA; i++) {
			res_[i] = (*a)[i];
		}
		while (count <= lenB) {
			if (res_[lenA - count] - (*b)[lenB - count] < 0) {
				res_[lenA - count - 1] -= 1;
				res_[lenA - count] += 10;
				res_[lenA - count] -= (*b)[lenB - count];
			}
			else {
				res_[lenA - count] -= (*b)[lenB - count];
			}
			count += 1;
		}
		*len= 0;
		for (int i = 0; i < lenA; i++) {
			if (res_[i] != 0) {
				*len = lenA - i;
				break;
			}
		}
		if (*len == 0) {
			*len = 1;
		}
		res = (int*)malloc(*len * sizeof(int));
		for (int i = lenA - *len; i < lenA; i++) {
			res[i - lenA + *len] = res_[i];
		}
	}
	else {
		for (int i = 0; i < lenB; i++) {
			res_[i] = (*b)[i];
		}
		while (count <= lenA) {
			if (res_[lenB - count] - (*a)[lenA - count] < 0) {
				res_[lenB - count - 1] -= 1;
				res_[lenB - count] += 10;
				res_[lenB - count] -= (*a)[lenA - count];
			}
			else {
				res_[lenB - count] -= (*a)[lenA - count];
			}
			count += 1;
		}
		*len = 0;
		for (int i = 0; i < lenB; i++) {
			if (res_[i] != 0) {
				*len = lenB - i;
				break;
			}
		}
		if (*len == 0) {
			*len = 1;
		}
		res = (int*)malloc(*len * sizeof(int));
		for (int i = lenB - *len; i < lenB; i++) {
			res[i - lenB + *len] = res_[i];
		}
		res[0] *= -1;
	}
	free(res_);
	return res;
}


int* BigIntMultiply(int** a, int lenA, int** b, int lenB, int* len) {
	int lenRes = Max(lenA, lenB) * 2;
	int* res_ = (int*)malloc(lenRes * sizeof(int));
	for (int i = 0; i < lenRes; i++) {
		res_[i] = 0;
	}
	
	for (int i = lenB - 1; i >= 0; i--) {
		int count = lenB - i;
		for (int j = lenA - 1; j >= 0; j--) {
			int mult = (*b)[i] * (*a)[j];
			res_[lenRes - count - 1] += (res_[lenRes - count] + mult) / 10;
			res_[lenRes - count] = (res_[lenRes - count] + mult)%10;
			
			count += 1;
		}
		for (int j = lenRes - 1; j > 0; j--) {
			res_[j - 1] += res_[j] / 10;
			res_[j] = res_[j] % 10;
		}
	}
	int* res;
	*len = 0;
	for (int i = 0; i < lenRes; i++) {
		if (res_[i] != 0) {
			*len = lenRes - i;
			break;
		}
	}
	if (*len == 0) {
		*len = 1;
	}
	res = (int*)malloc(*len * sizeof(int));
	for (int i = lenRes - *len; i < lenRes; i++) {
		res[i - lenRes + *len] = res_[i];
	}
	free(res_);
	return res;
}

int* BigIntDivision(int** a, int lenA, int** b, int lenB, int* len) {
	int flag = 0;
	if (lenB == 1) {
		if ((*b)[0] == 0) {
			printf("Error. Division by 0\n");
			exit(1);
		}
		else if ((*b)[0] == 1) {
			return ((*a));
		}
	}


	if (lenA < lenB) {
		flag = 1;
	}
	else if (lenA == lenB) {
		for (int i = 0; i < lenA; i++) {
			if ((*a)[i] < (*b)[i]) {
				flag = 1;
				break;
			}
		}
	}
	if (flag == 1) {
		int* res = (int*)malloc(sizeof(int));
		res[0] = 0;
		*len = 1;
		return res;
	}



	int* res_ = (int*)malloc(sizeof(int));
	int* mnozh;
	int digit = 0;
	int lenMn = lenA - lenB + 1;
	mnozh = (int*)malloc(lenMn * sizeof(int));
		for (int i = 0; i < lenMn; i++) {
			mnozh[i] = 0;
		}
		mnozh[0] = 1;
	int flagInc = 0;
	while (digit < lenMn) {	
		
		res_ = BigIntMultiply(b, lenB, &mnozh, lenMn, len);
		flag = 0;
		for (int i = 0; i < lenA; i++) {
			if ((*a)[i] < res_[i]) {
				flag = 1;
				break;
			}
			if ((*a)[i] > res_[i]) {
				flag = 0;
				break;
			}
		}
		if (flag == 0) {
			
			
			if (flagInc == 2) {
				digit += 1;
				mnozh[digit] = 9;
			}
			else {
				mnozh[digit] += 1;
				mnozh[digit - 1] += mnozh[digit] / 10;
				mnozh[digit] %= 10;
			}
			flagInc = 1;
		}
		if (flag == 1) {
			mnozh[digit] -= 1;
			if ((mnozh[digit] == 1) && (digit == 0)) {
				digit += 1;
				mnozh[digit] = 9;
			}
			if (mnozh[digit] == 0) {
				digit += 1;
				mnozh[digit] = 9;
			}
			if (mnozh[0] == 0) {
				mnozh[1] = 9;
				int* mass = (int*)malloc(lenMn * sizeof(int));
				for (int i = 0; i < lenMn; i++) {
					mass[i] = mnozh[i];
				}
				free(mnozh);
				lenMn -= 1;
				mnozh = (int*)malloc(lenMn * sizeof(int));
				for (int i = 0; i < lenMn; i++) {
					mnozh[i] = mass[i + 1];
				}
				free(mass);
			}
			
			flagInc = 2;
		}
	}
	*len = lenMn;
	free(res_);
	return mnozh;
}

int* BigIntModulo(int** a, int lenA, int** b, int lenB, int* len) {
	int lenDiv;
	int* div = BigIntDivision(a, lenA, b, lenB, &lenDiv);
	
	int lenMult;
	div = BigIntMultiply(b, lenB, &div, lenDiv, &lenMult);
	//OutputBigInt_(&mult, lenMult);
	OutputBigInt_(&div, lenMult);
	int lenDiff;
	int* diff = BigIntDiff(a, lenA, &div, lenMult, &lenDiff);
	free(div);
	//free(mult);
	*len = lenDiff;
	return diff;
}