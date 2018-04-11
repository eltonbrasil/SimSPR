#include "../GeneralClasses/IncludeFile.h"

int main (){	

	ofstream out_Rp_1;
	out_Rp_1.open("rp_1.txt");

	ofstream out_Rp_2;
	out_Rp_2.open("rp_2.txt");

	ofstream out_Rp_3;
	out_Rp_3.open("rp_3.txt");

	ofstream out_Rp_4;
	out_Rp_4.open("rp_4.txt");

	ofstream out_Rp_5;
	out_Rp_5.open("rp_5.txt");

	ofstream out_Rp_6;
	out_Rp_6.open("rp_6.txt");

	double n_0, real, imag, wavelength;
	double theta_i = 0;
	double d_11 = 30, d_12 = 40, d_13 = 50, d_14 = 60, d_15 = 70, d_16 = 80; 

	cout <<
	"---------------------------------------------------------------------------------------" << "\n"
	"---------------------------------- Welcome to SimSPR ----------------------------------" << "\n\n" 
	" A basic framework for Surface Plasmon Resonance simulation implemented in C++ language" << "\n\n"
	"---------------------------------------------------------------------------------------" << "\n\n";
	cout << "Type the incident light wavelength (nm):" << "\n";
	cin >> wavelength;
	cout << "Type the prism refractive index:" << "\n";
	cin >> n_0;
	cout << "Type the refractive index of the material (real part):" << "\n";
	cin >> real;
	cout << "Type the refractive index of the material (imaginary part) then enter to execute:" << "\n";
	cin >> imag;
	cout << "--> You can check your simulation results for one-layer system in the output file" << "\n\n";

	while(theta_i <= 90){		 
		 out_Rp_1 << theta_i << "\t\t" << obj_SPR.Reflectance(theta_i, real, imag, n_0, wavelength, d_11) << endl;
		 out_Rp_2 << theta_i << "\t\t" << obj_SPR.Reflectance(theta_i, real, imag, n_0, wavelength, d_12) << endl;
		 out_Rp_3 << theta_i << "\t\t" << obj_SPR.Reflectance(theta_i, real, imag, n_0, wavelength, d_13) << endl;
		 out_Rp_4 << theta_i << "\t\t" << obj_SPR.Reflectance(theta_i, real, imag, n_0, wavelength, d_14) << endl;
		 out_Rp_5 << theta_i << "\t\t" << obj_SPR.Reflectance(theta_i, real, imag, n_0, wavelength, d_15) << endl;
		 out_Rp_6 << theta_i << "\t\t" << obj_SPR.Reflectance(theta_i, real, imag, n_0, wavelength, d_16) << endl;

		 theta_i = theta_i + 0.01; 
	}

	out_Rp_1.close();
	out_Rp_2.close();
	out_Rp_3.close();
	out_Rp_4.close();
	out_Rp_5.close();
	out_Rp_6.close(); 
		
	return 0;
}