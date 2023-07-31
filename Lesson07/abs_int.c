#include <stdio.h>
#include <stdint.h>

void printNum(int64_t value);


int main(int argc, char* argv) {

    int64_t a;
    scanf("%lu", &a);
    int sign_bit_value = (!!(a&(1ULL << 63)));

    // printf("%lu\n", (~ (a - 1) ) * sign_bit_value);
    // printf("%lu\n", a * !sign_bit_value);

    printf("%lu\n", a * !sign_bit_value + ~(a-1) * sign_bit_value);

    /*
    unsigned char a = 25;
    1 + 8 + 16 = 25

    00011001

    а*(1 << 3)
    1 << 3 === 00001000

    a&(00001000)

    00001000
    ====
    00001000 

    
    */ 
    return 0; 


    // 64 битов sign integer искаме да направим операцията модул ( да обърнем знака )
    // - ако а беше -55, абс от а е 55;

}

void printNum(int64_t value) {
    for (int i = sizeof(char) * 15; i >= 0; i--)
        printf("%ld", (value & (1 << i)) >> i );
    putc('\n', stdout);
}

