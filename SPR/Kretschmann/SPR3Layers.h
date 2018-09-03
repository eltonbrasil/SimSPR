#define SPR3Layers_H

class SPR3Layers{
	
	private:
		
		typedef std::complex<double> Complex;
		
		double lambda, K0, R;

	public:	
	
		double Reflectance(double, double, double, double, double, double, double);
	
}spr;

double SPR3Layers::Reflectance(double theta_i, double wavelength, double n_prism, double n_analito, double n2_r, double n2_i, double d2){

	// ***
	// Initializing parameters
	// ***

	lambda = wavelength * pow(10,-9); 	// Wavelength (nm)
	K0 = (2*M_PI) / lambda;		  	  	// K0 is the free space wavenumber of optical wave
	const std::complex<double> i(0,1);	// Imaginary number
	double r = 2;

	// ***
	// Refractive index for each layer
	// ***

	Complex n_2 = Complex (n2_r, n2_i);	// Complex refractive index metal layer
	
	// ***
    // Layers thickness values (nm)
    // ***

	double d_2 = d2 * pow(10,-9);    		 

	// ***
	// Reflective coefficient of the reflection from mediums
	// ***
 
	double K1 =  K0*(sqrt(pow(n_prism,2)) - pow(n_prism,2)*pow(sin(theta_i*(M_PI/180)),2));
	Complex K2 = K0*std::sqrt(pow(n_2,2) - pow(n_prism,2)*pow(sin(theta_i*(M_PI/180)),2));
	double K3 =  K0*(sqrt(pow(n_analito,2)) - pow(n_prism,2)*pow(sin(theta_i*(M_PI/180)),2));
		
	// ***
	// Fresnel reflection coefficients for the P polarized wave between interfaces
	// ***

	Complex r_12 = Complex (((K1 * pow(n_2,2)) - (K2 * pow(n_prism,2))) / ((K1 * pow(n_2,2)) + (K2 * pow(n_prism,2))));

	Complex r_23 = Complex (((K2 * pow(n_analito,2)) - (K3 * pow(n_2,2))) / ((K2 * pow(n_analito,2)) + (K3 * pow(n_2,2))));

	// ***
	// Reflectance 
	// ***

	Complex R = (r_12 + r_23*std::exp(-i*r*K2*d_2)) / (r/2 + r_12*r_23*std::exp(-i*r*K2*d_2));

	
	return abs(pow(R,2));
}