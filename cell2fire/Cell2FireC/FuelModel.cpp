#include "FuelModel.h"

#include <iostream>
#include <math.h>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

/*
	Global coefficients
*/  
std::unordered_map<int, std::vector<float>> fmcs;
std::unordered_map<int, std::vector<float>> cbhs;
std::unordered_map<int, std::vector<float>> fls;
std::unordered_map<int, std::vector<float>> hs;

 
/*
	Functions
*/

void setup_const()
{
    //printf("dlw debug, enter fuel_coefs\n");
    /*   fuel type 1 */
    int PCH1 = 1;
    std::vector<float> fmc_pch1;
    std::vector<float> cbh_pch1;
    std::vector<float> fl_pch1;
    std::vector<float> h_pch1;
    fmc_pch1.push_back(0.018880);
    cbh_pch1.push_back(0.0282);
    fl_pch1.push_back(0.918);
    h_pch1.push_back(3328);
    fmcs.insert(std::make_pair(PCH1, fmc_pch1));
    cbhs.insert(std::make_pair(PCH1, cbh_pch1));
    fls.insert(std::make_pair(PCH1, fl_pch1));
    hs.insert(std::make_pair(PCH1, h_pch1));

    int PCH2 = 2;
    std::vector<float> fmc_pch2;
    std::vector<float> cbh_pch2;
    std::vector<float> fl_pch2;
    std::vector<float> h_pch2;
    fmc_pch2.push_back(0.016027);
    cbh_pch2.push_back(0.0282);
    fl_pch2.push_back(0.617);
    h_pch2.push_back(3928);
    fmcs.insert(std::make_pair(PCH2, fmc_pch2));
    cbhs.insert(std::make_pair(PCH2, cbh_pch2));
    fls.insert(std::make_pair(PCH2, fl_pch2));
    hs.insert(std::make_pair(PCH2, h_pch2));

    int PCH3 = 3;
    std::vector<float> fmc_pch3;
    std::vector<float> cbh_pch3;
    std::vector<float> fl_pch3;
    std::vector<float> h_pch3;
    fmc_pch3.push_back(0.010235);
    cbh_pch3.push_back(0.0282);
    fl_pch3.push_back(0.684);
    h_pch3.push_back(3928);
    fmcs.insert(std::make_pair(PCH3, fmc_pch3));
    cbhs.insert(std::make_pair(PCH3, cbh_pch3));
    fls.insert(std::make_pair(PCH3, fl_pch3));
    hs.insert(std::make_pair(PCH3, h_pch3));

    int PCH4 = 4;
    std::vector<float> fmc_pch4;
    std::vector<float> cbh_pch4;
    std::vector<float> fl_pch4;
    std::vector<float> h_pch4;
    fmc_pch4.push_back(0.008690);
    cbh_pch4.push_back(0.0282);
    fl_pch4.push_back(0.527);
    h_pch4.push_back(3928);
    fmcs.insert(std::make_pair(PCH4, fmc_pch4));
    cbhs.insert(std::make_pair(PCH4, cbh_pch4));
    fls.insert(std::make_pair(PCH4, fl_pch4));
    hs.insert(std::make_pair(PCH4, h_pch4));

    int PCH5 = 5;
    std::vector<float> fmc_pch5;
    std::vector<float> cbh_pch5;
    std::vector<float> fl_pch5;
    std::vector<float> h_pch5;
    fmc_pch5.push_back(0.001009);
    cbh_pch5.push_back(0.0282);
    fl_pch5.push_back(0.649);
    h_pch5.push_back(3800);
    fmcs.insert(std::make_pair(PCH5, fmc_pch5));
    cbhs.insert(std::make_pair(PCH5, cbh_pch5));
    fls.insert(std::make_pair(PCH5, fl_pch5));
    hs.insert(std::make_pair(PCH5, h_pch5));

    int MT01 = 6;
    std::vector<float> fmc_mt01;
    std::vector<float> cbh_mt01;
    std::vector<float> fl_mt01;
    std::vector<float> h_mt01;
    fmc_mt01.push_back(0.007603);
    cbh_mt01.push_back(0.0282);
    fl_mt01.push_back(2.923);
    h_mt01.push_back(4693);
    fmcs.insert(std::make_pair(MT01, fmc_mt01));
    cbhs.insert(std::make_pair(MT01, cbh_mt01));
    fls.insert(std::make_pair(MT01, fl_mt01));
    hs.insert(std::make_pair(MT01, h_mt01));

    int MT02 = 7;
    std::vector<float> fmc_mt02;
    std::vector<float> cbh_mt02;
    std::vector<float> fl_mt02;
    std::vector<float> h_mt02;
    fmc_mt02.push_back(0.008147);
    cbh_mt02.push_back(0.0282);
    fl_mt02.push_back(1.910);
    h_mt02.push_back(4693);
    fmcs.insert(std::make_pair(MT02, fmc_mt02));
    cbhs.insert(std::make_pair(MT02, cbh_mt02));
    fls.insert(std::make_pair(MT02, fl_mt02));
    hs.insert(std::make_pair(MT02, h_mt02));

    int MT03 = 8;
    std::vector<float> fmc_mt03;
    std::vector<float> cbh_mt03;
    std::vector<float> fl_mt03;
    std::vector<float> h_mt03;
    fmc_mt03.push_back(0.001672);
    cbh_mt03.push_back(0.0282);
    fl_mt03.push_back(3.308);
    h_mt03.push_back(4572);
    fmcs.insert(std::make_pair(MT03, fmc_mt03));
    cbhs.insert(std::make_pair(MT03, cbh_mt03));
    fls.insert(std::make_pair(MT03, fl_mt03));
    hs.insert(std::make_pair(MT03, h_mt03));

    int MT04 = 9;
    std::vector<float> fmc_mt04;
    std::vector<float> cbh_mt04;
    std::vector<float> fl_mt04;
    std::vector<float> h_mt04;
    fmc_mt04.push_back(0.004886);
    cbh_mt04.push_back(0.0282);
    fl_mt04.push_back(1.383);
    h_mt04.push_back(4572);
    fmcs.insert(std::make_pair(MT04, fmc_mt04));
    cbhs.insert(std::make_pair(MT04, cbh_mt04));
    fls.insert(std::make_pair(MT04, fl_mt04));
    hs.insert(std::make_pair(MT04, h_mt04));

    int MT05 = 10;
    std::vector<float> fmc_mt05;
    std::vector<float> cbh_mt05;
    std::vector<float> fl_mt05;
    std::vector<float> h_mt05;
    fmc_mt05.push_back(0.010321);
    cbh_mt05.push_back(0.0282);
    fl_mt05.push_back(3.029);
    h_mt05.push_back(5000);
    fmcs.insert(std::make_pair(MT05, fmc_mt05));
    cbhs.insert(std::make_pair(MT05, cbh_mt05));
    fls.insert(std::make_pair(MT05, fl_mt05));
    hs.insert(std::make_pair(MT05, h_mt05));
    
    int MT06 = 11;
    std::vector<float> fmc_mt06;
    std::vector<float> cbh_mt06;
    std::vector<float> fl_mt06;
    std::vector<float> h_mt06;
    fmc_mt06.push_back(0.009234);
    cbh_mt06.push_back(0.0282);
    fl_mt06.push_back(3.529);
    h_mt06.push_back(5087);
    fmcs.insert(std::make_pair(MT06, fmc_mt06));
    cbhs.insert(std::make_pair(MT06, cbh_mt06));
    fls.insert(std::make_pair(MT06, fl_mt06));
    hs.insert(std::make_pair(MT06, h_mt06));

    int MT07 = 12;
    std::vector<float> fmc_mt07;
    std::vector<float> cbh_mt07;
    std::vector<float> fl_mt07;
    std::vector<float> h_mt07;
    fmc_mt07.push_back(0.001787);
    cbh_mt07.push_back(0.0282);
    fl_mt07.push_back(3.189);
    h_mt07.push_back(4500);
    fmcs.insert(std::make_pair(MT07, fmc_mt07));
    cbhs.insert(std::make_pair(MT07, cbh_mt07));
    fls.insert(std::make_pair(MT07, fl_mt07));
    hs.insert(std::make_pair(MT07, h_mt07));

    int MT08 = 13;
    std::vector<float> fmc_mt08;
    std::vector<float> cbh_mt08;
    std::vector<float> fl_mt08;
    std::vector<float> h_mt08;
    fmc_mt08.push_back(0.004342);
    cbh_mt08.push_back(0.0282);
    fl_mt08.push_back(1.903);
    h_mt08.push_back(4500);
    fmcs.insert(std::make_pair(MT08, fmc_mt08));
    cbhs.insert(std::make_pair(MT08, cbh_mt08));
    fls.insert(std::make_pair(MT08, fl_mt08));
    hs.insert(std::make_pair(MT08, h_mt08));

    int BN01 = 14;
    std::vector<float> fmc_bn01;
    std::vector<float> cbh_bn01;
    std::vector<float> fl_bn01;
    std::vector<float> h_bn01;
    fmc_bn01.push_back(0.002249);
    cbh_bn01.push_back(0.0282);
    fl_bn01.push_back(2.624);
    h_bn01.push_back(4600);
    fmcs.insert(std::make_pair(BN01, fmc_bn01));
    cbhs.insert(std::make_pair(BN01, cbh_bn01));
    fls.insert(std::make_pair(BN01, fl_bn01));
    hs.insert(std::make_pair(BN01, h_bn01));

    int BN02 = 15;
    std::vector<float> fmc_bn02;
    std::vector<float> cbh_bn02;
    std::vector<float> fl_bn02;
    std::vector<float> h_bn02;
    fmc_bn02.push_back(0.001441);
    cbh_bn02.push_back(0.0282);
    fl_bn02.push_back(2.310);
    h_bn02.push_back(4550);
    fmcs.insert(std::make_pair(BN02, fmc_bn02));
    cbhs.insert(std::make_pair(BN02, cbh_bn02));
    fls.insert(std::make_pair(BN02, fl_bn02));
    hs.insert(std::make_pair(BN02, h_bn02));

    int BN03 = 16;
    std::vector<float> fmc_bn03;
    std::vector<float> cbh_bn03;
    std::vector<float> fl_bn03;
    std::vector<float> h_bn03;
    fmc_bn03.push_back(0.000979);
    cbh_bn03.push_back(0.0282);
    fl_bn03.push_back(3.544);
    h_bn03.push_back(4452);
    fmcs.insert(std::make_pair(BN03, fmc_bn03));
    cbhs.insert(std::make_pair(BN03, cbh_bn03));
    fls.insert(std::make_pair(BN03, fl_bn03));
    hs.insert(std::make_pair(BN03, h_bn03));
    
    int BN04 = 17;
    std::vector<float> fmc_bn04;
    std::vector<float> cbh_bn04;
    std::vector<float> fl_bn04;
    std::vector<float> h_bn04;
    fmc_bn04.push_back(0.001556);
    cbh_bn04.push_back(0.0282);
    fl_bn04.push_back(2.164);
    h_bn04.push_back(4452);
    fmcs.insert(std::make_pair(BN04, fmc_bn04));
    cbhs.insert(std::make_pair(BN04, cbh_bn04));
    fls.insert(std::make_pair(BN04, fl_bn04));
    hs.insert(std::make_pair(BN04, h_bn04));

    int BN05 = 18;
    std::vector<float> fmc_bn05;
    std::vector<float> cbh_bn05;
    std::vector<float> fl_bn05;
    std::vector<float> h_bn05;
    fmc_bn05.push_back(0.002365);
    cbh_bn05.push_back(0.0282);
    fl_bn05.push_back(1.954);
    h_bn05.push_back(4452);
    fmcs.insert(std::make_pair(BN05, fmc_bn05));
    cbhs.insert(std::make_pair(BN05, cbh_bn05));
    fls.insert(std::make_pair(BN05, fl_bn05));
    hs.insert(std::make_pair(BN05, h_bn05));

    int PL01 = 19;
    std::vector<float> fmc_pl01;
    std::vector<float> cbh_pl01;
    std::vector<float> fl_pl01;
    std::vector<float> h_pl01;
    fmc_pl01.push_back(0.013174);
    cbh_pl01.push_back(0.0282);
    fl_pl01.push_back(0.838);
    h_pl01.push_back(4399);
    fmcs.insert(std::make_pair(PL01, fmc_pl01));
    cbhs.insert(std::make_pair(PL01, cbh_pl01));
    fls.insert(std::make_pair(PL01, fl_pl01));
    hs.insert(std::make_pair(PL01, h_pl01));

    int PL02 = 20;
    std::vector<float> fmc_pl02;
    std::vector<float> cbh_pl02;
    std::vector<float> fl_pl02;
    std::vector<float> h_pl02;
    fmc_pl02.push_back(0.005973);
    cbh_pl02.push_back(0.0282);
    fl_pl02.push_back(3.019);
    h_pl02.push_back(4870);
    fmcs.insert(std::make_pair(PL02, fmc_pl02));
    cbhs.insert(std::make_pair(PL02, cbh_pl02));
    fls.insert(std::make_pair(PL02, fl_pl02));
    hs.insert(std::make_pair(PL02, h_pl02));

    int PL03 = 21;
    std::vector<float> fmc_pl03;
    std::vector<float> cbh_pl03;
    std::vector<float> fl_pl03;
    std::vector<float> h_pl03;
    fmc_pl03.push_back(0.002481);
    cbh_pl03.push_back(0.0282);
    fl_pl03.push_back(3.333);
    h_pl03.push_back(4870);
    fmcs.insert(std::make_pair(PL03, fmc_pl03));
    cbhs.insert(std::make_pair(PL03, cbh_pl03));
    fls.insert(std::make_pair(PL03, fl_pl03));
    hs.insert(std::make_pair(PL03, h_pl03));

    int PL04 = 22;
    std::vector<float> fmc_pl04;
    std::vector<float> cbh_pl04;
    std::vector<float> fl_pl04;
    std::vector<float> h_pl04;
    fmc_pl04.push_back(0.002712);
    cbh_pl04.push_back(0.0282);
    fl_pl04.push_back(3.249);
    h_pl04.push_back(4870);
    fmcs.insert(std::make_pair(PL04, fmc_pl04));
    cbhs.insert(std::make_pair(PL04, cbh_pl04));
    fls.insert(std::make_pair(PL04, fl_pl04));
    hs.insert(std::make_pair(PL04, h_pl04));

    int PL05 = 23;
    std::vector<float> fmc_pl05;
    std::vector<float> cbh_pl05;
    std::vector<float> fl_pl05;
    std::vector<float> h_pl05;
    fmc_pl05.push_back(0.006516);
    cbh_pl05.push_back(0.0282);
    fl_pl05.push_back(4.087);
    h_pl05.push_back(4870);
    fmcs.insert(std::make_pair(PL05, fmc_pl05));
    cbhs.insert(std::make_pair(PL05, cbh_pl05));
    fls.insert(std::make_pair(PL05, fl_pl05));
    hs.insert(std::make_pair(PL05, h_pl05));

    int PL06 = 24;
    std::vector<float> fmc_pl06;
    std::vector<float> cbh_pl06;
    std::vector<float> fl_pl06;
    std::vector<float> h_pl06;
    fmc_pl06.push_back(0.003255);
    cbh_pl06.push_back(0.0282);
    fl_pl06.push_back(3.714);
    h_pl06.push_back(4870);
    fmcs.insert(std::make_pair(PL06, fmc_pl06));
    cbhs.insert(std::make_pair(PL06, cbh_pl06));
    fls.insert(std::make_pair(PL06, fl_pl06));
    hs.insert(std::make_pair(PL06, h_pl06));

    int PL07 = 25;
    std::vector<float> fmc_pl07;
    std::vector<float> cbh_pl07;
    std::vector<float> fl_pl07;
    std::vector<float> h_pl07;
    fmc_pl07.push_back(0.002596);
    cbh_pl07.push_back(0.0282);
    fl_pl07.push_back(4.063);
    h_pl07.push_back(4870);
    fmcs.insert(std::make_pair(PL07, fmc_pl07));
    cbhs.insert(std::make_pair(PL07, cbh_pl07));
    fls.insert(std::make_pair(PL07, fl_pl07));
    hs.insert(std::make_pair(PL07, h_pl07));

    int PL08 = 26;
    std::vector<float> fmc_pl08;
    std::vector<float> cbh_pl08;
    std::vector<float> fl_pl08;
    std::vector<float> h_pl08;
    fmc_pl08.push_back(0.009777);
    cbh_pl08.push_back(0.0282);
    fl_pl08.push_back(0.905);
    h_pl08.push_back(4372);
    fmcs.insert(std::make_pair(PL08, fmc_pl08));
    cbhs.insert(std::make_pair(PL08, cbh_pl08));
    fls.insert(std::make_pair(PL08, fl_pl08));
    hs.insert(std::make_pair(PL08, h_pl08));

    int PL09 = 27;
    std::vector<float> fmc_pl09;
    std::vector<float> cbh_pl09;
    std::vector<float> fl_pl09;
    std::vector<float> h_pl09;
    fmc_pl09.push_back(0.005429);
    cbh_pl09.push_back(0.0282);
    fl_pl09.push_back(3.164);
    h_pl09.push_back(4816);
    fmcs.insert(std::make_pair(PL09, fmc_pl09));
    cbhs.insert(std::make_pair(PL09, cbh_pl09));
    fls.insert(std::make_pair(PL09, fl_pl09));
    hs.insert(std::make_pair(PL09, h_pl09));

    int PL10 = 28;
    std::vector<float> fmc_pl10;
    std::vector<float> cbh_pl10;
    std::vector<float> fl_pl10;
    std::vector<float> h_pl10;
    fmc_pl10.push_back(0.003799);
    cbh_pl10.push_back(0.0282);
    fl_pl10.push_back(2.742);
    h_pl10.push_back(4816);
    fmcs.insert(std::make_pair(PL10, fmc_pl10));
    cbhs.insert(std::make_pair(PL10, cbh_pl10));
    fls.insert(std::make_pair(PL10, fl_pl10));
    hs.insert(std::make_pair(PL10, h_pl10));

    int PL11 = 29;
    std::vector<float> fmc_pl11;
    std::vector<float> cbh_pl11;
    std::vector<float> fl_pl11;
    std::vector<float> h_pl11;
    fmc_pl11.push_back(0.001325);
    cbh_pl11.push_back(0.0282);
    fl_pl11.push_back(2.464);
    h_pl11.push_back(4684);
    fmcs.insert(std::make_pair(PL11, fmc_pl11));
    cbhs.insert(std::make_pair(PL11, cbh_pl11));
    fls.insert(std::make_pair(PL11, fl_pl11));
    hs.insert(std::make_pair(PL11, h_pl11));

    int DX01 = 30;
    std::vector<float> fmc_dx01;
    std::vector<float> cbh_dx01;
    std::vector<float> fl_dx01;
    std::vector<float> h_dx01;
    fmc_dx01.push_back(0.002134);
    cbh_dx01.push_back(0.0282);
    fl_dx01.push_back(8.25);
    h_dx01.push_back(4746);
    fmcs.insert(std::make_pair(DX01, fmc_dx01));
    cbhs.insert(std::make_pair(DX01, cbh_dx01));
    fls.insert(std::make_pair(DX01, fl_dx01));
    hs.insert(std::make_pair(DX01, h_dx01));

    int DX02 = 31;
    std::vector<float> fmc_dx02;
    std::vector<float> cbh_dx02;
    std::vector<float> fl_dx02;
    std::vector<float> h_dx02;
    fmc_dx02.push_back(0.001903);
    cbh_dx02.push_back(0.0282);
    fl_dx02.push_back(7.125);
    h_dx02.push_back(4652);
    fmcs.insert(std::make_pair(DX02, fmc_dx02));
    cbhs.insert(std::make_pair(DX02, cbh_dx02));
    fls.insert(std::make_pair(DX02, fl_dx02));
    hs.insert(std::make_pair(DX02, h_dx02));


}


