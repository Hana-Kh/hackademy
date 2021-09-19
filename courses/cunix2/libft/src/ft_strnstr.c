#include "../libft.h"

char* ft_strnstr (const char* str1, const char* str2, size_t len)
{
	size_t i = 0, j = 0;

	do
	{
		if (*(str2+j) == '\0') return (char*)(str1+i-j);
		if (*(str1+i) == *(str2+j))
			j++;
		else {
			i -= j;
			j = 0;
		}
		i++;
	} while(*(str1+i-1) != '\0' && i <= len);
	return NULL;
}
