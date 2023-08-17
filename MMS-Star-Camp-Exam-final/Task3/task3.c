#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

typedef struct RowData {

    int row;
    int *nums;
    int m; 
    double result;

} RowData;

void *compute_mean(void *arg);

int main() {

    int n, m;

    scanf("%d %d", &n, &m);

    RowData rows[n];

    int i, j;

    for(i = 0; i < n; i++) {
        char _tmp[4];
        scanf("%s %d", _tmp, &(rows[i].row));

        rows[i].nums = (int *) malloc(m * sizeof(int));
        rows[i].m = m;

        for(j = 0; j < m; j++) {
            scanf("%d", &(rows[i].nums[j]));
        }

    }

    char filename[100];
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if(file) {

        printf("Error: File already exists.\n");
        fclose(file);

        return 1;
    }

    pthread_t threads[n];

    for (int i = 0; i < n; i++) {
        pthread_create(&threads[i], NULL, compute_mean, &rows[i]);
    }
    for (int i = 0; i < n; i++) {
        pthread_join(threads[i], NULL);
    }

    file = fopen(filename, "w");
    for (int i = 0; i < n; i++) {
        fprintf(file, "ROW %d %.3lf\n", rows[i].row, rows[i].result);
        free(rows[i].nums);
    }
    fclose(file);
    
    return 0;
}

void *compute_mean(void *arg) {

    RowData *data = (RowData *) arg;
    int sum = 0;
    for (int i = 0; i < data->m; i++) {
        sum += data->nums[i];
    }

    data->result = (double)sum / data->m;

    return NULL;
}

/*
    gcc task3.c -o task3 -lpthread -Wall -Wextra

    ./task3 <input>

    5 6
    ROW 1 21 14 31 -51 33 1
    ROW 2 41 56 74 -21 42 -52
    ROW 3 51 61 17 37 97 39
    ROW 4 19 -1 85 -9 51 2
    ROW 5 71 26 43 36 22 99
    file1


*/
