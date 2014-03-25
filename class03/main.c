/*
 * Strings Manipulation
 *
 *
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	// char hello[] = {'H', 'e', 'l', 'l', 'o', '\0'};
	// char hello[] = "Hello";
    
    char nome[] = "Fulano";
    printf("%s\n", nome);
    printf("strlen: %d\n", strlen(nome));
    
	return 0;
}
