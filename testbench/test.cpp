#include "../GeneralClasses/IncludeFile.h"

int main (){	

	ofstream out_Rs;
	out_Rs.open("Rs.txt");

	ofstream out_Rp;
	out_Rp.open("Rp.txt");

	cout <<
	"-------------------------------------------------------------------------------" << "\n"
	"------------------------------ Welcome to SimSPR ------------------------------" << "\n\n" <<
	"A basic framework for Fresnel equations simulations implemented in C++ language" << "\n\n" <<
	"--> You can check your simulation results in the output file" <<endl<<endl;

	double theta_i; // Indident angle
	
	for(theta_i = 0; theta_i <= 90; theta_i++){
		
		out_Rp << theta_i << "\t\t" << obj_SLayer.ReflectanceP(theta_i) << endl;
		out_Rs << theta_i << "\t\t" << obj_SLayer.ReflectanceS(theta_i) << endl;
	}

	out_Rp.close();
	out_Rs.close();
	return 0;
}