#include "fresnel.h"

Fresnel::Fresnel()
{

}

void Fresnel::FresnelTermP(double theta_i)
{
//    theta_t = asin((n_1/n_2)*sin(theta_i*(M_PI/180)));

//    double term_1 = (n_1/(u_1*obj_Const.u_0))*cos(theta_t*(M_PI/180));
//    double term_2 = (n_2/(u_2*obj_Const.u_0))*cos(theta_i*(M_PI/180));

//    rp_wave = (term_1 - term_2) /(term_1 + term_2);

//    tp_wave = 2*(n_1/(u_1*obj_Const.u_0))*cos(theta_i*(M_PI/180))/(term_1+term_2);

}

void Fresnel::FresnelTermS(double theta_i)
{
//    theta_t = asin((n_1/n_2)*sin(theta_i*(M_PI/180)));

//    double term_1 = (n_1/(u_1*obj_Const.u_0))*cos(theta_i*(M_PI/180));
//    double term_2 = (n_2/(u_2*obj_Const.u_0))*cos(theta_t*(M_PI/180));

//    rs_wave = (term_1 - term_2) /(term_1 + term_2);

//    ts_wave = 2*(n_1/(u_1*obj_Const.u_0))*cos(theta_i*(M_PI/180))/(term_1+term_2);

}
