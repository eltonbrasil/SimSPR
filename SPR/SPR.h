#define SPR_H

class SPR{
	
	private:
		
		typedef std::complex<double> Complex;

		ComplexMatrix M;    

		double lambda, K; 

	public:	
	
		double Reflectance(double, double, double, double, double, double);
	
}spr;

double SPR::Reflectance(double theta_i, double wavelength, double d, double real, double imag, double n_prism){

	// ***
	// Initializing variables and setting local variables
	// ***

	double lambda = wavelength * pow(10,-9);		 		// Wavelenght (nm)

	double K = (2*M_PI) / lambda;					 		// Constant K

	Complex j = Complex (0, 1);

	M = ComplexMatrix (2, 2);

	// ***
	// Refractive index for each layer
	// ***

	Complex n_metal = Complex (real, imag);

	// ***
    // Layers thickness values (nm)
    // ***

    double d_metal = d * pow(10,-9);

    // ***
    // Admittance
    // ***

    Complex q = Complex (sqrt(pow(n_metal,2) - pow(n_prism*sin(theta_i*(M_PI/180)),2)) / pow(n_metal,2));

    // ***
    // Shift Phase
    // ***

    Complex beta = Complex (K*d_metal*sqrt(pow(n_metal,2) - pow(n_prism*sin(theta_i*(M_PI/180)),2)));

    // ***
	// Scattering matrix terms for each interface (Prism / First metal layer)
	// ***

	M(0,0) = cos(beta*(M_PI/180));

	M(0,1) = (-j/q)*sin(theta_i*(M_PI/180));

	M(1,0) = -j*q*sin(theta_i*(M_PI/180));

	M(1,1) = cos(beta*(M_PI/180));

	// ****
	// Calculing Fresnel reflection coefficientes for the P_polarized wave between interface
	// ***

	Complex num = Complex (M(0,0) + M(0,1)*q)*q - (M(1,0) + M(1,1)*q);
	Complex den = Complex (M(0,0) + M(0,1)*q)*q + (M(1,0) + M(1,1)*q);

	Complex rp_wave = Complex (num / den);

	return (abs(pow(rp_wave, 2))); // Return reflectance value
}