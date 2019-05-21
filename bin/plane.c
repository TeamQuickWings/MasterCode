#include "plane.h"
#include "myfunctions.h"
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

enum Param stringToParam(char* str){

  if(subStringIndex(str, "wingspan") >= 0){ return WINGSPAN;

  }else if(subStringIndex(str, "chord") >= 0){ return CHORD;

  }else if(subStringIndex(str, "swept_angle") >= 0){ return S_ANGLE;

  }else if(subStringIndex(str, "cruise_alt") >= 0){ return CRUISE_ALT;

  }else if(subStringIndex(str, "aoa_at_cruise") >= 0){ return AOA_C;

  }else if(subStringIndex(str, "cruise_velocity") >= 0){ return CRUISE_VEL;

  }else if(subStringIndex(str, "max_velocity") >= 0){ return MAX_VEL;

  }else if(subStringIndex(str, "aircraft_weight") >= 0){ return A_WGHT;

  }else if(subStringIndex(str, "cargo_weight") >= 0){ return C_WGHT;

  }else if(subStringIndex(str, "fuel_weight") >= 0){ return F_WGHT;

  }else if(subStringIndex(str, "span_efficiency_factor") >= 0){ return SPAN_EFF_FCTR;

  }else if(subStringIndex(str, "propeller_efficiency") >= 0){ return PROP_EFF;

  }else if(subStringIndex(str, "engine_power") >= 0){ return ENG_PWR;

  }else if(subStringIndex(str, "n_structure") >= 0){ return N_STR;

  }

  return -1;

}

char* paramToString(enum Param param){

  switch(param){

  case WINGSPAN: return "wingspan";

  case CHORD: return "chord";

  case S_ANGLE: return "swept_angle";

  case CRUISE_ALT: return "cruise_altitude";

  case AOA_C: return "angle_of_attack_at_cruise";

  case CRUISE_VEL: return "cruise_velocity";

  case MAX_VEL: return "max_velocity";

  case A_WGHT: return "aircraft_weight";

  case F_WGHT: return "fuel_weight";

  case C_WGHT: return "cagro_weight";

  case SPAN_EFF_FCTR: return "span_efficiency_factor";

  case PROP_EFF: return "propeller_efficiency";

  case ENG_PWR: return "engine_power";

  case N_STR: return "n_structure";

  }

  return NULL;

}

