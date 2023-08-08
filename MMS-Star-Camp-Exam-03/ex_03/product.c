#include "product.h"
#include <string.h>

void print_product(struct Product *product) {
    printf("Product ID: %u\n", product->id);
    printf("Product Name: %s\n", product->product_name);
    printf("Product Type: %c\n", product->product_type);
    printf("Old Price: %.2f\n", product->old_price);
    printf("New Price: %.2f\n", product->new_price);
    printf("Price Increase: %.2f\n\n", product->new_price - product->old_price);
}

void write_products_to_file(struct Product *products, size_t num_products, const char *file_name) {
    FILE *file = fopen(file_name, "wb");
    fwrite(products, sizeof(struct Product), num_products, file);
    fclose(file);
}

int compare_products(const void *a, const void *b) {
    struct Product *productA = (struct Product *)a;
    struct Product *productB = (struct Product *)b;

    double price_diff_A = productA->new_price - productA->old_price;
    double price_diff_B = productB->new_price - productB->old_price;

    if (price_diff_B - price_diff_A > 0.01) return 1;
    else if (price_diff_A - price_diff_B > 0.01) return -1;

    if (productB->product_type != productA->product_type) 
        return (productB->product_type - productA->product_type);

    int name_cmp = strcmp(productA->product_name, productB->product_name);
    if (name_cmp != 0) return name_cmp;

    return (productA->id - productB->id);
}
