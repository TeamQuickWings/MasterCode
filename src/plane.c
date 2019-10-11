#define _GNU_SOURCE

#include "plane.h"
#include "myfunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
  Function that when given a string returns the corresponding Param 
enum else it returns -1;
 */
enum Param stringToParam(char* str){

  if(subStringIndex(str, "cl_slope") >= 0){ return CL_SLOPE;

  }else if(subStringIndex(str, "zero_angle_cl") >= 0){ return CL0;

  }else if(subStringIndex(str, "wingspan") >= 0){ return WINGSPAN;

  }else if(subStringIndex(str, "chord") >= 0){ return CHORD;

  }else if(subStringIndex(str, "swept_angle") >= 0){ return S_ANGLE;

  }else if(subStringIndex(str, "cruise_alt") >= 0){ return CRUISE_ALT;

  }else if(subStringIndex(str, "aoa_at_cruise") >= 0){ return AOA_C;

  }else if(subStringIndex(str, "cruise_velocity") >= 0){ return CRUISE_VEL;

  }else if(subStringIndex(str, "max_velocity") >= 0){ return MAX_VEL;

  }else if(subStringIndex(str, "aircraft_weight") >= 0){ return A_WGHT;

  }else if(subStringIndex(str, "cargo_weight") >= 0){ return C_WGHT;

  }else if(subStringIndex(str, "fuel_weight") >= 0){ return F_WGHT;

  }else if(subStringIndex(str, "cD0") >= 0) { return CD0;

  }else if(subStringIndex(str, "span_efficiency_factor") >= 0){ return SPAN_EFF_FCTR;

  }else if(subStringIndex(str, "specific_fuel_consumption") >= 0){ return SFC;

  }else if(subStringIndex(str, "propeller_efficiency") >= 0){ return PROP_EFF;

  }else if(subStringIndex(str, "engine_power") >= 0){ return ENG_PWR;

  }else if(subStringIndex(str, "n_structure") >= 0){ return N_STR;

  }

  return -1;

}

/*
  function when given a param enum returns the corresponding string 
else returns null
 */
char* paramToString(enum Param param){

  switch(param){

  case CL_SLOPE: return "cl_slope";

  case CL0: return "zero_angle_cl";

  case WINGSPAN: return "wingspan";

  case CHORD: return "chord";

  case S_ANGLE: return "swept_angle";

  case CRUISE_ALT: return "cruise_altitude";

  case AOA_C: return "aoa_at_cruise";

  case CRUISE_VEL: return "cruise_velocity";

  case MAX_VEL: return "max_velocity";

  case A_WGHT: return "aircraft_weight";

  case F_WGHT: return "fuel_weight";

  case C_WGHT: return "cagro_weight";

  case CD0: return "cD0";

  case SPAN_EFF_FCTR: return "span_efficiency_factor";

  case SFC: return "specific_fuel_consumption";

  case PROP_EFF: return "propeller_efficiency";

  case ENG_PWR: return "engine_power";

  case N_STR: return "n_structure";

  }

  return NULL;

}

/*
  function to create a plane structure
 */
struct Plane makePlaneStruct(int type){

  struct Plane plane;
  plane.type = type;
  plane.params = NULL;
  plane.paramv = NULL;
  plane.param_size = 0;
  plane.xflr_angles = NULL;
  plane.xflr_cl = NULL;
  plane.xflr_cd = NULL;
  plane.xflr_size = 0;

  return plane;

}

/*
  function that returns the index of the param else returns -1
 */
int findParam(struct Plane plane, enum Param param){

  int i;
  for(i = 0; i < plane.param_size; i++){

    if(param == plane.params[i]){ return i; }

  }

  return -1;

}

/*
  function that adds the param and value to the plane struct, returns 0
  if it was sucessful and -1 if it param already exits
 */ 
int addParam(struct Plane* plane, enum Param param, double value){

  int test = findParam(*plane, param);
  if(test >= 0 ){ return -1; }

  enum Param *newp = (enum Param *)malloc(sizeof(enum Param) * (plane->param_size + 1));
  double *newv = (double *)malloc(sizeof(double) * (plane->param_size + 1));
  if(newp == NULL || newv == NULL){

    printf("Could not add param!\n");
    exit(-1);

  }

  int i;
  for(i = 0; i < plane->param_size; i++){

    newp[i] = plane->params[i];
    newv[i] = plane->paramv[i];

  }

  newp[plane->param_size] = param;
  newv[plane->param_size] = value;
  plane->param_size++;

  free(plane->params);
  free(plane->paramv);

  plane->params = newp;
  plane->paramv = newv;

  return 0;

}

/*
  function that returns the value of a param, if the param is not found
  it will ask the user to input a value
 */
double getValue(struct Plane* plane, enum Param param){

  int find = findParam(*plane, param);
  while(find == -1){

    double* test = NULL;
    while(test == NULL){

      printf("Input value for %s: ", paramToString(param));
      test = getDoubleTerm();

    }

    int added = addParam(plane, param, *test);
    if(added != 0){

      printf("An error that you should have not been able to achieve!\n");
      exit(-1);

    }

    find = findParam(*plane, param);
    
  }

  return plane->paramv[find];

}

