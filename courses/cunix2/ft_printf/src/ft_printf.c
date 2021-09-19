#include <unistd.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

#define next_char * (format + i)


char* int_to_char(int n, int digit)
{
	char* arr;
	char arr1[digit];

	arr = (char*)malloc(digit * sizeof(char));

	int index = 0;
	while (n) {
		arr1[++index] = n % 10 + '0';
		n /= 10;
	}

	int i;
	for (i = 0; i < index; i++) {
		arr[i] = arr1[index - i];
	}
	arr[i] = '\0';

	return (char*)arr;
}

int ft_printf(const char * format, ...)
{
	int i = 0;
	va_list args;
	va_start(args, format);

	while (next_char != '\0') {
		if (next_char == '%') {
			i++;
			
			bool sp_flag = false, pl_flag = false, zr_flag = false, ng_flag = false;
			while (next_char == ' ' || next_char == '+' || next_char == '0') {
				switch (next_char) {
				case ' ':
					sp_flag = true;
					break;
				case '+':
					pl_flag = true;
					break;
				case '0':
					zr_flag = true;
					break;			
				}
				i++;
			}
			
			int width_len = 0, width = 0;
			char* width_arr = (char*)malloc(sizeof(char) * 128);
			while (next_char >= '0' && next_char <= '9') {
				width_arr[width_len++] = next_char;
				i++;
			}
			width_arr[width_len] = '\0';
			int j = 0, k;
			int dozens = 1;
			for (k = 1; k < width_len; k++)
				dozens *= 10;
			while (*(width_arr+j) != '\0') {
				width += (*(width_arr+j) - '0') * dozens;
				dozens /= 10;
				j++;
			}

			int res_len = 0;
			char* res_char;
			switch (next_char) {
			case '%':
				write(1, "%", 1);
				i++;
				continue;
				//res_char = "%";
				//res_len = 1;
				//break;
			case 'd':
			case 'i': {
				int j = va_arg(args, int);

				if (j == 0) {
					res_char = "0";
					res_len = 1;
					break;
				}

				if (j == INT_MIN) {
					ng_flag = true;
					res_char = "2147483648";
					res_len = 10;
					break;
				}

				if (j < 0) {
					ng_flag = true;
					j *= -1;
				}

				int m = j;
				int digits = 0;
				while (m) {
					digits++;
					m /= 10;
				}

				res_char = int_to_char(j, digits);
				res_len = digits;
				break;
			}
			case 'c': {
				char c_arg = va_arg(args, int);
				res_char = &c_arg;
				res_len = 1;
				break;
			}
			case 's': {
				char * s_arg = va_arg(args, char*);

				if (s_arg == NULL)	
					s_arg = "(null)";

				j = 0;
				while (*(s_arg+j) != '\0') {
					j++;
				}

				res_char = s_arg;
				res_len = j;
				break;
			}
			default:
				write(2, "Unknown specifier: ", 20);
				write(2, &next_char, 1);
			}

			int sign = 0;
			if (!zr_flag)	
				for (k = 0; k < width - res_len - (int)(sp_flag | ng_flag); k++)
					write(1, " ", 1);

			if (ng_flag) {
				write(1, "-", 1);
				sign = 1;
			} else {
				if (pl_flag) {
					write(1, "+", 1);
					sign = 1;
				} else {
					if (sp_flag) {
						write(1, " ", 1);
						sign = 1;
					}
				}
			}

			if (zr_flag)
				for (k = 0; k < width - res_len - sign; k++)
					write(1, "0", 1);

			write(1, res_char, res_len);
		} else {
			write(1, &next_char, 1);
		}
		i++;
	}
	va_end(args);
	return 0;
}
