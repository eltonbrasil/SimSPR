#define SPR_H

class SPR{

private:
	
	std::complex<double> beta_1; 	// Phase shift Beta describes in each layer of thickness
	
	std::complex<double> q_1; 	    // Admittance describes in each layer of thickness
	
	std::complex<double> rp_wave;	// Fresnel terms for the P-polarized wave (Reflectance)
		
public:

	double Reflectance(int, double, double, double, double, double);
	
}spr;

double SPR::Reflectance(int theta_i, double n_prism, double wavelength, double d_metal, double real, double imag){
	
	// ***
	// Initializing variables and defining local variables
	// ***

	std::complex<double> i(0, 1); 				// Defining an imaginary number

	std::complex<double> n_metal_1(real, imag); // First Layer

	double lambda = wavelength * pow(10,-9);	// Wavelenght (nm)
	
	double K = (2*M_PI) / lambda;				// Constant K
	
	double d_metal_1 = d_metal * pow(10,-9); 	// First Layer thickness value (nm)

	// Admittance 

	std::complex<double> q_1 (sqrt(pow(n_metal_1,2) - pow(n_prism*sin(theta_i*(M_PI/180)),2)) / pow(n_metal_1,2));

	// Shift Phase

	std::complex<double> beta_1 (K*d_metal_1*sqrt(pow(n_metal_1,2) - pow(n_prism*sin(theta_i*(M_PI/180)),2)));

	// ***
	// Scattering matrix terms for the two-layer system 
	// ***

	std::complex<double> M_11 (cos(beta_1*(M_PI/180)));

	std::complex<double> M_12 ((-i/q_1)*sin(beta_1*(M_PI/180)));

	std::complex<double> M_21 (-i*q_1*sin(beta_1*(M_PI/180)));

	std::complex<double> M_22 (cos(beta_1*(M_PI/180)));

	// ****
	// Calculing Fresnel reflection coefficientes for the P_polarized wave between interface
	// ***

	std::complex<double> num ((M_11 + M_12*q_1)*q_1 - (M_21 + M_22*q_1));
	std::complex<double> den ((M_11 + M_12*q_1)*q_1 + (M_21 + M_22*q_1));

	std::complex<double> rp_wave (num / den);

	return (abs(pow(rp_wave, 2))); // Return reflectance value 
}

