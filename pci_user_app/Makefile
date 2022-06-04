pci_app: pci_app.o
	gcc $(CFLAGS) -o pci_app pci_app.o -lpci
pci_app.o: pci_app.c
	gcc $(CFLAGS) -o pci_app.o -c pci_app.c
clean:
	rm -f *.o pci_app
