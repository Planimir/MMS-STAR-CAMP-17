#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*

    gcc ex_03.c -o ex03 
    
    ./ex03 10 12.5 0xff -21 55 0XA 3.14

*/

int main(int argc, char *argv[]) {

    double sum = 0.0;
    int i;
    for(i=1; i < argc; i++) {

        if(strchr(argv[i], '.')) {

            sum += strtof(argv[i], NULL);
        } else if(strstr(argv[i], "0x") || strstr(argv[i], "0X")) {

            int temp;
            sscanf(argv[i], "%x", &temp);
            sum += temp;
            
        } else {

            sum += atoi(argv[i]);
        }
    }

    printf("Sum is %.2lf\n", sum);
    return 0;
}

/*

Задача 3 - command line arguments


Напишете програма, която намира сумата на аргументите, подадени от командния ред.
Програмата може да приема 3 вида аргументи от командния ред:
целочислени аргументи в десетична бройна система, например 10, -21, 55.
числа с плаваща запетая, например 12.5, 3.14
Числа в шестнадесетична бройна система 0xff

Приемете, че:
Ако аргумент има точка в записа, то той е число с плаваща запетая
Ако аргумент започва със 0X или 0x, то той е число записано в шестнадесетична бройна система
В противен случай аргументът е цяло число, записано в десетична бройна система

Използвайте функциите от стандартната библиотека за да си улесните работата по обработването на аргументите от командния ред (напр. atoi, strtof, sscanf от string.h).
Примерно изпълнение:
$ ./sum_cli 10 12.5 0xff -21 55 0XA 3.14
Sum is 324.64

Пояснение: 
10 + 12.5 + 0xff(255) - 21 + 55 + 0XA(10) + 3.14 = 324.64


*/