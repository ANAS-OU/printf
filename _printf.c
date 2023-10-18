#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * my_printf - Print formatted output to stdout.
 * @fmt: A format string with optional conversion specifiers.
 * Return: The count of characters printed (excluding the null byte).
 */
int my_printf(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);

    int char_count = 0; // To keep track of the number of characters printed

    for (int i = 0; fmt[i] != '\0'; i++) {
        if (fmt[i] == '%') {
            i++; // Move to the next character after '%'
            if (fmt[i] == '\0') {
                break; // End of format string
            }

            switch (fmt[i]) {
                case 'c':
                    char_count += putchar(va_arg(args, int));
                    break;

                case 's': {
                    const char *str = va_arg(args, const char*);
                    while (*str) {
                        char_count += putchar(*str);
                        str++;
                    }
                    break;
                }

                case '%':
                    char_count += putchar('%');
                    break;

                default:
                    char_count += putchar('%');
                    char_count += putchar(fmt[i]);
                    break;
            }
        } else {
            char_count += putchar(fmt[i]);
        }
    }

    va_end(args);
    return char_count;
}

int main() {
    my_printf("Greetings, %s! My beloved symbol is %c. Here's a %% sign: %%\n", "Eve", 'Y');
    return 0;
}
