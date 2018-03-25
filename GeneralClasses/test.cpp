#include "Fresnel.h"

int main (){	

	std::cout << "Everything is okay!"; 
	std::cout << "\n\n";

	for(float theta_i = 0; theta_i <= 360; theta_i++){
		obj_Fresnel.FresnelTermP(theta_i);
		std::cout << theta_i << "\t\t" << obj_Fresnel.tp_wave;
		std::cout << "\n\n";		
	}		

	return 0;
}
