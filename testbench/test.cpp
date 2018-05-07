#include "../GeneralClasses/IncludeFile.h"

int main (){	

	ofstream out_R;
	out_R.open("reflectance.txt");

	int choice;

	double theta_i = 0;		// Angle of Incidence (degrees)

	double real, imag, real_2, imag_2, real_3, imag_3;

	double n_prism, wavelength; 

	// ***
	// Set Layers thickness values (nm)
	// ***

	double d_1 = 50;
	double d_2 = 5000;
	double d_3;

	// ***
	// Set dielectric constant of the metal (real part)
	// ***

	double e_mr = -14.358;
	
	cout <<
	"---------------------------------------------------------------------------------------" << "\n"
	"---------------------------------- Welcome to Sim-SPR ---------------------------------" << "\n\n" 
	" An Open Source for Surface Plasmon Resonance simulation implemented in C++ language   " << "\n\n"
	"---------------------------------------------------------------------------------------" << "\n\n";
	
	cout << "## This Open Source works using Kretschmann configuration for three and four layers" "\n"; 
    cout << "## (3) or (4) layers?" << "\n";
    cin >> choice;

	cout << "## Type the incident light wavelength (nm):" << "\n";
	cin >> wavelength;

	cout << "## Type the prism refractive index:" << "\n";
	cin >> n_prism;

	cout << "## First Layer-- Type the refractive index of the material (real part):" << "\n";
	cin >> real;
	cout << "## First Layer-- Type the refractive index of the material (imaginary part):" << "\n";
	cin >> imag;

	cout << "## Second Layer-- Type the refractive index of the material (real part):" << "\n";
	cin >> real_2;
	cout << "## Second Layer-- Type the refractive index of the material (imaginary part) then enter to execute:" << "\n";
	cin >> imag_2;

	if (choice == 4){
		cout << "## Third Layer-- Type the refractive index of the material (real part):" << "\n";
		cin >> real_3;
		cout << "## Third Layer-- Type the refractive index of the material (imaginary part) then enter to execute:" << "\n";
		cin >> imag_3;
	}

	while(theta_i <= 90){
		
		if (choice ==  3){
		 	out_R << theta_i << "\t\t" << s_SPR.Reflectance(theta_i, real, imag, real_2, imag_2, n_prism, wavelength, d_1, d_2) << endl;
		    theta_i = theta_i + 0.1;
		}

		if (choice ==  4){
		 	out_R << theta_i << "\t\t" << m_SPR.Reflectance(theta_i, real, imag, real_2, imag_2, real_3, imag_3, n_prism, wavelength, d_1, d_2, d_3) << endl;
		    theta_i = theta_i + 0.1;
		}
		
	}
	
	cout << "--> You can check your simulation results in the output file" << "\n\n";

	out_R.close();
				
	return 0;
}