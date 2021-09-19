#include "../libft.h"

char* ft_strchr (const char *str, int ch){
	
	int i=0;
	do{
		if (*(str+i)==(char)ch) 
			return (char*)(str+i);
		i++;
	}while (*(str+i-1)!='\0');

	return 0;

}
