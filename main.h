#ifndef MAIN_H
#define MAIN_H

/**********************
 * standard libraries
 **********************/
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>

/**********************
 * functions prototype 
 **********************/

/* _printf.c */
int _printf(const char *format, ...);

/* _stdout.c */
int _putchar(char);
int _puts(char*);

/* print_number.c */
void print_number(int n);

#endif /* MAIN_H */
