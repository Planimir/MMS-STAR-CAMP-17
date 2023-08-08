#include "product.h"
#include <stdlib.h>
#include <time.h>

const char *product_names[] = { "Apple", "Orange", "Banana", "Cherry", "Peach", "Mango", "Blueberry" };

#define NUM_PRODUCTS 40

int main() {
    srand(time(NULL));

    struct Product products[NUM_PRODUCTS];

    for (unsigned int i = 0; i < NUM_PRODUCTS; ++i) {
        products[i].old_price = 4.99 + (rand() % 9561) / 100.0;
        products[i].new_price = 4.99 + (rand() % 9561) / 100.0;
        products[i].id = i + 1;
        products[i].product_type = 'A' + (rand() % 4);
        strncpy(products[i].product_name, product_names[rand() % (sizeof(product_names) / sizeof(product_names[0]))], PRODUCT_NAME_SIZE - 1);

        print_product(&products[i]);
    }

    qsort(products, NUM_PRODUCTS, sizeof(struct Product), compare_products);

    printf("\nSorted products:\n\n");
    for (unsigned int i = 0; i < NUM_PRODUCTS; ++i) {
        print_product(&products[i]);
    }

    write_products_to_file(products, NUM_PRODUCTS, "products.bin");

    return 0;
}
