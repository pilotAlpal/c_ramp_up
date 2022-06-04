#include <stdio.h>

int main()
{
    int v = 32;
    while (v < 256) {
            printf("char %c, ascii %d\n", v, v);
            v++;
    }
    return 0;
}
