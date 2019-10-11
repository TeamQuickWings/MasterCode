#include <stdio.h>
#include "plane.h"
#include "myfunctions.h"
#include <ctype.h>
#include <stdlib.h>

int main(void){

  struct Plane plane = makePlaneStruct(1);
  
  addDouble(&plane, 1, 2, 3);

  return 0; 

}
