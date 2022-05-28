sigchld: sigchld.o
	gcc $(CFLAGS) -o sigchld sigchld.o
sigchld.o: sigchld.c
	gcc $(CFLAGS) -o sigchld.o -c sigchld.c
clean:
	rm -f *.o sigchld
