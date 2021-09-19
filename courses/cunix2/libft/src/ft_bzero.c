#include "../libft.h"

void ft_bzero (void *s, size_t n) {
	size_t i;
	for (i=0; i<n; i++)
		*((char*)s+i)=0;
}
