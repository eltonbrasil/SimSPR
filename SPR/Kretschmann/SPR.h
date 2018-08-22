#define SPR_H

class SPR{
	
	private:
		
		typedef std::complex<double> Complex;

		ComplexMatrix M;
		ComplexMatrix M_2;
		ComplexMatrix M_T;
		
		double lambda, K; 

	public:	
	
		double Reflectance(double, double, double, double, double, double, double, double, double);
	
}spr;

double SPR::Reflectance(double theta_i, double wavelength, double d, double real, double imag, double real_2, double imag_2, double d_2, double n_prism){

	// ***
	// Initializing variables and setting local variables
	// ***

	double lambda = wavelength * pow(10,-9);		 		// Wavelenght (nm)

	double K = (2*M_PI) / lambda;					 		// Constant K

	Complex j = Complex (0, 1);

	M =   ComplexMatrix (2, 2);
	M_2 = ComplexMatrix (2, 2);
	M_T = ComplexMatrix (2, 2);
	
	// ***
	// Refractive index for each layer
	// ***

	Complex n_metal   = Complex (real, imag); // First Layer
	double  n_metal_2 = real_2;				  // Second Layer

	// ***
    // Layers thickness values (nm)
    // ***

    double d_metal =   d * pow(10,-9);		  // First Layer
    double d_metal_2 = d_2 * pow(10,-9);	  // Second Layer

    // ***
    // Admittance
    // ***

    Complex q = Complex (sqrt(pow(n_metal,2) - pow(n_prism*sin(theta_i*(M_PI/180)),2)) / pow(n_metal,2));
    double  q_2 =  sqrt(pow(n_metal_2,2) - pow(n_prism*sin(theta_i*(M_PI/180)),2)) / pow(n_metal_2,2);

    // ***
    // Shift Phase
    // ***

    Complex beta = Complex (K*d_metal*sqrt(pow(n_metal,2) - pow(n_prism*sin(theta_i*(M_PI/180)),2)));
    double  beta_2 = K*d_metal_2*sqrt(pow(n_metal_2,2) - pow(n_prism*sin(theta_i*(M_PI/180)),2));

    // ***
	// Scattering matrix terms for each interface (Prism / First metal layer)
	// ***

	M(0,0) = (cos(beta*(M_PI/180)));

	M(0,1) = (-j/q)*sin(theta_i*(M_PI/180));

	M(1,0) = (-j*q*sin(theta_i*(M_PI/180)));

	M(1,1) = (cos(beta*(M_PI/180)));

	// ***
	// Scattering matrix terms for each interface (First metal layer / Second metal layer)
	// ***

	M_2(0,0) = (cos(beta_2*(M_PI/180)));

	M_2(0,1) = (-j/q_2)*sin(theta_i*(M_PI/180));

	M_2(1,0) = (-j*q_2*sin(theta_i*(M_PI/180)));

	M_2(1,1) = (cos(beta_2*(M_PI/180)));

	// ****
	// Matrix Total
	// ***

	for (int row = 0; row < 2; row++) {
    	for (int col = 0; col < 2; col++) {
    		for (int inner = 0; inner < 2; inner++) {

        		M_T(row, col) += M(row, inner)*M_2(inner, col);
        
        	}
      	}
    }

	// ****
	// Calculing Fresnel reflection coefficientes for the P_polarized wave between interface
	// ***

	Complex num = Complex (M_T(0,0) + M_T(0,1)*q_2)*q - (M_T(1,0) + M_T(1,1)*q_2);
	Complex den = Complex (M_T(0,0) + M_T(0,1)*q_2)*q + (M_T(1,0) + M_T(1,1)*q_2);

	Complex rp_wave = Complex (num / den);

	return (abs(pow(rp_wave, 2))); // Return reflectance value
}