float rate_of_spread(inputs *data, fuel_coefs *ptr, main_outs *at)
   {
    float p1, p2, p3, ws, tmp, rh, ch, fmc, fch, fv, ps,fp;
   
   //se = slope_effect(inp) ;
   ws = data->ws;
   tmp = data->tmp;
   rh = data->rh;
   ps = data->ps;
   p1 = -12.86;
   p2 = 0.04316;
   p3 = 13.8;

   ch = (-2.97374 + 0.262 * rh - 0.00982 * tmp);
   fmc = fmcs[data->nftype][0]*60; //factor de propagacion en m/min
   fch = (389.1624 + 14.3 * ch + 0.02 * pow(ch, 2.0)) / (3.559 + 1.6615 * ch + 2.62392 * pow(ch, 2.0)); //es -14.3 segun el libro
   fv = p1 * exp(-p2 * ws) + p3;
   at->rss = fmc*fch*(fv); 
   
   return at->rss * (at->rss >= 0) ;

   }

float flankfire_ros(float ros,float bros,float lb)
   {
      return  ((ros + bros) / ( lb * 2.0)) ;
   }

/* ----------------- Length-to-Breadth --------------------------*/
float l_to_b(float ws, fuel_coefs *ptr)
  {
    float l1, l2, lb ;
    l1 = 2.233;//1.411; // ptr->l1 ;
    l2 = -0.01031; //0.01745; // ptr->l2 ;
	lb = 1.0 + pow(l1 * exp(-l2 * ws) - l1, 2.0) ;
    return lb;
  }

