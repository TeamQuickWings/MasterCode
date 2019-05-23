#ifndef PLANE_H
#define PLANE_H

enum Param { CL_SLOPE, CL0, WINGSPAN, CHORD, S_ANGLE, CRUISE_ALT, AOA_C, CRUISE_VEL, MAX_VEL, A_WGHT, F_WGHT, C_WGHT, CD0, SPAN_EFF_FCTR, SFC, PROP_EFF, ENG_PWR, N_STR };

/*
  Plane structure that holds the information for the given aircraft
*/
struct Plane{

  int type; // type of plane, 0 none, 1 prop, 2 jet, 3 electric
  double angles[2]; // usable angle of attackes (deg)
  enum Param *params; // parameters
  double *paramv; // value of the parameters
  int param_size;

};

enum Param stringToParam(char* str);
char* paramToString(enum Param param);
struct Plane makePlaneStruct(int type);
int findParam(struct Plane plane, enum Param param);
int addParam(struct Plane* plane, enum Param param, double value);
double getValue(struct Plane* plane, enum Param param);
double* doubleSubString(char* str, enum Param param);
int getAngles(char* str, double* angles);
struct Plane newPlane(char* file, int type);

#endif
