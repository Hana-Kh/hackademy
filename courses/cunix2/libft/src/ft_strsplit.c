#include <stdlib.h>

char** ft_strsplit(const char* s, char c) {
 int i = 0, words = 0;
 while (*(s+i) != '\0') {
  if (*(s+i) != c) {
   words++;
   while (*(s+i) != c && *(s+i) != '\0')
     i++;
   i--;
  }
  i++;
 }
 char** arr = (char**)malloc(words+1);
 if (arr == NULL)
   return NULL;
 i = 0;
 words = 0;
 while (*(s+i) != '\0') {
  if (*(s+i) != c) {
   int j = 0;
   while (*(s+i+j) != c && *(s+i+j) != '\0')
     j++;
   //printf("%d\n", j);
   arr[words] = (char*)malloc(j+1);
   if (arr[words] == NULL)
       return NULL;
     j = 0;
   while (*(s+i+j) != c && *(s+i+j) != '\0') {
     arr[words][j] = *(s+i+j);
     j++;
   }
   arr[words][j] = '\0';
   words++;
   i += j-1;
  }
  i++;
 }
 arr[words] = '\0';
 /*i = 0;
 words = 0;
 while (*(s+i) != '\0') {
  if (*(s+i) != c) {
   int j = 0;
   while (*(s+i+j) != c && *(s+i+j) != '\0'){
     arr[words][j++] = *(s+i+j);
   arr[words][j] = '\0';
   words++;
   //i += j-1;
  }
  i++;
 }*/
 
 return arr;
}
