#define SINGLELAYERSPR_H

class SingleLayerSPR{

private:
	
	std::complex<double> n_Gold; 	// Gold refractive index
	std::complex<double> n_Si; 	 	// Silicon refractive index

	std::complex<double> e_Gold;	// Gold metal permittivity

	std::complex<double> beta;	 	// Phase shift Beta describes in each layer of thickness

	std::complex<double> rp_wave;	// Fresnel terms for the P-polarized wave
	std::complex<double> rs_wave;	// Fresnel terms for the S-polarized wave

	double e_prism = 2.6131;		// Dielectrix constant of the prism
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

	std::complex<double> n_Gold(0.467, 2.4075); 
	std::complex<double> n_Si(4.05, -0.028);
	std::complex<double> e_Gold (-10.92, 1.49);

	theta_t = SnellLaw(theta_i);

	// Local variable
	double param = ((2*M_PI) / obj_Const.lambda)*obj_Const.d*cos(theta_i*(M_PI/180));
	std::complex<double> var(n_Gold*sqrt((e_prism*e_Gold)/(e_prism + e_Gold)));

	// Phase shift Beta describes in each layer of thickness
	std::complex<double> beta (param*real(var), param*imag(var));  
	
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

	// ****
	// Calculing Reflectance value for the P_polarized wave between interface
	// ***

	std::complex<double> i(0, 1); // Defining an imaginary number
	std::complex<double> e(exp(i*beta));

	std::complex<double> reflectance ((e*rp_wave)/e);

	return (abs(pow(reflectance,2))); // Return reflectance value for the one-layer system
}

double SingleLayerSPR::ReflectanceS(double theta_i){

	std::complex<double> n_Gold(0.467, 2.4075); 
	std::complex<double> n_Si(4.05, -0.028);
	std::complex<double> e_Gold (-10.92, 1.49);

	theta_t = SnellLaw(theta_i);

	// Local variable
	double param = ((2*M_PI) / obj_Const.lambda)*obj_Const.d*cos(theta_i*(M_PI/180));
	std::complex<double> var(n_Gold*sqrt((e_prism*e_Gold)/(e_prism + e_Gold)));

	// Phase shift Beta describes in each layer of thickness
	std::complex<double> beta (param*real(var), param*imag(var)); 
	
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

	// ****
	// Calculing Reflectance value for the S_polarized wave between interface
	// ***

	std::complex<double> i(0, 1); // Defining an imaginary number
	std::complex<double> e(exp(i*beta));

	std::complex<double> reflectance ((e*rs_wave)/e);

	return (abs(pow(reflectance,2))); // Return reflectance value for the one-layer system
}


double SingleLayerSPR::SnellLaw(double theta_i){

	std::complex<double> n_Gold(0.467, 2.415); 
	std::complex<double> n_Si(4.05, -0.028); 
	
	// Local variable
	double angle =  asin(arg(n_prism/n_Gold)*sin(theta_i*(M_PI/180)));

	return (angle);
}