/* ----------------- Back Rate of Spread --------------------------*/
float backfire_ros(main_outs *at, snd_outs *sec)
  {
    float hb, bros, lb ;
    //lb = l_to_b(data->fueltype,at->wsv) ;
    lb = sec->lb ;
    hb = (lb + sqrt(pow(lb,2) - 1.0)) /  (lb - sqrt(pow(lb, 2) - 1.0)) ;

    bros = at->rss / hb ;
    
    return bros * (bros >= 0);
  }

float flame_length(inputs *data, fuel_coefs *ptr) //REVISAR ESTA ECUACIÓN
   {
       float q1, q2, q3, fl, ws ;

       ws = data->ws ;
       q1 = 2 ;
       q2 = 2 ;
       q3 = 2 ; 

       fl = pow(q1 * exp(-q2 * ws) + q3, 2) ;
       return fl; 
   }

float angleFL(inputs *data, fuel_coefs *ptr)
   {
       float angle, fl, y, ws ;
       ws = data->ws ;
       fl = flame_length(data, ptr) ;
       y = 10.0 / 36.0 * ws ;

       angle = atan(2.24 * sqrt(fl / pow(y, 2)))  ;
       return angle;
   }

float flame_height(inputs *data, fuel_coefs *ptr)
  {
      float fh, phi ;
      phi = angleFL(data, ptr) ;
      fh = flame_length(data, ptr) * sin(phi) ;
      return fh ;
  }

