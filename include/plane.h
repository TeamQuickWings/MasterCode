#ifndef PLANE_H
#define PLANE_H

enum Param { WINGSPAN, CHORD, S_ANGLE, CRUISE_ALT, AOA_C, CRUISE_VEL, MAX_VEL, A_WGHT, F_WGHT, C_WGHT, SPAN_EFF_FCTR, PROP_EFF, ENG_PWR, N_STR };

/*
  Plane structure that holds the information for the given aircraft
*/
struct Plane{

  double *angles; // usable angle of attackes (deg)
  enum Param *params; // parameters
  double *paramv; // value of the parameters

};

struct Plane makePlane(char* file);
enum Param stringToParam(char* str);
char* paramToString(enum Param param);

#endif
