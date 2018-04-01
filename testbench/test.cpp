#include "../GeneralClasses/IncludeFile.h"

int main (){	

	ofstream output;
	output.open("output.txt");

	cout <<
	"-------------------------------------------------------------------------------" << "\n"
	"------------------------------ Welcome to SimSPR ------------------------------" << "\n\n" <<
	"A basic framework for Fresnel equations simulations implemented in C++ language" << "\n\n" <<
	"--> You can check your simulation results in the output file" <<endl<<endl;

	double theta_i; // Indident angle
	
	for(theta_i = 0; theta_i <= 90; theta_i++){
		
		output << theta_i << "\t\t" << obj_SLayer.PhaseShift(theta_i) << endl;
	}

	output.close();
	return 0;
}