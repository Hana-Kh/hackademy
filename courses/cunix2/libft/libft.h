#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

void ft_bzero (void *s, size_t n);

char* ft_strchr (const char *str, int ch);

int ft_isalpha (int ch);

int ft_isdigit (int ch);

int ft_isascii (int ch);

int ft_toupper (int ch);

int ft_tolower (int ch);

div_t ft_div (int num, int den);

int ft_abs (int num);

char* ft_strstr (const char* str1, const char* str2);

char* ft_strnstr (const char* str1, const char* str2, size_t len);

void ft_striter (char* s, void (*f)(char*));

char* ft_strjoin (const char* s1, const char* s2);

char* ft_strtrim (const char* s);

char** ft_strsplit (const char* s, char c);

void* ft_memcpy (void* dest, const void* source, size_t count);

void* ft_memset (void* buf, int ch, size_t count);

int ft_memcmp (const void* buf1, const void* buf2, size_t count);
