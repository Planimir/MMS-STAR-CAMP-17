#include<stdio.h>
#include<limits.h>
typedef union A {
    unsigned int ui;    // 4 byte
    unsigned char bytes[4]; // 4 byte
} A;
// sizeof(A) == 4
void printBytes(A a) {
    for(size_t i = 0; i < 4; i++) {
        printf("%02x ", a.bytes[i]);
    }
    printf("\n");
}
// unsigned int i = UINT_MAX - 1
// BIG ENDIAN:      ff ff ff fe
//                  ^  ^  ^  ^
//address           1  2  3  4
// ========================>
// LITTLE ENDIAN:   fe ff ff ff
//                  ^  ^  ^  ^
//address           1  2  3  4
int main() {
    A u1;
    u1.ui = 254;
    printBytes(u1);
    u1.ui = UINT_MAX - 2;
    printBytes(u1);
    u1.ui = 9;
    printBytes(u1);
    return 0;
}