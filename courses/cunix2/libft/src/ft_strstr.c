#include "../libft.h"

char* ft_strstr (const char* str1, const char* str2)
{
	int i = 0, j = 0;
	bool is_str2 = false;
	do
	{
		if (*(str2+j) == '\0') return (char*)(str1+i-j);
		is_str2 = *(str1+i) == *(str2+j);
		if (is_str2)
			j++;
		else
			j = 0;
		i++;
	} while(*(str1+i-1) != '\0');
	return NULL;
}
