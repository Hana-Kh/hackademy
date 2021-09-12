#include <unistd.h>

int my_puts(const char *s)
{
	int i=0;
	while(*(s+i) != '\0')
	{
		i++;
	}
	int j = write(1, s, i);
	char k = '\n';
	write(1, &k, 1);
	return j;
}
