#include "../libft.h"

void* ft_memcpy(void* dest, const void* source, size_t count) {
	size_t i;
	char* dest_2 = (char*)dest, *source_2 = (char*)source;
	for(i = 0; i<count; i++)
		*(dest_2+i) = *(source_2+i);
	return dest_2;
}
