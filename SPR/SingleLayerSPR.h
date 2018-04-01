#define SINGLELAYERSPR_H

class SingleLayerSPR{

private:
	
	std::complex<double> n_Gold; 	// Gold refractive index 
	std::complex<double> n_Si; 	 	// Silicon refractive index 
	std::complex<double> beta;	 	// Phase shift Beta describes in each layer of thickness
	std::complex<double> rp_wave;	// Fresnel terms for the P-polarized wave

	double theta_t;					// Transmitted angle
	double n_prism = 1.5214;	    // Prism refractive index 
	double n_air = 1; 				// Air refractive index
	double n_glass = 1.5168;    	// Glass refractive index

public:

	double ReflectanceP(double);
	double ReflectanceS(double);
	double SnellLaw(double);

}obj_SLayer;

double SingleLayerSPR::ReflectanceP(double theta_i){

	double K = (2*M_PI) / (obj_Const.lambda);
	
	theta_t = SnellLaw(theta_i);

	std::complex<double> n_Gold(0.467, 2.415); 
	std::complex<double> n_Si(4.05, -0.028); 

	// Local variable
	double param = K*obj_Const.d*cos(theta_i*(M_PI/180));

	std::complex<double> beta (param*real(n_Si), param*imag(n_Si)); // Phase shift Beta describes in each layer of thickness (Complex number)
	
	// Local variable
	double aux_1 = (n_prism*cos(theta_t*(M_PI/180)));
	double aux_2 = (real(n_Gold*cos(theta_i*(M_PI/180))));
	double aux_3 = (imag(n_Gold*cos(theta_i*(M_PI/180))));

	std::complex<double> num((aux_2 - aux_1),aux_3);
	std::complex<double> den((aux_2 + aux_1),aux_3);

	// ****
	// Calculing Fresnel reflection coefficientes for the P_polarized wave between interface
	// ***

	std::complex<double> rp_wave(num/den);

	return (abs(pow(rp_wave,2))); // Return reflectance value for the one-layer system
}

double SingleLayerSPR::ReflectanceS(double theta_i){

	double K = (2*M_PI) / (obj_Const.lambda);
	
	theta_t = SnellLaw(theta_i);

	std::complex<double> n_Gold(0.467, 2.415); 
	std::complex<double> n_Si(4.05, -0.028); 

	// Local variable
	double param = K*obj_Const.d*cos(theta_i*(M_PI/180));

	std::complex<double> beta (param*real(n_Si), param*imag(n_Si)); // Phase shift Beta describes in each layer of thickness (Complex number)
	
	// Local variable
	double var_1 = (n_prism*cos(theta_i*(M_PI/180)));
	double var_2 = (real(n_Gold*cos(theta_t*(M_PI/180))));

	double var_3 = (imag(n_Gold*cos(theta_t*(M_PI/180))));

	std::complex<double> num((var_1 - var_2),-var_3);
	std::complex<double> den((var_1 + var_2),var_3);

	// ****
	// Calculing Fresnel reflection coefficientes for the S_polarized wave between interface
	// ***

	std::complex<double> rs_wave(num/den);

	return (abs(pow(rs_wave,2))); // Return reflectance value for the one-layer system
}


double SingleLayerSPR::SnellLaw(double theta_i){

	std::complex<double> n_Gold(0.467, 2.415); 
	std::complex<double> n_Si(4.05, -0.028); 
	
	// Local variable
	double angle =  asin(arg(n_prism/n_Gold)*sin(theta_i*(M_PI/180)));

	return (angle);
}