#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include "temp_file_example.h"

temp_file_handle (*w_temp_f)(char*, size_t);
char* (*r_temp_f)(temp_file_handle, size_t*) = &read_temp_file;

temp_file_handle write_temp_file_mkstemp(char* buffer, size_t length)
{
    assert(buffer != NULL);
    printf("Write temp file mkstemp\n");
    char temp_filename[] = "/tmp/temp_file.XXXXXX";
    int fd = mkstemp(temp_filename);
    unlink(temp_filename);
    write(fd, &length, sizeof(length));
    write(fd, buffer, length);
    return fd;
}

temp_file_handle write_temp_file_tmpfile(char* buffer, size_t length)
{
    printf("Write temp file tmpfile\n");
    FILE* tmp_file = tmpfile();
    fwrite(&length, sizeof(size_t), 1, tmp_file);
    size_t bytes_w = fwrite(buffer, sizeof(char), length, tmp_file);
    int fd0 = dup(fileno(tmp_file));
    fclose(tmp_file);
    return fd0;
}

char* read_temp_file(temp_file_handle temp_file, size_t* length)
{
    assert(length != NULL);
    int fd = temp_file;
    lseek(fd, 0, SEEK_SET);
    size_t bytes_read;
    int error_code;
    printf("Reading text size from file..\n");
    bytes_read = read(fd, length, sizeof(size_t));
    if (bytes_read == -1){
        error_code = errno;
        printf("Error reading size: %s\n", strerror(error_code));
        exit(error_code);
    }
    else {
        printf("Text size is %zu\n", *length);
        char* buffer = malloc(sizeof *buffer * *length);
        printf("Reading text (%zu bytes) from file..\n", *length);
        bytes_read = read(fd, buffer, *length);
        error_code = errno;
        close(fd);
        if (bytes_read == -1){
            printf("Error reading text: %s\n", strerror(error_code));
            exit(error_code);
        }
        return buffer;
    }
}

void print_usage(char* prog_name, int exit_code)
{
    assert(prog_name != NULL);
    printf("Usage: %s <text_2_write_and_read>\n", prog_name);
    exit(exit_code);
}

void write_and_read_temp(char* text)
{
    size_t *b_read =  malloc(sizeof *b_read);
    temp_file_handle tmpf_h = (*w_temp_f)(text, strlen(text));
    char* text_read = (*r_temp_f)(tmpf_h, b_read);
    printf("%zu bytes read\n", *b_read);
    printf("File content: %s\n", text_read);
    free(text_read);
    free(b_read);
}

int main(int argc, char** argv)
{
    if (argc != 2)
        print_usage(argv[0], 1);
    r_temp_f = &read_temp_file;
    w_temp_f = &write_temp_file_mkstemp;
    write_and_read_temp(argv[1]);

    w_temp_f = &write_temp_file_tmpfile;
    write_and_read_temp(argv[1]);

    return 0;
}

