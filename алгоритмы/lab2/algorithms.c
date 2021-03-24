#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define FILENAME "string.txt"

#define bool int
#define false 0
#define true 1

int lin(char *str, char *sub);

int main()
{
	FILE *f = fopen(FILENAME, "r");

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

		printf("%s %d, %s %d\n", str, str_len, sub, sub_len);
	}
	
	free(str);
	free(sub);
	fclose(f);
	return 0;
}

int lin(char *str, char *sub)
{
	int sub_len = strlen(sub);
	for(int i = 0; str[i + sub_len - 1] != '\0'; i++) {
		int j = 0;
		while(str[i+j] == sub[j])
			j++;
		if(j == sub_len)
			return i;
	}
	return -1;
}

