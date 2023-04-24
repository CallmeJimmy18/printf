#include "main.h"
#include <stdint.h>
/**
 * _printf - function that produces output according to a format
 * @format:  is a character string.
 * Return: value
 */
int _printf(const char *format, ...)
{
int chars_printed;
conver_t function_list[] = {{"c", print_char}, {"s", print_string}, {"%", print_percent}, {"d", print_int}, {"i", print_int}, {NULL, NULL}};
va_list args;
if (format == NULL)
{
return (-1);
};
va_start(args, format);
chars_printed = parser{format, function_list, args};
va_end(args);
return (chars_printed);
}
