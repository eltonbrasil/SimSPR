#include "IncludeFile.h"

using namespace std;
int main (){	

	ofstream data;
	data.open("output.txt");
	
	cout <<
	"-------------------------------------------------------------------------------" << "\n"
	"------------------------------ Welcome to SimSPR ------------------------------" << "\n\n" <<
	"A basic framework for Fresnel equations simulations implemented in C++ language" << "\n\n" <<
	"@ You can check your simulations results in the output file" <<endl<<endl;

	double theta_i;

	for(theta_i = 0; theta_i <= 360; theta_i++){
		
		obj_Intensity.IntensityReflection(theta_i);
		obj_Intensity.IntensityTransmissivity();

		data << theta_i << "\t\t" << obj_Intensity.Rp <<endl;
	}
	
	data.close();
	
	return 0;
}


	

