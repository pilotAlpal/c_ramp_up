#ifndef TEMP_FILE_EXAMPLE
#define TEMP_FILE_EXAMPLE

#include <stddef.h>

typedef int temp_file_handle;
void print_usage(char* prog_name, int exit_code);
temp_file_handle write_temp_file_mkstemp(char* text_2_write, size_t length);
temp_file_handle write_temp_file_tmpfile(char* text_2_write, size_t length);
char* read_temp_file(temp_file_handle temp_file, size_t *length);
temp_file_handle (*w_temp_f)(char*, size_t);
char* (*r_temp_f)(temp_file_handle, size_t*);

#endif

