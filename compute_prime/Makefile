compute_prime: compute_prime.o
	gcc $(CFLAGS) -o compute_prime compute_prime.o -lpthread
compute_prime.o: compute_prime.c
	gcc $(CFLAGS) -o compute_prime.o -c compute_prime.c
clean:
	rm -f *.o compute_prime
