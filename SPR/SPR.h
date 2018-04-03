#define SPR_H

class SPR{

private:
	
	std::complex<double> n_1; 	    // Refractive index
	
	std::complex<double> beta_0; 	// Phase shift Beta describes in each layer of thickness
	std::complex<double> beta_1; 	// Phase shift Beta describes in each layer of thickness

	std::complex<double> rp_wave;	// Fresnel terms for the P-polarized wave
	
	double n_0;	    				// Prism refractive index

	double e_prism = 2.6131;		// Dielectrix constant of the prism 
	
public:

	double Reflectance(double, double, double, double, double);
	
}obj_SPR;

double SPR::Reflectance(double theta_i, double real, double imag, double n_prism, double wavelength){

	// Initializing variables

	std::complex<double> e_Gold (-10.92, 1.49);

	std::complex<double> n_1(real, imag); 
	
	double lambda = wavelength*pow(10,-9);

	n_0 = n_prism;

	double K = (2*M_PI) / lambda;

	std::complex<double> i(0, 1); // Defining an imaginary number

	// Admittance for the n_0 (prism) and n_1 (metal)

	std::complex<double> q_0 (sqrt(pow(n_0,2) - pow(n_1*sin(theta_i*(M_PI/180)),2)) / pow(n_0,2));
	std::complex<double> q_1 (sqrt(pow(n_1,2) - pow(n_1*sin(theta_i*(M_PI/180)),2)) / pow(n_1,2));

	// Absorbance for the n_0 (prism) and n_1 (metal)

	std::complex<double> beta_0 (K*obj_Const.d_0*sqrt(pow(n_0,2) - pow(n_1*sin(theta_i*(M_PI/180)),2)));
	std::complex<double> beta_1 (K*obj_Const.d_1*sqrt(pow(n_1,2) - pow(n_1*sin(theta_i*(M_PI/180)),2)));

	// ***
	// Scattering matrix terms for the one-layer system (n_0 -> n_1 interface)
	// ***

	std::complex<double> M_11 (cos(beta_0*(M_PI/180))*cos(beta_1*(M_PI/180)) - (q_0/q_1)*sin(beta_0*(M_PI/180))*sin(beta_1*(M_PI/180)));
	std::complex<double> M_12 ((-i/q_0)*sin(beta_0*(M_PI/180))*cos(beta_1*(M_PI/180)) - (i/q_1)*sin(beta_1*(M_PI/180))*cos(beta_0*(M_PI/180)));
	std::complex<double> M_21 (-i*q_1*sin(beta_1*(M_PI/180))*cos(beta_0*(M_PI/180)) - i*q_0*sin(beta_0*(M_PI/180))*cos(beta_1*(M_PI/180)));
	std::complex<double> M_22 ((-q_1/q_0)*sin(beta_0*(M_PI/180))*sin(beta_1*(M_PI/180)) + cos(beta_0*(M_PI/180))*cos(beta_1*(M_PI/180)));

	// ****
	// Calculing Fresnel reflection coefficientes for the P_polarized wave between interface
	// ***

	std::complex<double> num ((M_11 + M_12*q_1)*q_1 - (M_21 + M_22*q_1));
	std::complex<double> den ((M_11 + M_12*q_1)*q_1 + (M_21 + M_22*q_1));

	std::complex<double> rp_wave (num / den);

	return (abs(rp_wave)); // Return reflectance value for the one-layer system
}