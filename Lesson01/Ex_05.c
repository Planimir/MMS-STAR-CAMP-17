#include <stdio.h>
#define DEBUG

int main(int argc, char* argv[]) {

#ifdef DEBUG
printf("Debug mode is on\n");
#else
printf("Debug mode is off\n");
#endif

return 0;
}