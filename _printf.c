#include "main.h"

/**
 * _printf - Custom printf implementation
 * @format: A pointer to the format string
 *
 * Description: This function implements some functions of printf.
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
    const char *string;
    int char_count = 0;
    va_list args;

    if (!format)
        return (-1);

    va_start(args, format);
    string = format;

    char_count = loop_format(args, string);

    va_end(args);
    return (char_count);
}

/**
 * loop_format - Loop through the format string
 * @arg: A va_list containing the arguments
 * @string: A pointer to the format string
 *
 * Description: This function loops through the format string
 * and processes the format specifiers.
 * Return: The number of characters printed.
 */
int loop_format(va_list arg, const char *string)
{
    int i = 0, flag = 0, format_count = 0, char_count = 0, check_percent = 0;

    while (i < _strlen((char *)string) && *string != '\0')
    {
        char aux = string[i];

        if (aux == '%')
        {
            i++, flag++;
            aux = string[i];
            if (aux == '\0' && _strlen((char *)string) == 1)
                return (-1);
            if (aux == '\0')
                return (char_count);
            if (aux == '%')
            {
                flag++;
            }
            else
            {
                format_count = function_manager(aux, arg);
                if (format_count >= 0 && format_count != -1)
                {
                    i++;
                    aux = string[i];
                    if (aux == '%')
                        flag--;
                    char_count = char_count + format_count;
                }
                else if (format_count == -1 && aux != '\n')
                {
                    char_count += _putchar('%');
                }
            }
        }
        check_percent = check_percent(&flag, aux);
        char_count += check_percent;
        if (check_percent == 0 && aux != '\0' && aux != '%')
            char_count += _putchar(aux), i++;
        check_percent = 0;
    }
    return (char_count);
}

/**
 * check_percent - Handle percent characters
 * @flag: A pointer to the flag
 * @aux: The character to check
 *
 * Description: This function handles percent characters (%%).
 * Return: 1 if % is printed, 0 otherwise.
 */
int check_percent(int *flag, char aux)
{
    int tmp_flag;
    int char_count = 0;

    tmp_flag = *flag;
    if (tmp_flag == 2 && aux == '%')
    {
        _putchar('%');
        tmp_flag = 0;
        char_count = 1;
    }
    return (char_count);
}

/**
 * call_function_manager - Call the function manager
 * @aux: The character parameter
 * @arg: A va_list containing the arguments
 *
 * Description: This function calls the function manager.
 * Return: The number of characters printed.
 */
int call_function_manager(char aux, va_list arg)
{
    int char_count = 0;

    char_count = function_manager(aux, arg);
    return (char_count);
}

