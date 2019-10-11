#include "plane.h"
#include "myfunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
  main function to run performance estimates
*/
int main(int argc, char* argv[]){

  struct Plane plane;

  if(argc == 1){ printf("No input\n"); return 0;

  }else{

    char *dir1 = "parameters/";
    char *dir2 = "xflr5/";
    char *dir3 = "vsp/";
    int lenFile1 = strlen(argv[1]);
    int lenDir1 = strlen(dir1);

    int i, index = 0;
    int vsp = 0;
    for(i = 1; i < argc; i++){

      index++;
      
      if(subStringIndex(argv[i], "-x") >= 0){
	
	vsp = 1;
	break;

      }else if(subStringIndex(argv[i], "-o") >= 0){

	vsp = 2;
	break;

      }

    }

    int lenFile2 = strlen(argv[index + 1]);
    int lenDir2 = strlen(dir2);
    int lenDir3 = strlen(dir3);
    
    char *file1 = (char *)malloc(sizeof(char) * (lenFile1 + lenDir1));
    char *file2;
    if(vsp == 1){

      file2 = (char *)malloc(sizeof(char) * (lenFile2 + lenDir2));

    }else if(vsp == 2){

      file2 = (char *)malloc(sizeof(char) * (lenFile2 + lenDir3));

    }
    
    if(file1 == NULL || file2 == NULL){

      printf("Could not create pathway name!\n");
      return -1;

    }

    for(i = 0; i < lenDir1; i++){ file1[i] = dir1[i]; }

    for(i = 0; i < lenFile1; i++){

      file1[lenDir1 + i] = argv[1][i];

    }

    if(vsp == 1){
      
      for(i = 0; i < lenDir2; i++){ file2[i] = dir2[i]; }

      for(i = 0; i < lenFile2; i++){

	file2[lenDir2 + i] = argv[index + 1][i];

      }

    }else if(vsp == 2){

      for(i = 0; i < lenDir2; i++){ file2[i] = dir3[i]; }

      for(i = 0; i < lenFile2; i++){

	file2[lenDir3 + i] = argv[index + 1][i];

      }

    }

    plane = newPlane(file1, file2, 0, 0);

    free(file1);
    free(file2);

  }

  printf("finished\n");

  return 0;

}
