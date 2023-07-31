#include<stdio.h>
#include<stdlib.h>
int main() {
    void *p = malloc(sizeof(double));
    double *d_p = p;
    *d_p = 12.5;
    printf("%lf\n", *d_p);
    free(d_p);
 
    void *p2 = calloc(sizeof(double), sizeof(double));
    double *d_p2 = p2;
    printf("%lf\n", *d_p2);
    free(p2);

    void *p3 = malloc(sizeof(int)*100);
    int *p_i = p3;
    p_i[0] = 123;
    p_i[1] = 123;
    p_i[2] = 123;
    void *p4 = realloc(p3, sizeof(int)*50);
    int *p_i2 = p4;
    printf("%d %d %d\n", p_i2[0], p_i2[1], p_i2[2]);
    free(p4);

    int *p_6 = (int*)malloc(sizeof(int));
}