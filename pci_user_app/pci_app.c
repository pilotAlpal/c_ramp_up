#include <pci/pci.h>
#include <stdio.h>

void print_all_devices(struct pci_access *pci_a) {
    struct pci_dev* device = pci_a->devices;
    char n_buff[1024], c_buff[1024], v_buff[1024], *d_name, *d_class, *d_vendor;
    int flags = PCI_FILL_IDENT |  PCI_FILL_CLASS;
    while (device != NULL) {
        pci_fill_info(device, flags);
        printf("%02x:%02x:%d\t", device->bus, device->dev, device->func);
        d_name = pci_lookup_name(pci_a, n_buff, sizeof n_buff, PCI_LOOKUP_DEVICE, device->vendor_id, device->device_id);
        d_class = pci_lookup_name(pci_a, c_buff, sizeof c_buff, PCI_LOOKUP_CLASS, device->device_class);
        d_vendor = pci_lookup_name(pci_a, v_buff, sizeof v_buff, PCI_LOOKUP_VENDOR, device->vendor_id);

        printf("%s: %s %s\n", d_class, d_vendor, d_name);
        device = device->next;
    }
}

int main()
{
    struct pci_access *pacc;
    pacc = pci_alloc();
    pci_init(pacc);
    pci_scan_bus(pacc);
    print_all_devices(pacc);
    pci_cleanup(pacc);
    return 0;
}