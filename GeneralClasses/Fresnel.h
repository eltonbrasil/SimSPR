#include "PhysicalConstants.h"
#define FRESNEL_H

class Fresnel
{
private:
	float n_1 = 1; // Air refractive index
	float n_2 = 0.27732; // Gold refractive index

	float mu_1 = 1; // Air relative magnetic permeability
	float mu_2 = 0.99996; // Gold relative magnetic permeability 

	double theta_t = 0; // Transmitted Angle
	double rp_wave, tp_wave;  // Fresnel terms for the P-polarized wave
	double theta_i; // Incident Angle
public:
	
	void FresnelTermP(float, float);
	void FresnelTermS(float, float);
	int SnellTerms();

}obj_Fresnel;

void Fresnel::FresnelTermP(float theta_i, float theta_t){
	
}

void Fresnel::FresnelTermS(float theta_i, float theta_t){
	
}

int Fresnel::SnellTerms(){
	
	for(obj_Fresnel.theta_i = 0; obj_Fresnel.theta_i <= 360; obj_Fresnel.theta_i ++){ //  in Degrees
		obj_Fresnel.theta_t = (obj_Fresnel.n_1/obj_Fresnel.n_2)*sin(obj_Fresnel.theta_i*(M_PI/180));

		std::cout<<asin(obj_Fresnel.theta_t)*(180/M_PI); // Results in degrees
		std::cout<<"\n\n";
	}
		
	return(asin(obj_Fresnel.theta_t)*(180/M_PI));
}

