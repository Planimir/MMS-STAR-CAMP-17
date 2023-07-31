#include <stdio.h>

/*

ДА СЕ НАПИШЕ ПРОГРАМА, КОЯТО ПРИЕМА ДВА ПАРАМЕТЬРА :
ВЪЗРАСТ ЧЯЛО ЧИСЛО
ТЕГЛО С ДРОБНА ЧАСТ (ПЛАВАЩА ЗАПЕТАЯ)
1 ДА СЕ ПРОВЕРИ ВЪЗРАСТТА НА ЛИЦЕТО И АКО ТЯ Е ПО 18 ГОДИНИ ДА ОТГОВАРЯ ЧЕ Е НЕПЬЛНОЛЕТЕН И НЕ МОЖЕ ДА ДАВА КРЪВ ИЛИ ДА ГЛАСУВА
2 АКО Е НАД 18 ГОД И ПОД 100 КГ - МОЖЕ ДА ДАВА КРЪВ

*/

int main(int argc, char* argv[]) {

    int age;
    float weight;

    printf("\nEnter ur age : \n");
    scanf("%d", &age);
    printf("Enter ut weight: \n");
    scanf("%f", &weight);

    if ( age < 18 ) {
        
        printf("This person cannot vote and donate blood.");

    } else if (weight < 100) {

        printf("This person can donate blood.");


    } else{
        
        printf("This person can vote.");
        }      


 }
