#include "../libft.h"

int ft_memcmp(const void* buf1, const void* buf2, size_t count) {
	int i;
	char* buf1_2 = (char*)buf1, *buf2_2 = (char*)buf2;
	for(i = 0; i<(int)count; i++)
		if (*(buf1_2+i) != *(buf2_2+i))
			return (int*)(buf1_2+i) < (int*)(buf2_2+i) ? -1 : 1;
	return 0;
}
