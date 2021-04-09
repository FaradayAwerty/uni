#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define FILENAME "string.txt"

// линейный поиск
int lin(char *str, char *sub);

// поиск Бойера--Мура
int bm(char *str, char *sub);

// поиск Кнута--Морриса--Пратта
int kmp(char *str, char *sub);

// поиск Карпа-Рабина
int kr(char *str, char *sub);

int main()
{
	FILE *f = fopen(FILENAME, "r");
	if(f == NULL) {
		puts("can't open the file");
		return 1;
	}

	size_t str_size = 32, str_len;
	char *str = (char*)malloc(str_size*sizeof(char));

	size_t sub_size = 8, sub_len;
	char *sub = (char*)malloc(sub_size*sizeof(char));

	// breaks when reached end of file
	while(true) {
		do {
			str_len = getline(&str, &str_size, f);
		} while(str_len == 1);

		do {
			sub_len = getline(&sub, &sub_size, f);
		} while(sub_len == 1);

		if(str_len == -1 || sub_len == -1)
			break;

		// remove newline character at the end
		str[str_len-- - 1] = '\0';
		sub[sub_len-- - 1] = '\0';

		printf("%s\t%6d\t%6d\t%6d\t%6d\n%s\n",
				str,
				lin(str, sub),
				bm(str, sub),
				kmp(str, sub),
				kr(str, sub),
				sub);
	}
	
	free(str); free(sub); fclose(f);
	return 0;
}

int lin(char *str, char *sub)
{
	int sub_len = strlen(sub);

	for(int i = 0; str[i + sub_len - 1] != '\0'; i++) {
		for(int j = 0; j < sub_len && str[i+j] == sub[j]; j++) {
			if(j == sub_len-1)
				return i;
		}
	}

	return -1;
}

int bm(char *str, char *sub)
{
	int sub_len = strlen(sub);

	// preprocessing bad match table
	int bmt[256];
	for(int i = 0; i < 256; i++)
		bmt[i] = sub_len;
	for(int i = 0; i < sub_len-1; i++)
		bmt[sub[i]] = sub_len - 1 - i;

	// actual search
	for(int i = 0; str[i + sub_len - 1] != '\0'; i += bmt[str[i + sub_len - 1]]) {
		for(int j = sub_len-1; j >= 0 && str[i+j] == sub[j]; j--) {
			if(j == 0)
				return i;
		}
	}

	return -1;
}

int kmp(char *str, char *sub)
{
	int sub_len = strlen(sub);
	int *lps = (int*)malloc(sub_len * sizeof(int)); // largest proper suffix

	lps[0] = 0;
	for(int i = 1, j = 0; i < sub_len; i++) {
		while (sub[i] != sub[j] && j != 0)
			j = lps[j-1];
		if(sub[i] == sub[j])
			j++;
		lps[i] = j;
	}

	for(int i = 0, j = 0; str[i] != '\0'; i++) {
		while(str[i] != sub[j] && j != 0)
			j = lps[j-1];
		if(str[i] == sub[j])
			j++;
		if(j == sub_len)
			return i-j+1;
	}

	return -1;
}

int kr(char *str, char *sub)
{
	int sub_len = strlen(sub), sub_hash = 0, str_hash = 0;

	for(int i = 0; i < sub_len; i++) {
		sub_hash += sub[i];
		str_hash += str[i];
	}

	for(int i = sub_len; str[i] != '\0'; i++) {
		for(int j = 0; sub_hash == str_hash; j++)
			if(j == sub_len)
				return i - sub_len;
		str_hash = str_hash - str[i-1] + str[i];
	}

	return -1;
}

