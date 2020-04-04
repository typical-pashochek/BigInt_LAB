#include "String.h"
int length(char str[]) {
	int n = 0;
	while (str[n] != '\0') {
		n = n + 1;
	}
	return n;
}

void StrCopy(char** mass1, char** mass2) {
	int len2 = length(*mass2);
	//free(*mass1);
	*mass1 = (char*)malloc((len2 + 1) * sizeof(char));
	(*mass1)[len2] = 0;
	for (int i = 0; i < len2; i++) {
		(*mass1)[i] = (*mass2)[i];
	}


}

int Inclusion(char MainStr[], char SubStr[], int begin) {
	int MainStrLen = length(MainStr);
	int SubStrLen = length(SubStr);
	for (int i = begin; i < MainStrLen; i++) {
		if (MainStr[i] == SubStr[0]) {
			int ind = 0;
			for (int j = i; j < i + SubStrLen; j++) {
				int k = j - i;
				if (MainStr[j] != SubStr[k]) {
					ind = 1;
					break;
				}
			}
			if (ind == 0) {
				return i;
			}
		}
	}
	return -1;
}

int IncCount(char MainStr[], char SubStr[]) {
	int count = 0;
	int MainStrLen = length(MainStr);
	int SubStrLen = length(SubStr);
	for (int i = 0; i < MainStrLen; i++) {
		if (Inclusion(MainStr, SubStr, i) != -1) {
			count = count + 1;
			i = Inclusion(MainStr, SubStr, i) + SubStrLen - 1;
		}
	}
	return count;
}
char* strChange(char MainStr[], char SubStr[], char change[]) {
	int incCount = IncCount(MainStr, SubStr);
	if (incCount == 0) {
		printf("Main string doesn't include substring\n");
		return '\0';
	}
	int MainStrLen = length(MainStr);
	int SubStrLen = length(SubStr);
	int changeLen = length(change);
	int newLen = MainStrLen + incCount * (changeLen - SubStrLen);
	char* newStr = (char*)malloc((newLen + 1) * sizeof(char));
	newStr[newLen] = 0;
	int nsInd = 0;
	for (int i = 0; i < MainStrLen; i++) {
		if (Inclusion(MainStr, SubStr, i) == i) {
			for (int j = 0; j < changeLen; j++) {
				newStr[nsInd] = change[j];
				nsInd += 1;
			}
			i = i + SubStrLen - 1;
		}
		else {
			newStr[nsInd] = MainStr[i];
			nsInd += 1;
		}
	}
	printf("\n");
	return newStr;
}


char** str_split(char MainStr[], char delimiter, int* count) {
	int MainStrLen = length(MainStr);
	int begin = 0, j = 0;
	for (int i = 0; i <= MainStrLen; i++) {
		if (MainStr[i] == delimiter || MainStr[i] == '\0') {
			*count += 1;
		}
	}
	char** strings = (char**)malloc((*count) * sizeof(char*));
	for (int i = 0; i <= MainStrLen; i++) {
		if (MainStr[i] == delimiter || MainStr[i] == '\0') {
			strings[j] = (char*)malloc((i - begin + 1) * sizeof(char));
			strings[j][i - begin] = '\0';
			for (int k = begin; k < i; k++) {
				strings[j][k - begin] = MainStr[k];
			}
			j += 1;
			begin = i + 1;
		}
	}
	return strings;
}


