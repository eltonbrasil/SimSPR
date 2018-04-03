#include "../GeneralClasses/IncludeFile.h"

int main (){	

	ofstream out_Rp;
	out_Rp.open("rp.txt");

	double n_0 = 1.51947, real = 0.467, imag = 2.4075, wavelength = 532;
	double theta_i; // Indident angle

	cout <<
	"---------------------------------------------------------------------------------------" << "\n"
	"---------------------------------- Welcome to SimSPR ----------------------------------" << "\n\n" 
	" A basic framework for Surface Plasmon Resonance simulation implemented in C++ language" << "\n\n"
	"---------------------------------------------------------------------------------------" << "\n\n";
/*	cout << "Se the incident light wavelength (nm):" << "\n";
	cin >> wavelength;
	cout << "Type the prism refractive index:" << "\n";
	cin >> n_0;
	cout << "Type the refractive index of the material (real part):" << "\n";
	cin >> real;
	cout << "Type the refractive index of the material (imaginary part) then enter to execute:" << "\n";
	cin >> imag;
	cout << "--> You can check your simulation results for one-layer system in the output file" << "\n\n";
*/
	for(theta_i = 0; theta_i <= 360; theta_i++){
		
		 out_Rp << theta_i << "\t\t" << obj_SPR.Reflectance(theta_i, real, imag, n_0, wavelength) << endl;
	}

	out_Rp.close();
	
	return 0;
}