#include <stdio.h>
//factorial



int factorial();
int main() {


}

// n
// n*(n - 1 ) * (n - 2)...
int factorial(int n) {

    if(n == 0) {
        return 1;
    }

    return n * fact(n - 1);

    /*
    fact(5) = 5 * fact(4)
    fact(4) = 4 * fact(3)
    fact(3) = 3 * fact(2)
    fact(2) = 2 * fact(1)
    fact(1) = 1 * fact(0)
    fact(0) = 1
    fact(1) = 1 * 1
    fact(2) = 2 * 2
    fact(3) = 3 * 2
    fact(4) = 4 * 6
    fact(5) = 5 * 24
    */
}