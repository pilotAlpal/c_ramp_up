#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int i = 0;
    char* rev = malloc(sizeof *rev * strlen(argv[1]));
    while (i < strlen(argv[1]))
    {
        rev[strlen(argv[1]) - i - 1] = argv[1][i];
        i++;
    }
    printf("Reverse of %s is %s\n", argv[1], rev);
    free(rev);
    return 0;
}