float byram_intensity(main_outs* at, fuel_coefs* ptr) {
    float fl, ib;
    fl = at->fl;
    ib = 259.833 * pow(fl, 2.174);
    ib = std::ceil(ib * 100.0) / 100.0;
    return ib;
}

int fmc_scen(int scenario) {
    int fmc;
    fmc = 120; //hacer forma de ingresarlo manualmente
    return fmc;
}

bool fire_type(inputs *data, main_outs* at)
  {
      float intensity, critical_intensity, cbh;
      int fmc;
      bool crownFire = false;
      intensity = at->byram;
      cbh = data->cbh;
      fmc = fmc_scen(3); //modificar para ingresar manualmente
      critical_intensity = pow((0.01 * cbh * (460 + 25.9 * fmc)), 1.5);

      if ((intensity > critical_intensity) && cbh != 0) crownFire = true;
      return crownFire ;
  }

float rate_of_spread10(inputs *data)
   {
   // FM 10 coef
   float p1 = 0.2802, p2 = 0.07786, p3 = 0.01123 ;
   float ros, ros10, ws, ffros, fcbd, fccf;

   ffros = data->factor_ros10 ;
   fcbd  = data->factor_cbd ;
   fccf  = data->factor_ccf ;
   
   ws = data->ws ;
   ros10 = 1. / (p1 * exp(-p2 * ws) + p3) ;
   ros = ffros * ros10 + fccf * data->ccf + fcbd * data->factor_cbd ;
   
   return(ros);
   }
 
