#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int print_char(char c);
int print_string(char *str);
int handle_specifier(char specifier, va_list args);
int print_number(int n);

#endif
