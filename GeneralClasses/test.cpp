#include "IncludeFile.h"

int main (){	

	std::cout << "Everything is okay!"; 
	std::cout << "\n\n";

	for(float theta_i = 0; theta_i <= 360; theta_i++){
		
		obj_Intensity.IntensityReflection(theta_i);
		obj_Intensity.IntensityTransmissivity();

		std::cout << obj_Intensity.Tp;
		std::cout << "\n\n";
	}		

	return 0;
}
