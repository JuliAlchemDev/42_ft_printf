*This project has been created as part of the 42 curriculum by iualkhim*

<p align="center">
  <img src="./assets/ft_printf.png" alt="ft_printf 42 project badge"/>
</p>

## Description
The main goal of the project is to recreate the basic version of the C standard library `printf` function.

### Definition and Usage
The `printf()` function writes a formatted string to the console and returns the length of created string. The function `ft_printf` should be able to take an indefinite number of parameters, the first of which is always a string and handle the reduced list of specifiers that goes next.

```c
int	ft_printf(char const *str, ...);
```

### Handled Specifiers
| Format Specifier | Description | Responsible Function |
|---|---|---|
| %c | writes a single character |  [ft_putchar()](./ft_putchar.c)  |
| %s | writes a character string |  [ft_putstr()](./ft_putstr.c)  |
| %d or %i | writes a signed integer to decimal representation|  [ft_putnbr()](./ft_putnbr.c)  |
| %u| writes an unsigned integer to decimal representation |  [ft_putnbr_u()](./ft_putnbr_u.c)  |
| %x or %X | writes an unsigned integer to hexadecimal representation |  [ft_putnbr_hex()](./ft_putnbr_hex.c)  |
| %p | writes an implementation-defined character sequence defining a pointer address |  [ft_putptr()](./ft_putptr.c)  |
| %% | % followed by another % character writes % to the screen |  [ft_putchar('%')](./ft_putchar.c)  |

## Instructions

1. Clone a project:
```bash
git clone https://github.com/JuliAlchemDev/42_ft_printf.git ft_printf

cd ft_printf
```
2. Make use of Makefile to compile library: 
```bash
make 
``` 
3. Compile the main.c file with the ft_printf library and run the program:
```bash
cc main.c -L. -lftprintf -o test && ./test
```

![./test example](./assets/test-example.png "Example")
## Resources
C stdio printf() Function -> [w3schools](https://www.w3schools.com/c/ref_stdio_printf.php)

Variadic Functions -> [GeeksForGeeks](https://www.geeksforgeeks.org/c/variadic-functions-in-c/)  

You can also check my investigation and implementation process in [playground](./playground.c) 

---
**AI Usage:** I used [Claude](https://claude.ai) (Anthropic) as an AI augmentation tool throughout my learning process — breaking the project down into smaller parts before coding, discussing architecture and organization decisions, and getting guidance on documentation writing and evaluation preparation.