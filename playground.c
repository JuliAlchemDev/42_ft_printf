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
/*
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
*/ 


// -----------------------------------
// Working on ft_printf functionalities 
// -----------------------------------

// 1. One occurrence of %c in str

/*
#include <unistd.h>
#include <stdio.h>

int main()
{
    char *str_1;
    str_1 = "Hello%c";

    char ch_1 ='e';
    char ch_2 ='o';
    char ch_3 ='!';
    size_t i = 0;
   
    while(str_1[i] && str_1[i] != '%')
    {
        write(1, &str_1[i], 1);
        i++;
    }
    if(str_1[i] == '%' && str_1[i+1] == 'c')
    {
        write(1, &ch_3, 1);
    }
}
*/

// 2. Multiples occurrences of %c in str
/*
#include <unistd.h>
#include <stdio.h>

int main()
{
    char *str_1;
    str_1 = "j%cj%cj%c";
    
    char ch_1 ='e';
    size_t i = 0;
   
   
    while(str_1[i])
    {
       if(str_1[i] != '%')
       {
            write(1, &str_1[i], 1);
            i++;
       }
       else if(str_1[i] == '%' && str_1[i+1] == 'c')
       {
           write(1, &ch_1, 1);
           i += 2;
       }
    }
}
*/

// 3. Handle Multiples occurrences of %c in str in Variadic Function
/*
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int ft_printf(char const *str, ...)
{
    va_list args;
    va_start(args, str); 
    
    size_t i = 0;
    while(str[i])
    {
        if(str[i] != '%')
        {
            write(1, &str[i], 1);
            i++;
        }
        else if(str[i + 1] == 'c')
        {
            char ch = va_arg(args, int);
            write(1, &ch, 1); 
            i += 2;
        }
        else {
            write(1, &str[i], 1);
            i++;
        }
    }
    va_end(args);
    return 0;
}

int main()
{
    char ch_1 = 'e';
    char ch_2 = 'o';
    char ch_3 = '!';
    
    ft_printf("H%cll%c%c\n", ch_1, ch_2, ch_3);
    printf("H%cll%c%c", ch_1, ch_2, ch_3);
}
*/

// 4. Handle Multiple occurrences of %c and %s in Variadic Function
/*
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int ft_printf(char const *str, ...)
{
    va_list args;
    va_start(args, str); 
    
    size_t i = 0;
    
    while(str[i])
    {
        if(str[i] != '%')
        {
            write(1, &str[i], 1);
            i++;
        }
        else if(str[i] == '%' && str[i + 1] == 'c')
        {
            char ch = va_arg(args, int);
            write(1, &ch, 1); 
            i += 2;
        }
        
       
        else if(str[i] == '%' && str[i + 1] == 's' )
        {
            int count = 0;
            char *str_param = va_arg(args, char *);
            while(str_param[count])
            {
                write(1, &str_param[count], 1);
                count++;
            }
            i += 2;
        }
        
    }
    va_end(args);
    return 0;
}

int main()
{
    char ch_1 = 'e';
    char ch_2 = 'o';
    char ch_3 = '!';
    char *str_1 = "World";
    char *str_2 = "awsome!";
    
    ft_printf("H%cll%c %s%c The 42 is %s\n", ch_1, ch_2, str_1, ch_3, str_2);
    printf("H%cll%c %s%c The %d is %s", ch_1, ch_2, str_1, ch_3, 42, str_2);
}
*/

// 5. Recall how to print number using write() and recursion, and count the length of formatted number
/*
#include <unistd.h>
#include <stdio.h>

int ft_putnbr(int num)
{
    int ch;
    int len; 
    len = 0;
    ch = '0';
    
    if(num == -2147483648) 
    {
        write(1, "-2147483648", 11);
        len += 11;
        return len;
    }
    if (num < 0)
    {
        write(1, "-", 1);
        num *= -1;
        len += 1;
    }
    if (num > 9)
        len += ft_putnbr(num / 10);
    ch += num % 10;
    write(1, &ch, 1);
    return len + 1;
}

int main()
{
    printf(" - length: %d\n", ft_putnbr(42));
    printf(" - length: %d\n", ft_putnbr(-42));
    printf(" - length: %d\n", ft_putnbr(-0));
}
*/

// 6. Discover how to handle hexadecimal numbers using recursion and a base string
/*
#include <stdio.h>
#include <unistd.h>

void ft_putnbr_hex(unsigned long num, char format)
{
    int mod;
    char *base;

    mod = 0;
    if(format == 'x')
        base = "0123456789abcdef";
    else if(format == 'X')
        base = "0123456789ABCDEF";
         
    if(num > 15)
    {
       ft_putnbr_hex((num / 16), format);
    }
    mod = num % 16;
    write(1, &base[mod], 1);
}

int main()
{
    ft_putnbr_hex(42, 'X');
    write(1, "\n", 1);
    ft_putnbr_hex(255, 'x');
}
*/

// 7. Testing hexadecimal numbers behaviour in printf function
/*
int main()
{
    printf("%X\n", 24);         // outputs 18
    printf("%X\n", -24);        // outputs FFFFFFE8
    // -24 as unsigned: 2^32 - 24 = 4294967272
    // %X reinterprets the bits as unsigned int, no sign handling
    printf("%u\n", -24);        // 4294967272
    printf("%X\n", 4294967272); // FFFFFFE8 - confirmed
}
*/

// TODO:
/*
1. rename ft_printf.c to playground.c to save all discovery process.
2. scaffold the project:
    2.1 create ft_putchar, ft_putstr, ft_putnbr, ft_putnbr_hex, ft_putptr utilities functions
    2.2 implement ft_check_format (or ft_handle_specifier) to dispatch each specifier
    2.3 implement ft_printf to iterate the string, call ft_check_format and count total length

3. Implementation: 
    3.1 ft_putchar to write a char and return 1 ✅
    3.2 ft_putstr to write a str and return len of the string ✅
    3.3 ft_handle_specifier to look for %c %s ✅
    3.4 ft_printf to count a length ✅

    3.5 ft_putnbr to handle numbers and count a length of created str ✅
    3.6 ft_putnbr_u to handle unsigned numbers and count a length of created str ✅
    3.7 ft_putnbr_hex to handle unsigned numbers and count a length of created str ✅

    3.9 ft_putptr to handle pointer value and return its length ✅

4. Final Organization and documentation:    
    4.1   clean up project extracting headers from functions ✅
    4.2   prepare final version of Makefile ✅
    4.3   test ft_printf ✅
    4.4   add README.md
*/