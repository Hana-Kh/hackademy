#include "../libft.h"

div_t ft_div(int num, int den)
{
	div_t res;
	res.quot = num/den;
	res.rem = num%den;
	return res;
}
