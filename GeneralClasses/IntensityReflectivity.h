#include "Fresnel.h"
#define INTENSITYREFLECTIVITY_H

class IntensityReflectivity
{
private:
	float Rp; // Intensity reflection for P-polarized wave
	float Rs; // Intensity reflection for S-polarized wave
	float Tp; // Intensity transmissivities coefficient for P-polarized wave
	float Ts; // Intensity transmissivities coefficient for S-polarized wave
public:
	float IntensityReflection (int);
	float IntensityTransmissivity (int);
}obj_Intensity;

float IntensityReflectivity::IntensityReflection (int theta_i){

	float aux_1 = (pow(tan(theta_i - obj_Fresnel.theta_t), 2));
	float aux_2 = (pow(tan(theta_i + obj_Fresnel.theta_t), 2));
	
	obj_Intensity.Rp = aux_1 / aux_2;

	float term_1 = (pow(sin(theta_i - obj_Fresnel.theta_t), 2));
	float term_2 = (pow(sin(theta_i + obj_Fresnel.theta_t), 2));
	
	obj_Intensity.Rs = term_1 / term_2;

	return (obj_Intensity.Rs);
}



