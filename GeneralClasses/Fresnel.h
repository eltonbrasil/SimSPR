#define FRESNEL_H

class Fresnel
{
public:

	float n_1 = 1; // Air refractive index
	float n_2 = 0.27732; // Gold refractive index

	float u_1 = 1; // Air relative magnetic permeability
	float u_2 = 0.99996; // Gold relative magnetic permeability 

	float theta_t;

	float rp_wave, tp_wave;  // Fresnel terms for the P-polarized wave
	float rs_wave, ts_wave;  // Fresnel terms for the S-polarized wave

	void FresnelTermP(int); // Fresnel equations in their general form for the P_polarized wave
	void FresnelTermS(int); // Fresnel equations in their general form for the S_polarized wave
	
}obj_Fresnel; // Fresnel class object

void Fresnel::FresnelTermP(int theta_i){
	
	theta_t = asin((obj_Fresnel.n_1/obj_Fresnel.n_2)*sin(theta_i*(M_PI/180)));

	float term_1 = (obj_Fresnel.n_1/(obj_Fresnel.u_1*obj_Const.u_0))*cos(theta_t);
	float term_2 = (obj_Fresnel.n_2/(obj_Fresnel.u_2*obj_Const.u_0))*cos(theta_i);

	obj_Fresnel.rp_wave = (term_1 - term_2) / (term_1 + term_2);

	obj_Fresnel.tp_wave = 2*(obj_Fresnel.n_1/(obj_Fresnel.u_1*obj_Const.u_0))*cos(theta_i)/(term_1 + term_2);
}

void Fresnel::FresnelTermS(int theta_i){
	
	float theta_t = asin((obj_Fresnel.n_1/obj_Fresnel.n_2)*sin(theta_i*(M_PI/180)));

	float term_1 = (obj_Fresnel.n_1/(obj_Fresnel.u_1*obj_Const.u_0))*cos(theta_i);
	float term_2 = (obj_Fresnel.n_2/(obj_Fresnel.u_2*obj_Const.u_0))*cos(theta_t);

	obj_Fresnel.rs_wave = (term_1 - term_2) / (term_1 + term_2);

	obj_Fresnel.ts_wave = 2*(obj_Fresnel.n_1/(obj_Fresnel.u_1*obj_Const.u_0))*cos(theta_i)/(term_1 + term_2);
}


