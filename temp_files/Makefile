temp_file_example: temp_file_example.o
	gcc $(cflags) -o temp_file_example temp_file_example.o temp_file_example.h

temp_file_example.o: temp_file_example.c temp_file_example.h
	gcc $(CFLAGS) -o temp_file_example.o -c temp_file_example.c

clean:
	rm -rf *.o temp_file_example
