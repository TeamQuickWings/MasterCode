#ifndef PLANE_H
#define PLANE_H

/*
  Plane structure that holds the information for the given aircraft
*/
struct Plane{

  double *angles; // usable angle of attackes (deg)
  double wingspan; // wingspan (ft)
  double chord; // chord (ft)
  double swept_angle; // angle of sweep (deg)
  int cruise_alt; // cruise altitude (ft)
  double aoa_c; // angle of attack of the wing at cruise (deg)
  double cruise_vel; // velocity of cruise (knots)
  double max_vel; // max velocity to plot (knots)
  double a_wght; // dry weight (lbf)
  double f_wght; // weight of the fuel (lbf)
  double c_wght; // weight of the cargo (lbf)
  double span_eff_fctr; // span efficiency factor
  double sfc; // the specific fuel consumption
  double prop_eff; // propeller efficiency
  int eng_pwr; // the power of the engine (hp)
  double n_str; // the structure n factor

};

struct Plane makePlane(char* file);

#endif
