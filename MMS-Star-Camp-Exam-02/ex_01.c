#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*

    gcc ex_01.c -o ex01 
    
    ./ex01 123456789 

*/

char *encode_string(char *strArr) {

    int i = 0;
                    
    char *symbols = "!#/~=‘\\>.,"; 
                    
    char *letters = "ABCDEFGHIJ";


    int len = strlen(strArr);
    char *newStrArr = (char*)malloc(len + 1); 

    for(i = 0; i < len; i++) {
        int digit = strArr[i] - '0';
        if(i % 2 == 0) {
            newStrArr[i] = letters[digit];
        } else {
            newStrArr[i] = symbols[digit];
        }

    }

    newStrArr[len] = '\0';
    return newStrArr;

}

int main(int argc, char* argv[]) {
    char input[501];
    printf("\nPlease enter numbers to encode: ");
    scanf("%500s", input);

    char *encoded = encode_string(input);
    printf("-------------------\nEven index : ABCDEFGHIJ\nOdd index: !#/~=‘\\>.,\n-------------------");
    printf("\nEncoded numbers to a string: %s\n", encoded);

    free(encoded);
    return 0;
}


/*

ЗАДАЧА 1 - СИМВОЛНИ НИЗОВЕ : 

От стандартния вход се въвежда цяло положително число (което има най-много 500 цифри). Напишете функция, която кодира низа и връща нов символен низ, за който е заделена динамична памет. Кодирането се случва по следния начин:
Ако една цифра е на четна позиция, тя се замества със съответстващата главна латинска буква. Например:
0 се замества с A 
1 се замества с B
2 се замества с C и т.н.
Ако една цифра е на нечетна позиция, тя се замества със символ, както е зададено в долната таблица:
Цифра
Символ

0 !
1 #
2 /
3 ~
4 =
5 ‘
6 \
7 >
8 .
9 ,

Погрижете се за освобождаването на динамично заделената памет.
Примерен вход:
10296126782646987676234
Примерен изход:
B!C,G#C\H.C\E\J.H\H\C~E


*/