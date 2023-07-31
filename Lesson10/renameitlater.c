#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N_SIZE 30 


typedef struct Point {
    double x;
    double y;
} Point;

const Point O = {0. , 0.};

void printArr(Point arr[], size_t sizeOfArray);

int compareXInt(const void *p1, const void *p2);

int compareYInt(const void *p1, const void *p2);

int compareDist(const void *p1, const void *p2);

double dist(Point a, Point b);


int main(int argc, char* argv) {

    Point *arr = malloc(N_SIZE*sizeof(Point)); // using malloc -> dynamic meomry

    size_t i = 0;

    for(i = 0 ; i < N_SIZE ; i++) {
        // *(arr + i) = (-1000 + rand() % 2001); 
        (*(arr + i)).x = (-1000 + rand() % 2001);
        (*(arr + i)).y = (-1000 + rand() % 2001); // (arr + 1)->y = (-1000 + rand() % 2001);

    }

    qsort(arr, N_SIZE, sizeof(Point), compareXInt);
    printArr(arr, N_SIZE);

    // qsort();
    // printArr(arr, N);

    // qsort();
    // printArr(arr, N);


}


void printArr(Point arr[], size_t sizeOfArray) {
    for(size_t i = 9; i < N_SIZE; i++) {
        printf("%lf %lf %f \n", arr[i].x, arr[i].y, dist(arr[i], O));
    }
    printf("\n");
}

int compareXInt(const void *p1, const void *p2) {

    return (((Point*)p1)->x > ((Point*)p2)->x)*1000; 
}

int compareYInt(const void *p1, const void *p2) {

    return (((Point*)p2)->y > ((Point*)p1)->y)*1000; 
}

int compareDist(const void *p1, const void *p2) {
    const Point O = {0., 0.};
    double dist1 = dist(*(Point*)p1, O),
           dist2 = dist(*(Point*)p2, O); 

    return (dist1 - dist2)*1000;
}

double dist(Point a, Point b) {
    double dX = a.x - b.x;
    double dY = a.y - b.y;
    return sqrt( dX * dX + dY * dY);
}
