#ifndef MAIN_H
#define MAIN_H

/**********************
 * standard libraries
 **********************/
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>

/**********************
 *    complex types
 **********************/
/**
 * struct specifier - new custom type
 *
 * @c: conversion specifirr
 * @f: pointer to print functions
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list);
} specifier_t;

/**********************
 * functions prototype
 **********************/

/* _printf.c */
int _printf(const char *format, ...);

/* _stdout.c */
int _putchar(char);
int _puts(char *);

/* print_1.c */
int print_char(va_list);
int print_str(va_list);
int print_perc(va_list);

/* get_specifier_handler.c */
int (*get_specifier_handler(char *))(va_list);

/* _strcmp.c */
int _strcmp(char *, char *);

#endif /* MAIN_H */
