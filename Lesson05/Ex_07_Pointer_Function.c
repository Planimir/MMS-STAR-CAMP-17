#include <stdio.h>
// A normal funcction with an int parameter
// and void return type
void func(int a)
{
    printf("Value of a is %d\n", a);
}
  
int main()
{
    // Setting up the pointer func_ptr to point to the funcction
    void (*func_ptr)(int) = &func;
  
    /* The above line is equivalent of following two
       void (*func_ptr)(int);
       func_ptr = &func; 
    */
  
    // Invoking func() using func_ptr
    (*func_ptr)(10);
  
    return 0;
}