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
double *getDouble(char *str, int size){

  double temp = 0;
  double *num = &temp;
  int dec = -1;
  int pos = 1;
  int index = 0;
  
  if(size < 1 || size > strlen(str)){ return NULL; }

  if(str[0] == '-'){

    pos = -1;
    index++;

  }

  while(index < size && str[index] != '.'){

    if(isdigit(str[index]) == 0){ return NULL; }

    *num = (*num * 10) + str[index] - '0';
    index++;

  }

  if(index != size){

    if(str[index] == '.'){ index++; }

  }

  while(index < size){

    if(isdigit(str[index]) == 0){ return NULL; }

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

/*
  Function returns an array of doubles parsed from the inputted string, a points to a size variable is also inputted and will have a size greater than zero is numbers were parsed. If it fails it will return NULL
  code NULL - failed
 */
double* getDoubles(char* str, int* size){

  int len = strlen(str);
  int i = 0;
  *size = 0;
  int largest = 0;
  int start = 0, end = 0;
  while(start < len && end < len){

    while(isdigit(str[start]) == 0 && str[start] != '-'){

      start++;
      end++;

    }
    
    while(isdigit(str[end + 1]) != 0 || str[end + 1] == '.'){
    
      end++;

    }

    if(end > len){ break; }

    if((end - start) > largest){ largest = end - start; }

    if(start - end == 0){


      if(str[end] != '-'){ *size = *size + 1; }

    }else{ *size = *size + 1; }

    end++;
    start = end;

  }

  start = 0;
  end = 0;
  
  double* temp = (double *)malloc(sizeof(double) * *size);
  char* double_str = (char *)malloc(sizeof(char) * (largest + 2));
  if(double_str == NULL || temp == NULL){

    printf("Failed to make double string!\n");
    return NULL;

  }
  
  while(start < len && end < len){

    while(isdigit(str[start]) == 0 && str[start] != '-'){

      start++;
      end++;

    }
    
    while(isdigit(str[end + 1]) != 0 || str[end + 1] == '.'){
    
      end++;

    }

    int index = start;
    int j;
    for(j = 0; j < (end - start + 1); j++){

      double_str[j] = str[index];
      index++;

    }
    double_str[index] = 3;

    double* test = getDouble(double_str, end - start + 1);
    if(test == NULL){

      printf("Failed!\n");
      return NULL;

    }

    if(start - end == 0){


      if(str[end] != '-'){

	double* test = getDouble(double_str, end - start + 1);
	if(test == NULL){

	  printf("Failed!\n");
	  return NULL;

	}
	
	temp[i] = *test;
	i++;

      }

    }else{

      double* test = getDouble(double_str, end - start + 1);
      if(test == NULL){

	printf("Failed!\n");
	return NULL;

      }

    }

    end++;
    start = end;

  }

  free(double_str);

  if(*size == 0){ return NULL; }

  return temp;

}
