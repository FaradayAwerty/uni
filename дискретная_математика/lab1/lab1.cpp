#include <iostream>

#define TEMPLATE_SIZE 5

int main()
{
	int word_template[TEMPLATE_SIZE] = {10, 20, 30, 40, 50};
	int word[TEMPLATE_SIZE] = {0, 0, 0, 0, 0};

	int n = 5123; // print 5123 word  (counting with zero)
	
	for(int i = TEMPLATE_SIZE-1; i >= 0; i--) {
		word[i] = n % word_template[i];
		n /= word_template[i];
	}

	// print found word
	for(int i = 0; i < TEMPLATE_SIZE; i++)
		std::cout << word[i] << ' ';
	std::cout << std::endl;


	// fint the number of new word {0, 0, 2, 22, 23}
	int new_word[TEMPLATE_SIZE] = {0, 0, 2, 22, 23};
	int m = 0;
	int p = 1;
	for(int i = TEMPLATE_SIZE-1; i >= 0; i--) {
		m += p*new_word[i];
		p *= word_template[i];
	}
	std::cout << m << std::endl;

	return 0;
}

