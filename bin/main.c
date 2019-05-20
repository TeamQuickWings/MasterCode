#include "plane.h"
#include <stdio.h>
#include <string.h>


/*
  main function to run performance estimates
*/
int main(int argc, char* argv[]){

  struct Plane plane;

  if(argc == 1){ printf("No input\n"); return 0;

  }else if(argc == 3){

    if(strcmp("-f", argv[1]) == 0){

      plane = makePlane(argv[2]);

    }

  }

  printf("finished\n");

  return 0;

}
