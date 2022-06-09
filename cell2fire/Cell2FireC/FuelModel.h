#ifndef FUELMODELSPAIN
#define FUELMODELSPAIN

#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <unordered_map>
#include <string>
#include <vector>

/*
*  Input, Fire, and output structures
*/

typedef struct
   { char fueltype[4];
     float ws, saz, cur, ps, cbh, ccf, cbd, elev ;
     int waz, scen, nftype;
     float factor_cbd, factor_ccf, factor_ros10, factor_actv ;
	 bool cros, verbose;
   } inputs;


typedef struct
  { char fueltype[4] ;
    float p1, p2, p3 ;    // hros coef
    float q1, q2, q3 ; // flame length coef
	int nftype; 
  } fuel_coefs;
  
  typedef struct
  { float fl, fh, a, b, c, rss, angle, byram;
     char covertype;
	 bool cros;
  } main_outs;

typedef struct
  { float ros, rss;
    double fi;
  } fire_struc;

  typedef struct
  { float lb, area, perm, pgr, lbt;
  } snd_outs;


 /*
		Functions
 */
 // Initialize coefficients
 void initialize_coeff(int scenario);
 
 // Calculate flank fire 
float flankfire_ros(float ros, float bros, float lb) ;

// Calculate rate of spread
float rate_of_spread(inputs *data, fuel_coefs *ptr, main_outs *at) ;

// Length-to-Breadth ratio
float l_to_b(float ws);

// BROS
float backfire_ros(main_outs *at, snd_outs *sec) ;

// Flame length [m])
float flame_length(inputs *data, fuel_coefs *ptr);

// Angle of the flame w.r.t. horizontal surface (Putnam's)
float angleFL(inputs *data, fuel_coefs *ptr) ;

// Transformation from FL to FH using angle 
float flame_height(inputs *data, fuel_coefs *ptr) ;

//byram intensity
float byram_intensity(inputs* data, fuel_coefs* ptr);

// Type of fire (Crown = 1, SROS = 0)
bool fire_type(inputs *data, fuel_coefs *ptr) ;

// CROS adjustements
float rate_of_spread10(inputs *data) ;

// Back fire with CROS 
float backfire_ros10(fire_struc *hptr, snd_outs *sec) ;

// Slope effect
float slope_effect(inputs * data);

// Main function to populate spread outputs based on inputs provided from main class
void calculate(inputs *data,  fuel_coefs * ptr, main_outs *at, snd_outs *sec, fire_struc *hptr, fire_struc *fptr,fire_struc *bptr);

void determine_destiny_metrics(inputs* data, fuel_coefs* ptr, main_outs* at);


#endif
