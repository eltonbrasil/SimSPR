#define SPR4Layers_H

class SPR4Layers{
	
	private:
		
		typedef std::complex<double> Complex;
		
		double lambda, K, R;

	public:	
	
		double Reflectance(double, double, double, double, double, double, double, double, double, double);
	
}spr;

double SPR4Layers::Reflectance(double theta_i, double wavelength, double n_prism, double n_analito, double n2_r, double n2_i, double n3_r, double n3_i, double d2, double d3){

	// ***
	// Initializing variables and setting local variables
	// ***

	lambda = wavelength * pow(10,-9); // Wavelength (nm)
	K = (2*M_PI) / lambda;		  	  // Constant K

	Complex j = Complex (0,1);		  // Complex imaginary number
	Complex r = Complex (1,0);		  // Complex real number
	Complex r2 = Complex (2,0);		  // Complex real number

	// ***
	// Refractive index for each layer
	// ***

	Complex n_2 = Complex (n2_r, n2_i);
	Complex n_3 = Complex (n3_r, n3_i);

	// ***
    // Layers thickness values (nm)
    // ***

	double d_2 = d2 * pow(10,-9);
    double d_3 = d3 * pow(10,-9);		 

	// ***
	// Component of the wave vector of the reflection from mediums
	// ***

	Complex K1 = Complex (K*(sqrt(pow(n_prism,2)) - pow(n_prism,2)*pow(sin(theta_i*(M_PI/180)),2)));
	Complex K2 = Complex (K*(sqrt(pow(n_2,2)) - pow(n_prism,2)*pow(sin(theta_i*(M_PI/180)),2)));
	Complex K3 = Complex (K*(sqrt(pow(n_3,2)) - pow(n_prism,2)*pow(sin(theta_i*(M_PI/180)),2)));
	Complex K4 = Complex (K*(sqrt(pow(n_analito,2)) - pow(n_prism,2)*pow(sin(theta_i*(M_PI/180)),2)));

	// ***
	// Fresnel reflection coefficients for the P_polarized wave between interfaces
	// ***

	Complex r_12 = Complex (((K1 / pow(n_prism,2)) - (K2 / pow(n_2,2))) / ((K1 / pow(n_prism,2)) + (K2 / pow(n_2,2))));

	Complex r_23 = Complex (((K2 / pow(n_2,2)) - (K3 / pow(n_3,2))) / ((K2 / pow(n_2,2)) + (K3 / pow(n_3,2))));

	Complex r_34 = Complex (((K3 / pow(n_3,2)) - (K4 / pow(n_analito,2))) / ((K3 / pow(n_analito,2)) + (K4 / pow(n_analito,2))));

	Complex r_234 = Complex ((r_23 + r_34*exp(j*r2*K3*d_3)) / (r + r_23*r_34*exp(j*r2*K3*d_3)));

	Complex r_1234 = Complex ((r_12 + r_234*exp(j*r2*K2*d_2)) / (r + r_12*r_234*exp(j*r2*K2*d_2)));

	// ***
	// Reflectance 
	// ***

	R = (abs(pow(r_1234,2)));

	return (R);
}