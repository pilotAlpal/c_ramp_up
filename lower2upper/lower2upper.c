#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char** argv)
{
    char* upper = malloc(sizeof *upper * strlen(argv[1]));
    int i = 0;
    while (i < strlen(argv[1])) {
        upper[i] = toupper(argv[1][i]);
        i++;
    }
    printf("%s\n", upper);
    free(upper);
    return 0;
}
