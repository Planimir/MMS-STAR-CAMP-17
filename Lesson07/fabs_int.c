#include <stdio.h>
#include <stdint.h>

int main() {

    double a; // 64 bits
    scanf("%lf", &a);

    // взимаме това, което се пази на адреса на а и го реинтрепетираме в long.

    // въпроса е: това е адрес сочещ към double, а искаме да е към uint64_t, затова го cast-ваме.

    // &a взима адреса на а, (uint64_t*) взима битовете и който бит от uint64_t съответсва с тях, ги взима.
    // не правим статично кастване 

    // Искаме да вземем побитовото представяне  на "а" и него да запазим в uint64_t.
    uint64_t b = *(uint64_t*)&a;
    b &= ~(1ULL << 63); // b = b & 1ULL << 63

    // cast-ваме като указател към double, взимащ стойността на uint64_t b.
    a = *(double*)&b;
    printf("%lf", a);


    return 0;
}