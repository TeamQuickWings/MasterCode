#include "plane.h"
#include "csv.h"
#include <stdio.h>
#include <stdlib.h>

/*
  method that will return a Plane struct using the information in the
  inputted file
*/
struct Plane makePlane(char* filename){

  FILE *file = fopen(filename, "r");
  if(file == NULL){ printf("Plane file could not be opened\n"); exit(-1); }

  

}
