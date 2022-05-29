#include <pthread.h>
#include <stdio.h>

struct char_print_params
{
    char character;
    int count;
};

void* char_print(void* params) {
    struct char_print_params* p = (struct char_print_params*) params;
    int i;
    for (i = 0; i < p->count; ++i) 
        fputc(p->character, stdout);
    return NULL;
}

int main()
{
    pthread_t th_id1, th_id2;
    struct char_print_params th_args1, th_args2;

    th_args1.character = 'x';
    th_args1.count = 1700;
    pthread_create(&th_id1, NULL, &char_print, &th_args1);

    th_args2.character = 'y';
    th_args2.count = 1400;
    pthread_create(&th_id2, NULL, &char_print, &th_args2);

    pthread_join(th_id1, NULL);
    pthread_join(th_id2, NULL);
    printf("z\n");

    return 0;
}
