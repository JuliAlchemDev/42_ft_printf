#include <stdio.h>
#include <string.h>

// Discovering how printf works on backstage  
int main() {
    // 
    printf("return: %d\n", printf("Hello %s\n", "World!"));
    // returns 13: "Hello World!\n" = 12 chars + 1 for \n
    char *str = "Hello World!";
    printf("Str len: %d", strlen(str));
    // returns 12: strlen doesn't count null terminator \0;
    return 0;
}