#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point {
    double x;
    double y;
} P;

double distance(P p1, P p2);

int main(int argc, char* argv[]) {
    // your existing code here...

    for(size_t i = 0; i < N; i++) {
        printf("%lf %lf\n", (*(points + i)).x, (*(points + i)).y);
    }

    // compute and print distances
    for(size_t i = 0; i < N; i++) {
        for(size_t j = i+1; j < N; j++) {
            double dist = distance(points[i], points[j]);
            printf("Distance between point %lu (%lf, %lf) and point %lu (%lf, %lf) is %lf\n",
                   i, points[i].x, points[i].y, j, points[j].x, points[j].y, dist);
        }
    }

    return 0;
}

double distance(P p1, P p2) {
    double dX = p1.x - p2.x,
    dY = p1.y - p2.y;
    return sqrt(dX*dX + dY*dY);   
}
