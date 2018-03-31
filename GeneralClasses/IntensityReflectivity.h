#define INTENSITYREFLECTIVITY_H

class IntensityReflectivity
{
public:
	double Rp; // Intensity reflection for P-polarized wave
	double Rs; // Intensity reflection for S-polarized wave
	double Tp; // Intensity transmissivities coefficient for P-polarized wave
	double Ts; // Intensity transmissivities coefficient for S-polarized wave

	void IntensityReflection (double);
	void IntensityTransmissivity ();
	
}obj_Intensity;

void IntensityReflectivity::IntensityReflection (double theta_i){

	obj_Fresnel.FresnelTermP(theta_i);

	double aux_1 = pow(tan(theta_i*(M_PI/180) - obj_Fresnel.theta_t), 2);
	double aux_2 = pow(tan(theta_i*(M_PI/180) + obj_Fresnel.theta_t), 2);
	
	Rp = aux_1 / aux_2;

	double term_1 = pow(sin(theta_i*(M_PI/180) - obj_Fresnel.theta_t), 2);
	double term_2 = pow(sin(theta_i*(M_PI/180) + obj_Fresnel.theta_t), 2);
	
	Rs = term_1 / term_2;
}

void IntensityReflectivity::IntensityTransmissivity (){

	Tp = 1 - Rp;
	Ts = 1 - Rs;
}


