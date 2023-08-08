#include "product.h"

#define NUM_PRODUCTS 40

int main() {
    FILE *file = fopen("products.bin", "rb");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    struct Product products[NUM_PRODUCTS];
    fread(products, sizeof(struct Product), NUM_PRODUCTS, file);

    for (unsigned int i = 0; i < NUM_PRODUCTS; ++i) {
        print_product(&products[i]);
    }

    fclose(file);

    return 0;
}
