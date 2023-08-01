#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/*

    gcc ex_02.c -o ex02 
    
    ./ex02 <choice>

*/

#define ARRAY_SIZE 10

typedef struct Car {
    char model[21];
    uint8_t maxspeed;
    double price;
} Car;


int compareByModelAsc(const void* a, const void* b) {
    Car* carA = (Car*) a;
    Car* carB = (Car*) b;
    return strcmp(carA->model, carB->model);
}

int compareByModelDesc(const void* a, const void* b) {
    return compareByModelAsc(b, a);
}

int compareByMaxspeedAsc(const void* a, const void* b) {
    Car* carA = (Car*) a;
    Car* carB = (Car*) b;
    return (int)carA->maxspeed - (int)carB->maxspeed;
}

int compareByMaxspeedDesc(const void* a, const void* b) {
    return compareByMaxspeedAsc(b, a);
}

int compareByPriceAsc(const void* a, const void* b) {
    Car* carA = (Car*) a;
    Car* carB = (Car*) b;
    return carA->price - carB->price > 0 ? 1 : -1;
}

int compareByPriceDesc(const void* a, const void* b) {
    return compareByPriceAsc(b, a);
}

int (*getComparator(int n))(const void*, const void*) {
    switch(n) {
        case 1: 
        printf("\nCompare by model ASC: \n");
        return compareByModelAsc;

        case 2:
        printf("\nCompare by model DSC: \n");
        return compareByModelDesc;

        case 3:
        printf("\nCompare by max speed  ASC: \n");
        return compareByMaxspeedAsc;

        case 4:
        printf("\nCompare by max speed DSC: \n");
        return compareByMaxspeedDesc;

        case 5:
        printf("\nCompare by price ASC \n");
        return compareByPriceAsc;

        case 6:
        printf("\nCompare by price DSC: \n");
        return compareByPriceDesc;

        default:
        return NULL;
    }
}

void printCarInfo(Car car) {
    printf("Model: %s, Maxspeed: %d, Price: %.2f\n", car.model, car.maxspeed, car.price);
}

int main() {

    Car cars[ARRAY_SIZE] = {
        {"Audi", 220, 30000.00},
        {"BMW", 240, 40000.00},
        {"Cadillac", 200, 25000.00},
        {"Mazda", 103, 10000.00},
        {"Kia", 150, 35000.00},
        {"Hyundai", 130, 22000.00},
        {"Maserati", 240, 80000.00},
        {"Ram", 250, 90000.00},
        {"KN", 210, 50000.00},
        {"Mini-Cooper", 120, 15000.00}
 
    };

    int option;
    printf("Choose : \n1. Compare by model ASC\n2. Compare by model DSC\n3. Compare by max speed ASC\n4. Compare by max speed DSC\n5. Compare by price ASC\n6. Compare by price DSC\nChoice :");
    scanf("%d", &option);

    int (*comparator)(const void*, const void*) = getComparator(option);
    if(comparator == NULL) {
        printf("Invalid option\n");
        return -1;
    }

    qsort(cars, ARRAY_SIZE, sizeof(Car), comparator);
    for(int i = 0; i < ARRAY_SIZE; i++) {
        printCarInfo(cars[i]);
    }

    return 0;
}

/*

ЗАДАЧА 2 - СОРТИРАНЕ :

Направете структура Car, за която да се съхраняват следните данни:
model - C-string - max 20 symbols
maxspeed - uint8_t
price - double

Да се направят 6 функции, с помощта на които да се сортира масив от автомобили (сравняващи функции каквито се подават в стандартната qsort()): 
Сравнение по марка - възходящ лексикографски ред;
Сравнение по марка - низходящ лексикографски ред;
Сравнение по максимална скорост - възходящ ред;
Сравнение по максимална скорост - низходящ ред;
Сравнение по цена - възходящ ред.
Сравнение по цена - низходящ ред.

Да се направи функция, която да връща сравняваща функция, от тези които дефинирахме по-горе.
int (*getComparator(int n))(const void*, const void*);
Номерът на функцията n, да е между 1 и 6. При число различно от това, да се върне нулев указател.

Да се създаде масив от 10 автомобила. Да се запълни с произволни стойности:
Марка - [A-Z][a-z]{4,10}
Максимална скорост - 100 - 300
Цена - 1000.00 - 100 000.00

Потребител да въведе от стандартния вход цяло число между 1 и 6, с което да избира начин на сортиране на масива от автомобили, като използва функцията getComparator().
Сортирането да се извърши със стандартната функция qsort().
Да се изведе сортираният масив в подходящ формат.

*/