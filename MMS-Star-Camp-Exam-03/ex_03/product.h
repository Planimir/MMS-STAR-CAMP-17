#ifndef PRODUCT_H
#define PRODUCT_H

#include <stdio.h>

#define PRODUCT_NAME_SIZE 64

struct Product {
    double old_price;
    double new_price;
    unsigned int id;
    char product_type;
    char product_name[PRODUCT_NAME_SIZE];
};

void print_product(struct Product *product);
void write_products_to_file(struct Product *products, size_t num_products, const char *file_name);
int compare_products(const void *a, const void *b);

#endif
