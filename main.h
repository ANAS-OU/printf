#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <limits.h>

int _putchar(char c);
int _printf(const char *format, ...);
void print_number(int n);
int specifier_handler(char spc, va_list args);

#endif /* MAIN_H */
