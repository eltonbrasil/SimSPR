#define FRESNEL_H

class Fresnel
{
public:

	float n_1 = 1; // Air refractive index
	float n_2 = 1.5168; // Glass refractive index

	float u_1 = 1; // Air relative magnetic permeability
	float u_2 = 1; // Glass relative magnetic permeability 

	double theta_t; // Transmitted angle

	double rp_wave, tp_wave;  // Fresnel terms for the P-polarized wave
	double rs_wave, ts_wave;  // Fresnel terms for the S-polarized wave

	void FresnelTermP(double); // Fresnel equations in their general form for the P_polarized wave
	void FresnelTermS(double); // Fresnel equations in their general form for the S_polarized wave
	
}obj_Fresnel; // Fresnel class object

void Fresnel::FresnelTermP(double theta_i){
	
	theta_t = asin((n_1/n_2)*sin(theta_i*(M_PI/180)));

	double term_1 = (n_1/(u_1*obj_Const.u_0))*cos(theta_t*(M_PI/180));
	double term_2 = (n_2/(u_2*obj_Const.u_0))*cos(theta_i*(M_PI/180));

	rp_wave = (term_1 - term_2) / (term_1 + term_2);

	tp_wave = 2*(n_1/(u_1*obj_Const.u_0))*cos(theta_i*(M_PI/180))/(term_1 + term_2);
}

void Fresnel::FresnelTermS(double theta_i){
	
	theta_t = asin((n_1/n_2)*sin(theta_i*(M_PI/180)));

	double term_1 = (n_1/(u_1*obj_Const.u_0))*cos(theta_i*(M_PI/180));
	double term_2 = (n_2/(u_2*obj_Const.u_0))*cos(theta_t*(M_PI/180));

	rs_wave = (term_1 - term_2) / (term_1 + term_2);

	ts_wave = 2*(n_1/(u_1*obj_Const.u_0))*cos(theta_i*(M_PI/180))/(term_1 + term_2);
}


