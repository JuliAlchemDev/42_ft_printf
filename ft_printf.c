#include <stdio.h>
#include <string.h>

// Discovering how printf works on backstage  
/*
int main() {
    // 
    printf("return: %d\n", printf("Hello %s\n", "World!"));
    // returns 13: "Hello World!\n" = 12 chars + 1 for \n
    char *str = "Hello World!";
    printf("Str len: %d", strlen(str));
    // returns 12: strlen doesn't count null terminator \0;
    return 0;
}
*/

// Learn more about printf specifiers to implement for this project
/*
int main() {
 
    char ch = 'A';
    
    char str[10] = "Hello";
    char *str_lit = "Hello";
  
    printf("Char: %c\n", 'A');
    printf("String: %s\n", "Hello");
    // STACK
    printf("Pointer CH: %p\n", &ch); // Ex: 0x7ffcdd256cc7 (changes each run)
    printf("Pointer STR: %p\n", &str); // Ex: 0x7ffcdd256cbd (changes each run)
    // .rodata
    printf("Pointer STR_lit: %p\n", str_lit); // 0x402004 (stable address)

    int decimal = 9;
    int integer = -42; 
    unsigned int un_int = 42;
    // unsigned int un_int = -42; // testing negative value → 2³² + (-42) = 4294967254

    // same behaviour for printf
    printf("Decimal: %d\n", decimal);
    printf("Integer: %i\n", integer);
    // if (positive ) returns num;
    // if (negative) reinterprets bits as unsigned 2³² + num;
    printf("Unsigned decimal / integer: %u\n", un_int);
   

    // TODO: discover what hex int is, usage and behaviour 

    // Base 2: 0-1;
    // Base 10: 0-9;
    // Base 16: 0-9 y a-f

    char str[10] = "Hello";
    printf("Hexadecimal integer (lower): %x\n", &str); //3cb065c6
    printf("Hexadecimal integer (upper): %X\n", &str); //3CB065C6
    printf("Pointer STR: %p\n", &str); // 0x7ffd3cb065c6

    printf("Percent symbol: %%\n"); 
    // %% accepts no arguments, %  alone is undefined behaviour
    // printf("Variation 1: %\n"); -> invalid conversion specifier '\x0a'
    // printf("Variation 2: %%\n", '%'); -> data argument not used by format string

    return 0;
}
*/

// Variadic Functions 
// [GeeksForGeeks](https://www.geeksforgeeks.org/c/variadic-functions-in-c/)

#include <stdarg.h>

void print(int n, ...)
{
    va_list args;
    va_start(args, n);

    for(int i = 0; i < n; i++)
        printf("%d ", va_arg(args, int)); // retrieve Args -> va_arg(list, type)
    printf("\n");

    va_end(args);
}

int main()
{
    print(3, 1, 2, 3);
    print(5, 1, 2, 3, 4, 5);
}