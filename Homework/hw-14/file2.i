# 1 "file2.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "file2.c"
void swap(int* num1, int* num2)
{
    *num1 ^= *num2;
    *num2 ^= *num1;
    *num1 ^= *num2;
}
