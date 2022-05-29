print_from_threads: print_from_threads.o
	gcc $(CFLAGS) -o print_from_threads print_from_threads.o -lpthread
print_from_threads.o: print_from_threads.c
	gcc $(CFLAGS) -o print_from_threads.o -c print_from_threads.c
clean:
	rm -f *.o print_from_threads

