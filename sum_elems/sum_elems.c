#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int i = 1;
    int* sum = malloc(sizeof *sum);
    while (i < argc) {
        *sum += atoi(argv[i]);
        i++;
    }
    printf("sum is %d\n", *sum);
    free(sum);
    return 0;
}