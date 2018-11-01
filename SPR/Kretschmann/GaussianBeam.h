#define GaussianBeam_H

class GaussianBeam{

	private:

		typedef std::complex<double> Complex;
		double lambda, K0;

	public:

		double Reflectance ();

}gaussian;

	// ***
	// Reflectance value for SPR effect using a Gaussian beam (LED) 
    // for four-layer Kretschmann and Otto Configuration
	// ***

double GaussianBeam::Reflectance(){

	// Initializing parameters
	
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

    // Fresnel relection coefficients

    Complex r_12 = Complex (((K1Z / pow(n_prism,2)) - (K2Z / pow(n_2,2))) / (K1Z / pow(n_prism,2)) + (K2Z / pow(n_2,2)));
    Complex r_23 = Complex (((K2Z / pow(n_2,2)) - (K3Z / pow(n_analyte,2))) / (K2Z / pow(n_2,2)) + (K3Z / pow(n_analyte,2)));
    Complex r_34 = Complex (((K3Z / pow(n_analyte,2)) - (K4Z / pow(n_4,2))) / (K3Z / pow(n_analyte,2)) + (K4Z / pow(n_4,2)));
    // ************************************************************************************

    // Fresnel relection coefficients
    
}