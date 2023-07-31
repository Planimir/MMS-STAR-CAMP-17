#include <stdio.h>

int main(int argc,char* argv[]) {

    unsigned short A;
    unsigned short B;

    printf("Enter operand A /from 0 to 100/ : \n");
    scanf("%hu", &A);

    printf("Enter operand B /from 0 to 100/ : \n");
    scanf("%hu", &B);
    printf("\nOperand A is : %d", A);
    printf("\nOperand B is : %d", B);

    // Bitwise AND "&"

    printf("\nA: | %hu |, B:  | %hu |, [ %hu ]\n", A, B, A & B);
    
    // Bitwise OR "|"
    printf("\nA: | %hu |, B:  | %hu |, [ %hu ]\n", A, B, A | B);

    // Bitwise XOR "^"
    printf("\nA: | %hu |, B:  | %hu |, [ %hu ]\n", A, B, A ^ B);

    // Bitwise NOT "~" A
    printf("\nA: | %hu |, [ %hu ]\n", A, ~A);

    // Bitwise NOT "~" B
    printf("\nA: | %hu |, [ %hu ]\n", B, ~B);

    // Bitwise LEFT SHIFT A "<<"
    printf("\nA: | %hu |, [ %hu ]\n", A, A << 1);

    // Bitwise RIGHT SHIFT A ">>"
    printf("\nA: | %hu |, [ %hu ]\n", A, A >> 1);

    // Bitwise LEFT SHIFT B "<<"
    printf("\nA: | %hu |, [ %hu ]\n", B, B << 1);

    // Bitwise RIGHT SHIFT B ">>"
    printf("\nA: | %hu |, [ %hu ]\n", B, B >> 1);


}