float backfire_ros10(fire_struc *hptr, snd_outs *sec)
  {
    float hb, bros, lb ;
    lb = sec->lb ;
    hb = (lb + sqrt(pow(lb, 2) - 1.0)) /  (lb - sqrt(pow(lb, 2) - 1.0)) ;

    bros = hptr->ros / hb ;
    
    return bros;
  }
  
 void calculate(inputs *data,  fuel_coefs * ptr, main_outs *at, snd_outs *sec, fire_struc *hptr, fire_struc *fptr,fire_struc *bptr)
{
    // Hack: Initialize coefficients 
    setup_const();

	// Aux
	float  ros, bros, lb, fros;
	bool crownFire;
    // const;
    
    // Populate fuel coefs struct
	//ptr->fueltype = data->fueltype;
	if (data->verbose){
		std::cout  << "Populate fuel types " <<  std::endl;
		std::cout  << "NfTypes:"  << data->nftype <<  std::endl;
		std::cout  << "scen:"  << data->scen <<  std::endl;
	}
    
	ptr->nftype = data->nftype;
    //cout << "   tipo " << data->nftype << "\n";
    //std::cout << "hola:" << fmcs[data->nftype][0] << std::endl;

    ptr->fmc = fmcs[data->nftype][0];
    //cout << "   fmc combustible " << ptr->fmc << "\n";

    ptr->cbh = cbhs[data->nftype][0];
    //cout << "   cbh " << ptr->cbh << "\n";

    ptr->fl = fls[data->nftype][0];
    //cout << "   fl " << ptr->fl << "\n";

    ptr->h = hs[data->nftype][0];
    //cout << "   h " << ptr->h << "\n";

    // Step 1: Calculate HROS (surface)
    at->rss = rate_of_spread(data, ptr, at);
    hptr->rss = at->rss ;
	
    
    // Step 2: Calculate Length-to-breadth
    sec->lb = l_to_b(data->ws, ptr) ;
    
    // Step 3: Calculate BROS (surface)
    bptr->rss = backfire_ros(at, sec) ;
    
    // Step 4: Calculate central FROS (surface)
    fptr->rss = flankfire_ros(hptr->rss, bptr->rss, sec->lb);
    
    // Step 5: Ellipse components
    at->a = (hptr->rss + bptr->rss) / 2. ;
    at->b = (hptr->rss + bptr->rss) / (2. * sec->lb) ; 
    at->c = (hptr->rss - bptr->rss) / 2. ; 
    
    // Step 6: Flame Length
    at->fl = flame_length(data, ptr);
    
    // Step 7: Flame angle
    at->angle = angleFL(data, ptr) ;
    
	// Step 8: Flame Height
    at->fh = flame_height(data, ptr) ;

    // Step 9: Byram Intensity
    at->byram = byram_intensity(at, ptr);
    
	// Step 10: Criterion for Crown Fire Initiation (no init if user does not want to include it)
    if (data->cros) {
        crownFire = fire_type(data, at);
        if (data->verbose) {
            cout << "Checking crown Fire conditions " << crownFire << "\n";
        }
    }
    else {
        crownFire = false;
    }



	// If we have Crown fire, update the ROSs
    if (crownFire){
            hptr->ros = rate_of_spread10(data) ;
            bptr->ros = backfire_ros10(hptr,sec) ;
            fptr->ros = flankfire_ros(hptr->ros, bptr->ros, sec->lb) ;
            
			if (data->verbose){
				cout << "hptr->ros = " << hptr->ros << "\n" ;
				cout << "bptr->ros = " << bptr->ros << "\n" ;
				cout << "fptr->ros = " << fptr->ros << "\n" ;
			}

            at->a = (hptr->ros + bptr->ros) / 2. ;
            at->b = (hptr->ros + bptr->ros) / (2. * sec->lb) ; 
            at->c = (hptr->ros - bptr->rss) / 2 ; 
			at->cros = true;
    }
	
	// Otherwise, use the surface alues
    else{
        hptr->ros = hptr->rss ;
        bptr->ros = bptr->rss ; 
        fptr->ros = fptr->rss ;
		if (data->verbose){
			cout << "hptr->ros = " << hptr->ros << "\n" ;
			cout << "bptr->ros = " << bptr->ros << "\n" ;
			cout << "fptr->ros = " << fptr->ros << "\n" ;
		}
    }
	
	if (data->verbose){
		cout << "--------------- Inputs --------------- \n" ;
		cout << "ws = " << data->ws << "\n" ;
		cout << "coef data->cbh = " << data->cbh << "\n" ;
		cout << "coef ptr->fmc = " << ptr->fmc << "\n" ;
		cout << "coef ptr->cbh = " << ptr->cbh << "\n" ;
		cout << "coef ptr->fl = " << ptr->fl << "\n" ;
		cout << "coef ptr->h = " << ptr->h << "\n" ;
		//cout << "coef ptr->q2 = " << ptr->q2 << "\n" ;
		//cout << "coef ptr->q3 = " << ptr->q3 << "\n" ;
		cout << "\n" ;

		cout << "---------------- Outputs --------------- \n" ;
		cout << "at->rss = " << at->rss << "\n" ;
		cout << "hptr->rss = " << hptr->rss << "\n" ;
		cout << "lb = " << sec->lb << "\n" ;
		cout << "bptr->rss = " << bptr->rss << "\n" ;
		cout << "fptr->rss = " << fptr->rss << "\n" ;
		cout << "axis a = " << at->a << "\n" ;
		cout << "axis b = " << at->b << "\n" ;
		cout << "axis c = " << at->c << "\n" ;
		cout << "fl = " << at->fl << "\n";
		cout << "angle = " << at->angle << "\n";
		cout << "fh = " << at->fh << "\n";
		cout << "Crown Fire = " << crownFire << "\n";
	}
}

void determine_destiny_metrics(inputs* data, fuel_coefs* ptr, main_outs* metrics) {
    // Hack: Initialize coefficients 
    setup_const();

    // Aux
    float  ros, bros, lb, fros;
    bool crownFire = false;

    //ptr->q1 = q_coeff[data->nftype][0];
    //ptr->q2 = q_coeff[data->nftype][1];
    //ptr->q3 = q_coeff[data->nftype][2];
    ptr->nftype = data->nftype;
    // Step 6: Flame Length
    metrics->fl = flame_length(data, ptr);
    // Step 9: Byram Intensity
    metrics->byram = byram_intensity(metrics, ptr);

    // Step 10: Criterion for Crown Fire Initiation (no init if user does not want to include it)
    if (data->cros) {
        crownFire = fire_type(data, metrics);
        if (data->verbose) {
            cout << "Checking crown Fire conditions " << crownFire << "\n";
        }
    }
    else {
        crownFire = false;
    }

    metrics->cros = crownFire;
}
