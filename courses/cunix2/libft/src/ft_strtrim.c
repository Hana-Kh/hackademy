#include <stdlib.h>

char* ft_strtrim(const char* s) {
 int i = 0, st_sp = 0, en_sp = 0;
 while (*(s+i) != '\0')
  i++;
 while (*(s+st_sp) == '\t' || *(s+st_sp) == '\n' || *(s+st_sp) == ' ')
  st_sp++;
 while (*(s+i-en_sp-1) == '\t' || *(s+i-en_sp-1) == '\n' || *(s+i-en_sp-1) == ' ')
  en_sp++;
 if ((st_sp == en_sp && st_sp == i) || i == 0) {
	 char* res = (char*)malloc(1);
	 res[0] = '\0';
	 return res;
 }
 char* res = (char*)malloc(i-st_sp-en_sp+1);
 if (res == NULL)
   return NULL;
 int j = 0;
 while (j < i-st_sp-en_sp) {
  res[j] = *(s+j+st_sp);
  j++;
 }
 res[j] = '\0';
 return res;
}
