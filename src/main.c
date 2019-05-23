#include "plane.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
  main function to run performance estimates
*/
int main(int argc, char* argv[]){

  struct Plane plane;

  if(argc == 1){ printf("No input\n"); return 0;

  }else if(argc == 3){

    if(strcmp("-f", argv[1]) == 0){

      char *directory = "parameters";
      int lenFile = strlen(argv[2]);
      int lenDir = strlen(directory);

      char *filename = (char *)malloc(sizeof(char) * (lenFile + lenDir + 1));
      if(filename == NULL){

	printf("Could not create pathway name!\n");
	return -1;

      }

      int i;
      for(i = 0; i < lenDir; i++){

	filename[i] = directory[i];

      }

      filename[lenDir] = '/';

      for(i = 0; i < lenFile; i++){

	filename[lenDir + 1 + i] = argv[2][i];

      }

      plane = newPlane(filename, 0);

      free(filename);

    }

  }

  printf("finished\n");

  return 0;

}
