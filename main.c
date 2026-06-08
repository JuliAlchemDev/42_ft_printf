#include <stdio.h> 
#include "ft_printf.h" 

#define GREEN  "\033[92m"
#define BG_BLUE   "\033[107m"
#define CYAN     "\033[36m"
#define BOLD      "\033[1m"
#define UNDERLINE  "\033[4m"
#define RESET     "\033[0m"

// cc main.c -L. -lftprintf -o test

int main(void)
{
    int len_1;
    int len_2;

    printf(BOLD "%s" RESET "\n\n", "=================================================");

    /* *******************CHAR*********************** */
    printf(CYAN BOLD "[01] >> Print Char" RESET "\n" );
    printf(UNDERLINE "ft_printf | printf" RESET "  \n" );
    
    len_1 = ft_printf("%c", 'H');
    printf("         |");
    printf("%1s", "");
    len_2 = printf("%c", 'H');
    printf(BOLD "\nResult: " RESET);
    if (len_1 == len_2)
        printf(GREEN "%-6s[OK]\n" RESET, "");
    
    printf("\n");
    /* *******************END*CHAR********************** */

    /* *******************STRING*********************** */
    printf(CYAN BOLD"[02] >> Print String\n" RESET);
    printf(UNDERLINE "ft_printf | printf" RESET "  \n" );

    len_1 = ft_printf("%s", "Hello!");
    printf("    |");
    printf("%1s", "");
    len_2 = printf("%s" , "Hello!");
    printf(BOLD "\nResult: " RESET);
    if (len_1 == len_2)
        printf(GREEN "%-6s[OK]\n" RESET, "");
    printf("\n");
    /* *******************END*STRING********************** */

    /* *******************POINTER*********************** */
    printf(CYAN BOLD"[03] >> Print Pointer\n" RESET);
    printf(UNDERLINE "ft_printf  | printf" RESET "  \n" );
    int *ptr = &len_1;
    len_1 = ft_printf("%p", ptr);
    printf("|");
    printf("%1s", "");
    len_2 = printf("%p" , ptr);
    printf(BOLD "\nResult: " RESET);
    if (len_1 == len_2)
        printf(GREEN "%-6s[OK]\n" RESET, "");
    printf("\n");
    /* *******************END*POINTER********************** */

    /* *******************DECIMAL/INTEGER*********************** */
    printf(CYAN BOLD"[04] >> Print Decimal / Integer\n" RESET);
    printf(UNDERLINE "ft_printf | printf" RESET "  \n" );
    len_1 = ft_printf("%i", -42);
    printf("       |");
    printf("%1s", "");
    len_2 = printf("%i" , -42);
    printf(BOLD "\nResult: " RESET);
    if (len_1 == len_2)
        printf(GREEN "%-6s[OK]\n" RESET, "");
    printf("\n");
    /* *******************END*DECIMAL/INTEGER********************** */

    /* *******************UNSIGNED*********************** */
    printf(CYAN BOLD"[05] >> Print Unsigned\n" RESET);
    printf(UNDERLINE "ft_printf | printf" RESET "  \n" );
    len_1 = ft_printf("%u", 42);
    printf("        |");
    printf("%1s", "");
    len_2 = printf("%u" , 42);
    printf(BOLD "\nResult: " RESET);
    if (len_1 == len_2)
        printf(GREEN "%-6s[OK]\n" RESET, "");
    printf("\n");
    /* *******************END*UNSIGNED********************** */
    
     /* *******************HEX*********************** */
    printf(CYAN BOLD"[06] >> Print Hexadecimal Uppercase / Lowercase\n" RESET);
    printf(UNDERLINE "ft_printf | printf" RESET "  \n" );
    len_1 = ft_printf("%x", 42949691);
    printf("   |");
    printf("%1s", "");
    len_2 = printf("%x" , 42949691);
    printf(BOLD "\nResult: " RESET);
    if (len_1 == len_2)
        printf(GREEN "%-6s[OK]\n" RESET, "");
    printf("\n");
    /* *******************END*HEX********************** */
    
    /* *******************PERCENT*SIGN********************** */
    printf(CYAN BOLD"[07] >> Print Percent sign\n" RESET);
    printf(UNDERLINE "ft_printf | printf" RESET "  \n" );
    len_1 = ft_printf("%%");
    printf("         |");
    printf("%1s", "");
    len_2 = printf("%%");
    printf(BOLD "\nResult: " RESET);
    if (len_1 == len_2)
        printf(GREEN "%-6s[OK]\n" RESET, "");
    printf("\n");
    printf(BOLD "%-50s" RESET "\n", "=================================================");
    /* *******************END*PERCENT*SIGN********************** */
    return (0);
}

