#define SPR_H

class SPR{

private:
	
	std::complex<double> beta; 	    // Phase shift Beta describes in each layer of thickness
				 double  beta_2;

	std::complex<double> q; 	    // Admittance describes in each layer of thickness
				 double  q_2;
		
	std::complex<double> rp_wave;	// Fresnel terms for the P-polarized wave (Reflectance)
		
public:

	double Reflectance(float, double, double, double, double, double, double, double);
	
}spr;

double SPR::Reflectance(float theta_i, double n_prism, double wavelength, double d, double real, double imag, double d_2, double n_2){
	
	// ***
	// Initializing variables and defining local variables
	// ***

	double lambda = wavelength * pow(10,-9);		 // Wavelenght (nm)
	
	double K = (2*M_PI) / lambda;					 // Constant K
	
	std::complex<double> i(0, 1); 					 // Defining an imaginary number

	// ***
	// Refractive index for each layer
	// ***

	std::complex<double> n (real, imag);           // Refractive index for each metal layer
   
	// ***
    // Layers thickness values (nm)
    // ***

    double d_metal_1 = d * pow(10,-9); 		        
    double d_metal_2 = d_2 * pow(10, -9);
    
	// Admittance 

	std::complex<double> q     (sqrt(pow(n,2) -   pow(n_prism*sin(theta_i*(M_PI/180)),2)) / pow(n,2));
	             double  q_2 =  sqrt(pow(n_2,2) - pow(n_prism*sin(theta_i*(M_PI/180)),2)) / pow(n_2,2);
	
	// Shift Phase

	std::complex<double> beta    (K*d_metal_1*sqrt(pow(n,2)   - pow(n_prism*sin(theta_i*(M_PI/180)),2)));
				 double  beta_2 = K*d_metal_2*sqrt(pow(n_2,2) - pow(n_prism*sin(theta_i*(M_PI/180)),2)); 
	
	// ***
	// Scattering matrix terms for each interface
	// ***

	std::complex<double> M_11 (cos(beta*(M_PI/180))*cos(beta_2*(M_PI/180)) - (q_2/q)*sin(beta*(M_PI/180))*sin(beta_2*(M_PI/180)));

	std::complex<double> M_12 ((-i/q_2)*sin(beta_2*(M_PI/180))*cos(beta*(M_PI/180)) - (i/q)*sin(beta*(M_PI/180))*cos(beta_2*(M_PI/180)));

	std::complex<double> M_21 (-i*q*sin(beta*(M_PI/180))*cos(beta_2*(M_PI/180)) - i*q_2*sin(beta_2*(M_PI/180))*cos(beta*(M_PI/180)));

	std::complex<double> M_22 ((-q/q_2)*sin(beta*(M_PI/180))*sin(beta_2*(M_PI/180)) + cos(beta*(M_PI/180))*cos(beta_2*(M_PI/180)));
	
	// ****
	// Calculing Fresnel reflection coefficientes for the P_polarized wave between interface
	// ***

	std::complex<double> num ((M_11 + M_12*q_2)*q - (M_21 + M_22*q_2));
	std::complex<double> den ((M_11 + M_12*q_2)*q + (M_21 + M_22*q_2));

	std::complex<double> rp_wave (num / den);

	return (abs(pow(rp_wave, 2))); // Return reflectance value 
}

