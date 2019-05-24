#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

/*
  Function that returns the index of the beginning of a substring in 
  a given string. Returns -1 if the substring was not found.
 */
int subStringIndex(char *haystack, char *needle){

  char *s1, *s2, *s3;
  int i, j;

  s1 = haystack;
  s2 = needle;

  for(i = 0; i < strlen(haystack); i++){
    
    if(*s1 == *s2){

      s3 = s1;

      for(j = 0; j < strlen(needle); j++){

	if(*s3 == *s2){ s3++; s2++;

	}else{ break; }

      }

      s2 = needle;
      if(j == strlen(needle)){ return i; }

    }

    s1++;

  }

  return -1;

}

/*
  Function that returns a double of the inputted string. Exits with error
  code -1 if the inputted string can not be converted to a double
*/
double *getDouble(const char *str, int size){

  double temp = 0;
  double *num = &temp;
  int dec = -1;
  int pos = 1;
  int index = 0;

  int len = 0;
  while(len < size){

    if(str[len] == '\0' || str[len] == '\n'){ break; }
    len++;

  }

  if(len < 1){

    return NULL;

  }

  if(str[0] == '-'){

    pos = -1;
    index++;

  }

  while(index < len && str[index] != '.'){

    if(isdigit(str[index]) == 0){

      return NULL;

    }

    *num = (*num * 10) + str[index] - '0';
    index++;

  }

  if(index != len){

    if(str[index] == '.'){ index++; }

  }

  while(index < len){

    if(isdigit(str[index]) == 0){

      return NULL;

    }

    *num = *num + ((str[index] - '0') * pow(10, dec--));
    index++;

  }

  *num = *num * pos;

  return num;

}

/*
  Function that returns a double of the inputted string. Exits with error
  code -1 if the inputted string can not be converted to a double
*/
double *getDoubleTerm(void){

  char str[10];
  scanf("%s", str);

  double temp = 0;
  double *num = &temp;
  int dec = -1;
  int pos = 1;
  int index = 0;
  int len = strlen(str);

  if(len < 1){

    return NULL;

  }

  if(str[0] == '-'){

    pos = -1;
    index++;

  }

  while(index < len && str[index] != '.'){

    if(isdigit(str[index]) == 0){

      return NULL;

    }

    *num = (*num * 10) + str[index] - '0';
    index++;

  }

  if(index != len){

    if(str[index] == '.'){ index++; }

  }

  while(index < len){

    if(isdigit(str[index]) == 0){

      return NULL;

    }

    *num = *num + ((str[index] - '0') * pow(10, dec--));
    index++;

  }

  *num = *num * pos;

  return num;

}

int getDoubles(char* str, double* doubles, int* size){

  int len = strlen(str);
  int i;
  int count = 0;

  for(i = 0; i < len - 1; i++){

    if(4isdigit(str[i]) != 0 && isdigit(str[i + 1]) == 0 && str[i + 1] != '-' && str[i + 1] != '.'){ count++; }

  }

  if(isdigit(str[len - 1]) != 0 || str[len - 1] == '.'){ count++; }

  printf("count: %d\n", count);
  

  return 0;

}
