#define SPR_H

class SPR{

private:
	
	std::complex<double> beta_1; 	// Phase shift Beta describes in each layer of thickness
	std::complex<double> beta_n;
	
	std::complex<double> q_1; 	    // Admittance describes in each layer of thickness
	std::complex<double> q_n;
	
	std::complex<double> rp_wave;	// Fresnel terms for the P-polarized wave (Reflectance)
		
public:

	double Reflectance(float, double, double, double, double, double, double, double, double);
	
}spr;

double SPR::Reflectance(float theta_i, double n_prism, double wavelength, double d_metal, double d, double real, double imag, double N_real, double N_imag){
	
	// ***
	// Initializing variables and defining local variables
	// ***

	double lambda = wavelength * pow(10,-9);		 // Wavelenght (nm)
	
	double K = (2*M_PI) / lambda;					 // Constant K
	
	std::complex<double> i(0, 1); 					 // Defining an imaginary number

	// ***
	// Refractive index for each layer
	// ***

	std::complex<double> n_metal_1 (real, imag); 	 // Refractive index of the first metal layer
	std::complex<double> n_metal   (N_real, N_imag); // Refractive index for each metal layer

	// ***
    // Layers thickness values (nm)
    // ***

    double d_metal_1 = d_metal * pow(10,-9); 		 // First Layer thickness value (nm)
    double d_metal_n = d * pow(10,-9); 		 		 // First Layer thickness value (nm)

	// Admittance 

	std::complex<double> q_1 (sqrt(pow(n_metal_1,2) - pow(n_prism*sin(theta_i*(M_PI/180)),2)) / pow(n_metal_1,2));
	std::complex<double> q_n (sqrt(pow(n_metal,2)   - pow(n_prism*sin(theta_i*(M_PI/180)),2)) / pow(n_metal,2));

	// Shift Phase

	std::complex<double> beta_1 (K*d_metal_1*sqrt(pow(n_metal_1,2) - pow(n_prism*sin(theta_i*(M_PI/180)),2)));
	std::complex<double> beta_n (K*d_metal_n*sqrt(pow(n_metal,2)   - pow(n_prism*sin(theta_i*(M_PI/180)),2)));

	// ***
	// Scattering matrix terms for the first interface: prism / first metal layer
	// ***

	std::complex<double> M_11 (cos(beta_1*(M_PI/180)));

	std::complex<double> M_12 ((-i/q_1)*sin(beta_1*(M_PI/180)));

	std::complex<double> M_21 (-i*q_1*sin(beta_1*(M_PI/180)));

	std::complex<double> M_22 (cos(beta_1*(M_PI/180)));

	// ***
	// Scattering matrix terms for each interface
	// ***

	std::complex<double> N_11 (cos(beta_n*(M_PI/180)));

	std::complex<double> N_12 ((-i/q_n)*sin(beta_n*(M_PI/180)));

	std::complex<double> N_21 (-i*q_n*sin(beta_n*(M_PI/180)));

	std::complex<double> N_22 (cos(beta_n*(M_PI/180)));

	// ***
	// Scattering Matrix total terms for each interface
	// ***

	std::complex<double> MT_11 (M_11 * N_11 + M_12 * N_21);
	std::complex<double> MT_12 (M_11 * N_12 + M_12 * N_22);
	std::complex<double> MT_21 (M_21 * N_11 + M_22 * N_21);
	std::complex<double> MT_22 (M_21 * N_12 + M_22 * N_22);

	// ****
	// Calculing Fresnel reflection coefficientes for the P_polarized wave between interface
	// ***

	std::complex<double> num ((MT_11 + MT_12*q_n)*q_1 - (MT_21 + MT_22*q_n));
	std::complex<double> den ((MT_11 + MT_12*q_n)*q_1 + (MT_21 + MT_22*q_1));

	std::complex<double> rp_wave (num / den);

	return (abs(pow(rp_wave, 2))); // Return reflectance value 
}

