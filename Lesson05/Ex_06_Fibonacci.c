#include<stdio.h>    

void fibonacciSeries(int n1, int n2) {
    int n3;
    int i;
    int number;

    printf("Enter the number of elements:");    
    scanf("%d",&number);    
    printf("\n%d %d",n1,n2);//printing 0 and 1 

    for(i=2;i<number;++i) {    
        n3=n1+n2;    
        printf(" %d",n3);    
        n1=n2;    
        n2=n3;    
    } 

}

// un-comment line 39 to 45 to see how it works.
void fibonacciSeriesRecursion(int n){    
    static int n1=0,n2=1,n3;    
    if(n>0){    
         n3 = n1 + n2;    
         n1 = n2;    
         n2 = n3;    
         printf("%d ",n3);    
         fibonacciSeriesRecursion(n-1);    
    }    

int main() { 

    int n1=0;
    int n2=1;

    fibonacciSeries(n1, n2);

    // Fibonacci Series Recursion.
    // int n;    
    // printf("Enter the number of elements: ");    
    // scanf("%d",&n);    
    // printf("Fibonacci Series: ");    
    // printf("%d %d ",0,1);    
    // printFibonacci(n-2);//n-2 because 2 numbers are already printed  



    return 0;  
 }