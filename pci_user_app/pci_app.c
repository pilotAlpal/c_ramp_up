#include <stdlib.h>
#include <getopt.h>
#include <pci/pci.h>
#include <stdio.h>

u8 print_header_type = 0;

void print_usage(char* prog_name, int exit_code) {
    printf("Usage: %s [options]\n", prog_name);
    printf("\t-h --help\tDisplay this usage info\n");
    printf("\t-t --header_types\tPrint header types\n");
    exit(exit_code);

}

void print_all_devices(struct pci_access *pci_a) {
    struct pci_dev* device = pci_a->devices;
    char n_buff[1024], c_buff[1024], v_buff[1024], *d_name, *d_class, *d_vendor;
    int flags = PCI_FILL_IDENT |  PCI_FILL_CLASS;
    u8 h_type;
    while (device != NULL) {
        pci_fill_info(device, flags);
        printf("%02x:%02x:%d\t", device->bus, device->dev, device->func);
        d_name = pci_lookup_name(pci_a, n_buff, sizeof n_buff, PCI_LOOKUP_DEVICE, device->vendor_id, device->device_id);
        d_class = pci_lookup_name(pci_a, c_buff, sizeof c_buff, PCI_LOOKUP_CLASS, device->device_class);
        d_vendor = pci_lookup_name(pci_a, v_buff, sizeof v_buff, PCI_LOOKUP_VENDOR, device->vendor_id);

        printf("%s: %s %s\n", d_class, d_vendor, d_name);
        if (print_header_type) {
            h_type = pci_read_byte(device, PCI_HEADER_TYPE);
            printf("\tHeader type: 0x%x\n", h_type);
        }

        device = device->next;
    }
}

int main(int argc, char** argv)
{
    int next_opt;
    const char* const short_opts = "ht";
    const struct option long_opts[] = {
        {"help", 0, NULL, 'h'},
        {"header_types", 0, NULL, 't'},
        {NULL, 0, NULL, 0}
    };

    do {
        next_opt = getopt_long(argc, argv, short_opts, long_opts, NULL);
        switch(next_opt) {
            case 'h':
                print_usage(argv[0], 0);
            case 't':
                print_header_type = 1;
                break;
            case '?':
                print_usage(argv[0], 1);
            case -1:
                break;
            default:
                abort();
                
        }
    }
    while (next_opt != -1);

    struct pci_access *pacc;
    pacc = pci_alloc();
    pci_init(pacc);
    pci_scan_bus(pacc);
    print_all_devices(pacc);
    pci_cleanup(pacc);
    return 0;
}

