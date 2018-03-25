#include "IntensityReflectivity.h"

int main (){	

	std::cout << "Everything is okay!"; 
	std::cout << "\n\n";

	for(float theta_i = 0; theta_i <= 360; theta_i++){
		
		obj_Fresnel.FresnelTermP(theta_i);
		float aux_variable = obj_Intensity.IntensityReflection(theta_i);

		std::cout << theta_i << "\t\t" << aux_variable;
		std::cout << "\n\n";		
	}		

	return 0;
}
