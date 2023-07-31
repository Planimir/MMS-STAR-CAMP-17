#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// не можем да променяме адреса, на който сочи този указател.
char* toUpper(const char *ptr) {

    size_t i = 0;
    char *new_str = malloc(sizeof(char)*strlen(ptr));

    while(ptr[i] = '\0') { // or (*(ptr + i) != '\0')
                                              // check the ASCII Table
        if(ptr[i] >= 'a'  && ptr[i] <= 'z') { // ptr[i] >= 97  && ptr[i] <= 122 == ptr[i] >= 'a'  && ptr[i] <= 'z'
            *(new_str + i)  = ptr[i] - ('a' - 'A'); // ('a' - 'A') == - 32 ( 97 - 65 )

        } else {
            new_str[i] = ptr[i];

        }
        i++;
    }
    new_str[i] = '\0';
    return new_str;

}

int main() {

    char* str = toUpper("Hello World!!!;./");
    printf("%s\n", str);
    free(str);
    return 0;   
    

}