#include <stdio.h>
#include <math.h>


int main(int argc, char* argv[]) {

// integer types
char c;
short s;
int i;
long l;
long long ll;
// floating-point types
double d;
float f;

// Можем също да използваме sizeof оператора, за да определим размера на всеки тип в байтове:
printf("Size of char:      ( %lu ) - bytes\n", sizeof(c));
printf("Size of short:     ( %lu ) - bytes\n", sizeof(s)); 
printf("Size of int:       ( %lu ) - bytes\n", sizeof(i));
printf("Size of long:      ( %lu ) - bytes\n", sizeof(l)); 
printf("Size of long long: ( %lu ) - bytes\n", sizeof(ll)); 
printf("Size of float:     ( %lu ) - bytes\n", sizeof(f)); 
printf("Size of double:    ( %lu ) - bytes\n", sizeof(d));

return 0;
}

 