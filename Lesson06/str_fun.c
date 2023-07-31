#include <stdio.h>
#include <string.h>

// strlen(str) - ne promenq simvolite na char-a, koito polzvame.
// strcat(sre, dest) - 
// strcpy(src, dest) -
// strcmp(strt, strd) - 

int strlen_(char *str) {

    int cnt = 0;
    
    while(str[cnt]) {
        cnt++;
    }
    return cnt;
}



// Coppies src in dest
void strcpy_(char *dest, char *src) {

    while(*src) {
        *(dest++) = *(src++);
    }

    *dest = '\0';
}

// Coppies symbols after 
void strcat_(char *dest, char *src) {
    dest += strlen_(dest);
    while(*src) {
        *(dest++) = *(src++);

    }
    *dest = '\0';

}

// Coppies symbols after 
void strcat_2(char *dest, char *src) {
    strcpy_(dest + strlen_(dest), src);
}

// while the chars are equal keep on going, but once they find \0 - stop.
void strcmp_(char *str1, char *str2) {  
    while( (*str1 == *str2) && (*str2) ) { // *str != "\0" == *str
        str1++; // goes from 0th index to 1st index... n index
        str2++;

        /* 
        lets say we have :
        
        str1: Helloooo\0qwe 
        str2: Helloooo\0qwe

        */

    }
}



int main(int argc, char* argv) {

    char a[20] = "Program";
    char b[20]={'P','r','o','g','r','a','m', '\0'};

    /*

    Technically returns the length of the char.
    
    */
    printf("String: %s\n", a);
    printf("Length of char a = | %lu | \n", strlen(a));
    // ... , strlen(a);
    printf("Length of char b = | %lu | \n", strlen(b));


    // -----------------------------------------------------------------------------------------

    char c[100] = "Hello ", d[] = "World!";

    // concatenates c and d
    // the resultant string is stored in c.

    printf("\nstrcat:\n");
    strcat(c, d);

    puts(c); // is now combined as Hello World, but used to be Hello.
    puts(d); // is World.

    // -----------------------------------------------------------------------------------------

    // char* strcpy(char* destination, const char* source);

    char e[20] = "C programming\n";
    char f[20];

    // copying e to f
    strcpy(f, e);

    printf("\nstrcpy:\n");
    puts(f); // C programming


    // -----------------------------------------------------------------------------------------

    // int strcmp (const char* g, const char* h);

    char g[] = "abcd", h[] = "abCd", i[] = "abcd";
    int result;

    // comparing strings g and h
    result = strcmp(g, h);
    printf("strcmp(g, h) = %d\n", result);

    // comparing strings g and i
    result = strcmp(g, i);
    printf("strcmp(g, i) = %d\n", result);




//  -----------------------------------------------------------------------------------------
                            // Campus teacher's explanation.
    


    int aa;
    const int *p = &a;
    // Pointer to const int ( cannot change value, but can change address)
    p++;

    // not allowed to change address, but allowed to change value at address.
    int * const p = &a;
    *p = 100; // allowed

    const int * const p = &a;
    // Cannot either change address, either value.
    return 0;
}

// int strlen(char *str); // returns the length of the char
// void strcpy(char *dest, char *src); // copies the src in dest
// void strcat(char *dest, char*src); // adds src at the end of dest.
// void strcmp(char *str1, char *str2); // compares str1 and str2
// // Returns 0 if str1 and str2 are equal
// // Number < 0 if the first symbol, in which str1 and str2 are different, is smaller at str1
// // Number > 0 if the first symbol, in which str1 and str2 are different, is smaller at str2

