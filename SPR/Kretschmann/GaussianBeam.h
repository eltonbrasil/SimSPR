#define GaussianBeam_H

class GaussianBeam{

	private:

		typedef std::complex<double> Complex;

		double lambda, K0;

	public:

		double Reflectance (double, double, double, double, double, double, double, double, double, double);

}gaussian;

	// ***
	// Reflectance value for SPR effect using a Gaussian beam (LED) 
    // for four-layer Kretschmann and Otto Configuration
	// ***

double GaussianBeam::Reflectance(double theta_i, double wavelength, double n_prism, double n2_r, double n2_i, double n_analyte, double n4_r, double n4_i, double d2, double d3){

	// Initializing parameters
	
	const std::complex<double> i(0,1);	// Imaginary number
	double r = 2;						// aux real number
	double r_aux = 1;					// aux real number
	lambda = wavelength * pow(10,-9); 	// Wavelength (nm)
	K0 = (2*M_PI) / lambda;		  	  	// K0 is the free space wavenumber of optical wave
	// ************************************************************************************

	// Refractive index for each layer
	
	Complex n_2 = Complex (n2_r, n2_i);	// Complex refractive index metal layer
	Complex n_4 = Complex (n4_r, n4_i);	// Complex refractive index metal layer
	// ************************************************************************************

	// Layers thickness values (nm)
    
	double d_2 = d2 * pow(10,-9);		// (2nd layer) Metal Layer thickness value (nm)
	double d_3 = d3 * pow(10,-9);  		// (3th layer) Dielectric layer thickness value (nm)
	// ************************************************************************************

    // Wave number in vacuum (Ki & KiY)
  
    double K1 = K0 * n_prism;			//  Prism (real number)			
    double K3 = K0 * n_analyte;			//	Analyte (real number)

    Complex K2 = Complex (K0 * n_2);	// 2nd Layer (complex number)			
    Complex K4 = Complex (K0 * n_4);	// 4th Layer (complex number)

    double K1Y = K0*n_prism*sin(theta_i*(M_PI/180));	//  Prism (real number)			
    double K3Y = K0*n_analyte*sin(theta_i*(M_PI/180));	//	Analyte (real number)

    Complex K2Y = Complex (K0 * n_2 * sin(theta_i*(M_PI/180)));	// 2nd Layer (complex number)			
    Complex K4Y = Complex (K0 * n_4 * sin(theta_i*(M_PI/180)));	// 4th Layer (complex number)
    // ************************************************************************************

    // Wave number of normal component of each medium (KiZ)

    double K1Z = sqrt(pow(K1,2) - pow(K1Y,2));	//  Prism (real number)
    double K3Z = sqrt(pow(K3,2) - pow(K3Y,2)); //	Analyte (real number)

    Complex K2Z = std::sqrt(pow(K2,2) - pow(K2Y,2)); // 2nd Layer (complex number)
    Complex K4Z = std::sqrt(pow(K4,2) - pow(K4Y,2)); // 4th Layer (complex number)
    // ************************************************************************************

    // Fresnel reflection coefficients

    Complex r_12 = Complex (((K1Z / pow(n_prism,2)) - (K2Z / pow(n_2,2))) / (K1Z / pow(n_prism,2)) + (K2Z / pow(n_2,2)));
    Complex r_23 = Complex (((K2Z / pow(n_2,2)) - (K3Z / pow(n_analyte,2))) / (K2Z / pow(n_2,2)) + (K3Z / pow(n_analyte,2)));
    Complex r_34 = Complex (((K3Z / pow(n_analyte,2)) - (K4Z / pow(n_4,2))) / (K3Z / pow(n_analyte,2)) + (K4Z / pow(n_4,2)));
    // ************************************************************************************

    // Fresnel reflection coefficient (r_p) for p-polarized Gaussian beam

    Complex N = Complex (r_12 + r_12*r_23*r_34*std::exp(r*i*K3Z*d_3) + std::exp(r*i*K2Z*d_2)*(r_23 + r_34*std::exp(r*i*K3Z*d_3)));
    Complex D = Complex (r_aux + r_23*r_34*std::exp(r*i*K3Z*d_3) + r_12*std::exp(r*i*K2Z*d_2)*(r_23 + r_34*std::exp(r*i*K3Z*d_3)));

    Complex r_p = Complex (N / D);
    // ************************************************************************************

    // Reflectance (R) for p-polarized Gaussian beam

    double theta_alpha = atan( std::imag(N*std::conj(D)) / std::real(N*std::conj(D)) );
    double R_alpha = pow(abs(r_p),2);
    Complex r_alpha = std::sqrt(R_alpha)*std::exp(i*theta_alpha);

    Complex R = Complex ((pow(theta_i,2)/r)*std::real(r*i*(r_aux / tan(theta_i))*(r_p / r_alpha)));
    // (std::real(2*i*(1 / tan(theta_i))));

    return abs(R);    
}