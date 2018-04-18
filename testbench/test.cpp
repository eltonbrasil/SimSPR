#include "../GeneralClasses/IncludeFile.h"

int main (){	

	ofstream out_Rp_1;
	out_Rp_1.open("rp_1.txt");

	double theta_i = 0;
	double real_1, imag_1, real_2, imag_2, n_prism, wavelength; 
	double d_1 = 10.5, d_2 = 10;

	cout <<
	"---------------------------------------------------------------------------------------" << "\n"
	"---------------------------------- Welcome to SimSPR ----------------------------------" << "\n\n" 
	" A basic framework for Surface Plasmon Resonance simulation implemented in C++ language" << "\n\n"
	"---------------------------------------------------------------------------------------" << "\n\n";
	cout << "Type the incident light wavelength (nm):" << "\n";
	cin >> wavelength;
	cout << "Type the prism refractive index:" << "\n";
	cin >> n_prism;
	cout << "## First Layer--Type the refractive index of the material (real part):" << "\n";
	cin >> real_1;
	cout << "## First Layer-- Type the refractive index of the material (imaginary part):" << "\n";
	cin >> imag_1;
	cout << "## Second Layer-- Type the refractive index of the material (real part):" << "\n";
	cin >> real_2;
	cout << "## Second Layer-- Type the refractive index of the material (imaginary part) then enter to execute:" << "\n";
	cin >> imag_2;
	cout << "--> You can check your simulation results for one-layer system in the output file" << "\n\n";

	while(theta_i <= 360){		 
		 out_Rp_1 << theta_i << "\t\t" << obj_SPR.Reflectance(theta_i, real_1, imag_1, real_2, imag_2, n_prism, wavelength, d_1, d_2) << endl;
		 
		 theta_i = theta_i + 0.01; 
	}

	out_Rp_1.close();
			
	return 0;
}