double* doubleSubString(char* str, enum Param param){

  int start = strlen(paramToString(param));

  while(isdigit(str[start]) == 0 && str[start] != '-'){ start++; }
  int end = start + 1;
  while(isdigit(str[end]) != 0){ end++; }

  if(str[end] == '.'){

    end++;
    while(isdigit(str[end]) != 0){ end++; }

  }

  char num[100];

  int i;
  for(i = start; i < end; i++){

    num[i - start] = str[i];

  }

  double* ret = getDouble(num, end - start);

  return ret;

}

int getAngles(char* str, double* angles){

  char first[10];
  char last[10];
  char del = ' ';
  int index1 = -1;
  int index2 = -1;
  int len = strlen(str);

  int i;
  for(i = 0; i < len; i++){

    if(index1 == -1 && str[i] == del){ index1 = i; }
    if(index1 != -1 && index1 != i && str[i] == del){ index2 = i; break; }

  }

  index1++;
  index2++;
  for(i = index1; i < index2; i++){

    first[i - index1] = str[i];

  }

  for(i = index2; i < len; i++){

    last[i - index2] = str[i];

  }

  if(index2 == -1){ return -1; }

  double* test = getDouble(first, index2 - index1 - 1);
  if(test == NULL){ return -1; }
  angles[0] = *test;
  test = getDouble(last, len - index2 - 1);
  if(test == NULL){ return -1; }
  angles[1] = *test;
  
  return 0;

}

int addDouble(struct Plane* plane, double alpha, double cl, double cd){
  
  double *newa = (double *)malloc(sizeof(double) * (plane->xflr_size + 1));
  double *newl = (double *)malloc(sizeof(double) * (plane->xflr_size + 1));
  double *newd = (double *)malloc(sizeof(double) * (plane->xflr_size + 1));
  if(newa == NULL || newl == NULL || newd == NULL){

    printf("Could not add double set!\n");
    exit(-1);

  }

  int i;
  for(i = 0; i < plane->xflr_size; i++){
    
    newa[i] = plane->xflr_angles[i];
    newl[i] = plane->xflr_cl[i];
    newd[i] = plane->xflr_cd[i];

  }

  newa[plane->xflr_size] = alpha;
  newl[plane->xflr_size] = cl;
  newd[plane->xflr_size] = cd;
  plane->xflr_size++;
  
  free(plane->xflr_angles);
  free(plane->xflr_cl);
  free(plane->xflr_cd);

  plane->xflr_angles = newa;
  plane->xflr_cl = newl;
  plane->xflr_cd = newd;

  return 0;

}

/*
  method that will return a Plane struct using the information in the
  inputted file, type of plane, vsp boolean
 */
struct Plane newPlane(char* paramfile, char* datafile, int vsp, int type){

  FILE *pfile = fopen(paramfile, "r");
  if(pfile == NULL){ printf("Plane file could not be opened\n"); exit(-1); }

  char* line = NULL;
  size_t len = 0;
  ssize_t read;

  struct Plane plane = makePlaneStruct(type);
  int angles = 0;

  //loop to collect the enum parameters and
  while((read = getline(&line, &len, pfile)) != -1){

    enum Param param = stringToParam(line);
    char* str = paramToString(param);

    if(str != NULL){

      double* testd = doubleSubString(line, param);
      if(testd == NULL){

	printf("Invalid number in line %s\n", line);

      }else{ addParam(&plane, param, *testd); }

    }

    if(subStringIndex(line, "angles:") >= 0){

      int test = getAngles(line, plane.angles);
      if(test != 0){

	printf("Invalid angle input! %s\n", line);

      }else if(plane.angles[0] > plane.angles[1]){

	printf("Invalid inputs, the first angle is larger that the second!\n");

      }else{ angles = 1; }
      
    }
    
  }

  fclose(pfile);

  if(angles == 0){
    
    int good = 1;
    while(good){

      int test = 1;
      while(test){

	printf("Input the first angle: ");
	double* d = getDoubleTerm();
	if(d == NULL){ printf("Invalid input!\n");

	}else{

	  plane.angles[0] = *d;
	  test = 0;

	}

      }

      test = 1;

      while(test){

	printf("Input the second angle: ");
	double* d = getDoubleTerm();
	if(d == NULL){ printf("Invalid input!\n");

	}else{

	  plane.angles[1] = *d;
	  test = 0;

	}

      }

      if(plane.angles[0] > plane.angles[1]){

	printf("Invalid inputs, the first angle is larger that the second!\n");

      }else{ good = 0; }

    }

  }

  FILE * dfile = fopen(datafile, "r");
  if(dfile == NULL){ printf("Plane file could not be opened\n"); exit(-1); }
    
  int header = 0;
  while((read = getline(&line, &len, dfile)) != -1){

    if(header){

      int size;
      double* doubles = getDoubles(line, &size);
      if(doubles != NULL && size != 0){

	if(doubles[0] >= plane.angles[0] && doubles[0] <= plane.angles[1]){

	  printf("angle: %lf\n", doubles[0]);
	  addDouble(&plane, doubles[0], doubles[1], doubles[2]);

	}

      }

    }

    if(subStringIndex(line, "alpha") >= 0 && subStringIndex(line, "CL") >= 0 && subStringIndex(line, "CD") >= 0){ header = 1; }

  }

  fclose(dfile);

  return plane;

}

