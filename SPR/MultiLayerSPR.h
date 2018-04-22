#define MULTILAYERSPR_H

class MultiLayerSPR{

private:
	
	std::complex<double> beta_1; 	// Phase shift Beta describes in each layer of thickness
	std::complex<double> beta_2; 	// Phase shift Beta describes in each layer of thickness
	std::complex<double> beta_3; 	// Phase shift Beta describes in each layer of thickness

	std::complex<double> q_1; 	    // Admittance describes in each layer of thickness
	std::complex<double> q_2; 	    // Admittance describes in each layer of thickness
	std::complex<double> q_3; 	    // Admittance describes in each layer of thickness

	std::complex<double> n_metal_3;

	std::complex<double> rp_wave;	// Fresnel terms for the P-polarized wave (Reflectance)
		
public:

	double Reflectance(double, double, double, double, double, double, double, double, double);
	
}m_SPR;

double MultiLayerSPR::Reflectance(double theta_i, double real, double imag, double real_2, double imag_2, double n_prism, double wavelength, double d_1, double d_2){

	// ***
	// Initializing variables
	// ***

	std::complex<double> n_metal_1(real, imag);
	
	std::complex<double> n_metal_3(real_2, imag_2); // Refractive index of 1-dodecanethiol SAM (Second Layer)

	double n_metal_2 = 1.5; 

	double d_metal_1 = d_1 * pow(10,-9);
	double d_metal_3 = d_2 * pow(10,-9);
	double d_metal_2 = 2 * pow(10,-9);

	// ***
	// Defining local variables
	// ***

	std::complex<double> i(0, 1); // Defining an imaginary number

	double lambda = wavelength*pow(10,-9); // Wavelength

	double K = (2*M_PI) / lambda;
	
	// Admittance 

	std::complex<double> q_1 (sqrt(pow(n_metal_1,2) - pow(n_prism*sin(theta_i*(M_PI/180)),2)) / pow(n_metal_1,2));

	std::complex<double> q_2 (sqrt(pow(n_metal_2,2) - pow(n_prism*sin(theta_i*(M_PI/180)),2)) / pow(n_metal_2,2));

	std::complex<double> q_3 (sqrt(pow(n_metal_3,2) - pow(n_prism*sin(theta_i*(M_PI/180)),2)) / pow(n_metal_3,2));

	// Absorbance

	std::complex<double> beta_1 (K*d_metal_1*sqrt(pow(n_metal_1,2) - pow(n_prism*sin(theta_i*(M_PI/180)),2)));

	std::complex<double> beta_2 (K*d_metal_2*sqrt(pow(n_metal_2,2) - pow(n_prism*sin(theta_i*(M_PI/180)),2)));	

	std::complex<double> beta_3 (K*d_metal_3*sqrt(pow(n_metal_3,2) - pow(n_prism*sin(theta_i*(M_PI/180)),2)));

	// ***
	// Individual matrix for each layer 
	// ***
	// First matrix

	std::complex<double> M_11_1 (cos(beta_1*(M_PI/180)));
	std::complex<double> M_12_1 (-(i/q_1)*sin(beta_1*(M_PI/180)));
	std::complex<double> M_21_1 (-i*q_1*sin(beta_1*(M_PI/180)));
	std::complex<double> M_22_1 (cos(beta_1*(M_PI/180)));

	// Second matrix

	std::complex<double> M_11_2 (cos(beta_2*(M_PI/180)));
	std::complex<double> M_12_2 (-(i/q_2)*sin(beta_2*(M_PI/180)));
	std::complex<double> M_21_2 (-i*q_2*sin(beta_2*(M_PI/180)));
	std::complex<double> M_22_2 (cos(beta_2*(M_PI/180)));
		
	// Third matrix
	
	std::complex<double> M_11_3 (cos(beta_3*(M_PI/180)));
	std::complex<double> M_12_3 (-(i/q_3)*sin(beta_3*(M_PI/180)));
	std::complex<double> M_21_3 (-i*q_3*sin(beta_3*(M_PI/180)));
	std::complex<double> M_22_3 (cos(beta_3*(M_PI/180)));	

	// ***
	// Scattering matrix terms
	// ***

	std::complex<double> M_11_t (M_11_1 * M_11_2 + M_12_1 * M_21_2);
	std::complex<double> M_12_t (M_11_1 * M_12_2 + M_12_1 * M_22_2);
	std::complex<double> M_21_t (M_21_1 * M_11_2 + M_22_1 * M_21_2);
	std::complex<double> M_22_t (M_21_1 * M_12_2 + M_22_1 * M_22_2);

	// ***
	// Total matrix terms
	// ***

	std::complex<double> M_11 (M_11_t * M_11_3 + M_12_t * M_21_3);
	std::complex<double> M_12 (M_11_t * M_12_3 + M_12_t * M_22_3);
	std::complex<double> M_21 (M_21_t * M_11_3 + M_22_t * M_21_3);
	std::complex<double> M_22 (M_21_t * M_12_3 + M_22_t * M_22_3);

	// ****
	// Calculing Fresnel reflection coefficientes for the P_polarized wave between interface
	// ***

	std::complex<double> num ((M_11 + M_12*q_3)*q_1 - (M_21 + M_22*q_3));
	std::complex<double> den ((M_11 + M_12*q_3)*q_1 + (M_21 + M_22*q_3));
	
	std::complex<double> rp_wave (num / den);

	return (abs(pow(rp_wave, 2))); // Return reflectance value for the two-layer system
} 