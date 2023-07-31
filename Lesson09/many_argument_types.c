#include<stdio.h>
typedef union A {
    char c;
    double d;
    int i;
} A;
// ########
// c
// d
// i
typedef struct Arg {
    A argVal; // 8 bytes
    int argType;   // 4bytes
    // 4 bytes
} Arg;
// ######## ####     ####
//  argVal   argType padding

typedef struct Arg_Bloated {
    char c;
    double d;
    int i;
    int argType;
} Arg_Bloated;
void print(Arg a) {
    if(a.argType == 0) {
        printf("%c\n", a.argVal.c);
    }
    if(a.argType == 1) {
        printf("%lf\n", a.argVal.d);
    }
    if(a.argType == 2) {
        printf("%d\n", a.argVal.i);
    }
}
int main() {
    Arg argChar;
    argChar.argType = 0;
    argChar.argVal.c = 'W';
    print(argChar);

    Arg argDouble;
    argDouble.argType = 1;
    argDouble.argVal.d = 3.14516;
    print(argDouble);

    Arg argInt;
    argInt.argType = 2;
    argInt.argVal.i = 1231512;
    print(argInt);
}