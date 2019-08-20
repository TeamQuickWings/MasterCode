#include <stdio.h>
#include "plane.h"
#include "myfunctions.h"
#include <ctype.h>
#include <stdlib.h>

int main(void){

  //struct Plane plane = newPlane("parameters/dev/testfile", 0, 0);

  /*
  printf("size: %d\n", plane.param_size);
  int i;
  for(i = 0; i < plane.param_size; i++){

    printf("param %s: %lf\n", paramToString(plane.params[i]), plane.paramv[i]);

  }

  printf("angles: %lf %lf\n", plane.angles[0], plane.angles[1]);
  */
  
  double* values;
  int size;
  values = getDoubles("20", &size);

  int i;
  printf("size: %d\n", size);
  for(i = 0; i < size; i++){

    printf("%lf\n", values[i]);

  }

  return 0; 

}
