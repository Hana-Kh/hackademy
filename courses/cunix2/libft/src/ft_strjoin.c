#include <stdlib.h>

char* ft_strjoin(const char* s1, const char* s2) {
 int i = 0;
 while (*(s1+i) != '\0')
  i++;
 int j = 0;
 while (*(s2+j) != '\0')
  j++;
 char* res = (char*)malloc(i+j+1);
 if (res == NULL)
   return NULL;
 i = 0;
 while (*(s1+i) != '\0') {
  res[i] = *(s1+i);
  i++;
 }
 j = 0;
 while (*(s2+j) != '\0') {
  res[i+j] = *(s2+j);
  j++;
 }
 res[i+j] = '\0';
 return res;
}
