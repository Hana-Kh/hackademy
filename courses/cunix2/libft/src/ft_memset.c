#include "../libft.h"

void* ft_memset(void* buf, int ch, size_t count) {
	size_t i;
	char* buf_2 = (char*)buf;
	for(i = 0; i<count; i++)
		*(buf_2+i) = ch & 0xFF;
	return buf_2;
}
