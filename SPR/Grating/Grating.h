#define Grating_H

class Grating{

private:

	typedef std::complex<double> Complex;
	double lambda, K0, L;
	
public:

	double grating (double, double, double, double, double);

}grid;

double Grating::grating(double wavelength, double n_prism, double theta_i, double l, double n_d){
	
	// ***
	// Initializing parameters
	// ***

	lambda = wavelength * pow(10,-9); 				// Wavelength (nm)
	K0 = (2*M_PI) / lambda;							// K0 is the free space wavenumber of optical wave
	L = l * pow(10,-9);	  							// Grating period (nm)

	// ***
	// The component of the wavenumber along x-axis
	// ***

	double Kx_0 = K0 * n_prism * sin(theta_i*(M_PI/180));  					// For l=0, Floquet harmonic
	double Kx_1 = K0 * n_prism * sin(theta_i*(M_PI/180)) + ((2*M_PI)/L);	// For l=1, Floquet harmonic

	// ***
	// The other parameters
	// ***

	double Kzp_0 = pow(K0,2)*pow(n_prism,2) - pow(Kx_0,2);
	double Kzp_1 = pow(K0,2)*pow(n_prism,2) - pow(Kx_1,2);

	double Kzt_0 = pow(K0,2)*pow(n_d,2) - pow(Kx_0,2);
	double Kzt_1 = pow(K0,2)*pow(n_d,2) - pow(Kx_1,2);

	// ***
	// Linear Reflectance and Transmittance
	// ***

	std::complex <double> MyComplex (Kzp_0,0);
	std::complex <double> Num (std::sqrt(MyComplex));
	std::complex <double> R_0 (Num.real() / MyComplex);

	std::complex <double> MyComplex_2 (Kzp_1,0);
	std::complex <double> Num_2 (std::sqrt(MyComplex_2));
	std::complex <double> R_1 (Num_2.real() / MyComplex);

	std::complex <double> MyComplex_3 (Kzt_0,0);
	std::complex <double> Num_3 (std::sqrt(MyComplex_3));
	std::complex <double> T_0 (Num_3.real() / MyComplex);

	std::complex <double> MyComplex_4 (Kzt_1,0);
	std::complex <double> Num_4 (std::sqrt(MyComplex_4));
	std::complex <double> T_1 (Num_4.real() / MyComplex);

	// ***
	// Absorptance
	// ***

	std::complex <double> A_p (R_0 + R_1 + T_0 + T_1);

	return (abs(T_0));
}