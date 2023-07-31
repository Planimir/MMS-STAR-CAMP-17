#include <stdio.h>
#include <stdint.h>
#include <string>

uint64_t sumDigits(uint64_t a);

int atoi_reverse(char* str);

int main() {

    uint64_t a;

    scanf("%lu", &a);

    uint64_t sum = 0, a_temp = a;

    while(a_temp) {
        sum += a_temp % 10;
        a_temp /= 10;
    } 
    printf("%lu", sum);

    sumDigits(12345);

    char str1[10] = "1234",
    str2[10];

    reverse(str1, str2);
    

    return 0;
 }


//sumDigits(12345) = sumDigits(12345/10) + 12345 % 10;
 uint64_t sumDigits(uint64_t a) {

    if(a < 10) {
        return a;
    }

    return sumDigits(a / 10) + a % 10;
 }


    /*
    
        str    1234
        (1 * 10 + 2) * 10 + 3) * 10 + 4
        str_rev 4321
        atoi_rev('4321') = 4 + 10 * atoi('321')
        atoi_rev('321') = 3 + 10 * atoi('21')
        atoi_rev('21') = 2 + 10 * atoi('1')
        atoi_rev('1') = 1 + 10 * atoi('')
        atoi_rev('') = 0
    
    */
 int atoi_reverse(const char * const str_rev) {

    // '2' - 48 == 2
    // '9' - 48 == 2
    // *str_rev == 0 is the same as just leaving *str_rev
    if(*str_rev == '\0') { // or if *str is the terminating 0 - '\0'
        return 0;
    }

    return (*str_rev - '0') + atoi_rev(str_rev + 1)*10;


 }

 int atoi(char *str) {

    return atoi(str_rev);
    
 }

void reverse(const char *str1, char *str2) {

    str2 += strlen(str1);
    *str2 = '\0';
    while(*str1) {
        *str2-- = *str1;
    }


}