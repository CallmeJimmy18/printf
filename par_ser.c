#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * parser - checkes the code
 * @format: this is a character string
 * @function_list: has the different formats as arguments
 * @args: these are the arguments
 * Return: returns the characters printed
 */
int parser(const char *format, conver_t function_list[], va_list args)
{
int i, j, val, chars_printed;
chars_printed = 0;
for (i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%')//for format specifiers
{
for (j = 0; function_list[j].sym != NULL; j++)
{
if (format[i + 1] == function_list[j].sym[0])
{
val = function_list[j].f(args);
if (val == -1)
return (-1);
chars_printed += val;
break;
}
}
if (function_list[j].sym == NULL && format[i + 1] != ' ')
{
if (format[i + 1] != '\0')
{
_putchar(format[i]);
_putchar(format[i + 1]);
chars_printed = chars_printed + 2;
}
else
return (-1);
}
i = i + 1;
}
else
{
_putchar(format[i]);
chars_printed++;
}
}
return (chars_printed);
}
