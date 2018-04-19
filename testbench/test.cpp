#include "../GeneralClasses/IncludeFile.h"

int main (){	

	ofstream out_Rp;
	out_Rp.open("rp.txt");

	ofstream out_Tp;
	out_Tp.open("tp.txt");

	double theta_i = 0;
	double real_1, imag_1, real_2, imag_2, n_prism, wavelength; 
	double d_1 = 40, d_2 = 10;

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

	while(theta_i <= 90){

		 out_Rp << theta_i << "\t\t" << obj_SPR.Reflectance(theta_i, real_1, imag_1, real_2, imag_2, n_prism, wavelength, d_1, d_2) << endl;
		 out_Tp << theta_i << "\t\t" << obj_SPR.Transmissivity(theta_i, real_1, imag_1, real_2, imag_2, n_prism, wavelength, d_1, d_2) << endl;
		 
		 theta_i = theta_i + 0.1; 
	}

	out_Rp.close();
	out_Tp.close();			
	return 0;
}