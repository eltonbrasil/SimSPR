#include "../GeneralClasses/IncludeFile.h"

using namespace std;
int main (){	

	ofstream data_Rp;
	data_Rp.open("Rp.txt");

	ofstream data_Rs;
	data_Rs.open("Rs.txt");
	
	cout <<
	"-------------------------------------------------------------------------------" << "\n"
	"------------------------------ Welcome to SimSPR ------------------------------" << "\n\n" <<
	"A basic framework for Fresnel equations simulations implemented in C++ language" << "\n\n" <<
	"--> You can check your simulation results in the output file" <<endl<<endl;

	double theta_i; // Indident angle

	for(theta_i = 0; theta_i <= 90; theta_i++){
		
		obj_Intensity.IntensityReflection(theta_i);
		obj_Intensity.IntensityTransmissivity();

		data_Rp << theta_i << "\t\t" << obj_Intensity.Rp << endl;
		data_Rs << theta_i << "\t\t" << obj_Intensity.Rs << endl;
	}

	data_Rp.close();
	data_Rs.close();
	
	return 0;
}


	

