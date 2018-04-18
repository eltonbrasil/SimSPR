#define SINGLELAYERSPR_H

class SingleLayerSPR{

private:
	
	std::complex<double> n_1; 	    // Refractive index
	
	std::complex<double> beta_0; 	// Phase shift Beta describes in each layer of thickness
	std::complex<double> beta_1; 	// Phase shift Beta describes in each layer of thickness

	std::complex<double> rp_wave;	// Fresnel terms for the P-polarized wave
	
public:

	double Reflectance(double, double, double, double, double, double, double, double, double);
	
}obj_SPR;

double SingleLayerSPR::Reflectance(double theta_i, double real_1, double imag_1, double real_2, double imag_2, double n_prism, double wavelength, double d_1, double d_2){

	// ***
	// Initializing variables and defining local variables
	// ***

	std::complex<double> n_metal_1(real_1, imag_1);
	std::complex<double> n_metal_2(real_2, imag_2); 
	std::complex<double> i(0, 1); // Defining an imaginary number

	double lambda = wavelength*pow(10,-9);
	double K = (2*M_PI) / lambda;
	
	double d_metal_1 = d_1 * pow(10,-9);
	double d_metal_2 = d_2 * pow(10,-9);

	// Snell Law

	// std::complex<double> theta_t (asin((n_metal_1/n_metal_2)*sin(theta_i)));

	// Admittance 

	std::complex<double> q_1 (sqrt(pow(n_metal_1,2) - pow(n_prism*sin(theta_i*(M_PI/180)),2)) / pow(n_metal_1,2));
	std::complex<double> q_2 (sqrt(pow(n_metal_2,2) - pow(n_prism*sin(theta_i*(M_PI/180)),2)) / pow(n_metal_2,2));

	// Absorbance

	std::complex<double> beta_1 (K*d_metal_1*sqrt(pow(n_metal_1,2) - pow(n_prism*sin(theta_i*(M_PI/180)),2)));
	std::complex<double> beta_2 (K*d_metal_2*sqrt(pow(n_metal_2,2) - pow(n_prism*sin(theta_i*(M_PI/180)),2)));
	
	// ***
	// Scattering matrix terms for the two-layer system 
	// ***

	std::complex<double> M_11 (cos(beta_1*(M_PI/180))*cos(beta_2*(M_PI/180)) - (q_2/q_1)*sin(beta_1*(M_PI/180))*sin(beta_2*(M_PI/180)));

	std::complex<double> M_12 ((-i/q_2)*sin(beta_2*(M_PI/180))*cos(beta_1*(M_PI/180)) - (i/q_1)*sin(beta_1*(M_PI/180))*cos(beta_2*(M_PI/180)));

	std::complex<double> M_21 (-i*q_1*sin(beta_1*(M_PI/180))*cos(beta_2*(M_PI/180)) - i*q_2*sin(beta_2*(M_PI/180))*cos(beta_1*(M_PI/180)));

	std::complex<double> M_22 ((-q_1/q_2)*sin(beta_1*(M_PI/180))*sin(beta_2*(M_PI/180)) + cos(beta_1*(M_PI/180))*cos(beta_2*(M_PI/180)));
	// ****
	// Calculing Fresnel reflection coefficientes for the P_polarized wave between interface
	// ***

	std::complex<double> num ((M_11 + M_12*q_2)*q_1 - (M_21 + M_22*q_2));
	std::complex<double> den ((M_11 + M_12*q_2)*q_1 + (M_21 + M_22*q_2));

	std::complex<double> rp_wave (num / den);

	return (abs(pow(rp_wave, 2))); // Return reflectance value for the two-layer system
}


