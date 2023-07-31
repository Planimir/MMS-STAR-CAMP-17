#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point {
    double x;
    double y;
} P;

// Type of struct Point.
double distance(P p1, P p2);
int main(int argc, char* argv[]) {

    if(argc != 2) {
        fprintf(stderr, "Invalid command line arguments\n");
        return 1;
    }

    unsigned int N;
    if(sscanf(argv[1], "%u", &N) != 1) {
        fprintf(stderr, "Invalid command line arguments\n");
        return 1;
    }

    P points[N];
    printf("sizeof(P): %lu\n", sizeof(P));
    printf("sizeof(P): %lu\n", sizeof(points));

    for(size_t i = 0; i < N; i++) {
        points[i].x = (double)(rand()%1000)/1000;
        points[i].y = (double)(rand()%1000)/1000;
    }

    for(size_t i = 0; i < N; i++) {
        printf("%lf %lf\n", (*(points + i)).x, (*(points + i)).y);
    }

    // compute and print distances
for(size_t i = 0; i < N; i++) {
    for(size_t j = 1; j < N; j++) { // start from i+1
        printf("\n%lu %lu %lf", i, j, distance(points[i], points[j]));
    }
}




    return 0;
}


double distance(P p1, P p2) {
            // взимаме корен от двата 
    double dX = p1.x - p2.x,
    dY = p1.y - p2.y;
    return sqrt(dX*dX + dY*dY);   
}

// намери разстоянието между 2-те точки - 