#define OpticalFiber_H

class OpticalFiber{

private:
	typedef std::complex<double> Complex; 		// Standard complex data type
	double R, K0, d0, d1, d2;

public:
	double Reflectance(double, double, double, double, double, double, double, double, double);


}fiber_spr;

double OpticalFiber::Reflectance(double theta_i, double wavelength, double n_p, double d_silica, double eps_r, double eps_i, double d_metal, double n_a, double d_a){

	// ***
	// Initializing parameters based as input
	// ***

	Complex i = Complex (0,1);
	K0 = (2*M_PI) / (wavelength * pow(10,-9));
	d0 = d_silica * pow(10,-9);
	d1 = d_metal  * pow(10,-9);
	d2 = d_a      * pow(10,-9);


	Complex n0    = Complex (n_p,0);
	Complex eps_m = Complex (eps_r,eps_i);
	Complex na    = Complex (n_a,0);
	
	// ***
	// Phase Factor (delta) for each layer
	// ***

	Complex delta_0 = K0 * d0 * Complex (sqrt(pow(n0,2) - pow(n0,2)*pow(sin(theta_i),2)));
	Complex delta_1 = K0 * d1 * Complex (sqrt(eps_m     - pow(n0,2)*pow(sin(theta_i),2)));
	Complex delta_2 = K0 * d2 * Complex (sqrt(pow(na,2) - pow(n0,2)*pow(sin(theta_i),2)));

	// ***
	// Optical Admittance (eta) as function of the polarization states
	// ***

	// First Layer: silica

	Complex etaS_0 = Complex (sqrt(pow(n0,2) - pow(n0,2)*pow(sin(theta_i),2))); // for s-wave (TE)
	Complex etaP_0 = Complex (pow(n0,2) / etaS_0);									// for p-wave (TM)

	// Second Layer: metal

	Complex etaS_1 = Complex (sqrt(eps_m - pow(n0,2)*pow(sin(theta_i),2)));     // for s-wave (TE)
	Complex etaP_1 = Complex (eps_m / etaS_1);									// for p-wave (TM)

	// Third Layer: analyte

	Complex etaS_2 = Complex (sqrt(pow(na,2) - pow(n0,2)*pow(sin(theta_i),2))); // for s-wave (TE)
	Complex etaP_2 = Complex (pow(na,2) / etaS_2);								// for p-wave (TM)

	// ***
	// Characteristic Matrix of the layered system
	// ***

	// First Layer: silica

	Complex M11_0 = Complex (cos (delta_0));
	Complex M12_0 = Complex (-i*sin(delta_0)/etaP_0);
	Complex M21_0 = Complex (-i*sin(delta_0)*etaP_0);
	Complex M22_0 = Complex (cos (delta_0));

	// Second Layer: metal

	Complex M11_1 = Complex (cos (delta_1));
	Complex M12_1 = Complex (-i*sin(delta_1)/etaP_1);
	Complex M21_1 = Complex (-i*sin(delta_1)*etaP_1);
	Complex M22_1 = Complex (cos (delta_1));

	// Total Characteristic Matrix

	Complex MT_11 = Complex (M11_0*M11_1 + M12_0*M21_1);
	Complex MT_12 = Complex (M11_0*M12_1 + M12_0*M22_1);
	Complex MT_21 = Complex (M21_0*M11_1 + M22_0*M21_1);
	Complex MT_22 = Complex (M21_0*M12_1 + M22_0*M22_1);

	// ***
	// Fresnel Reflection Coefficients
	// ***

	Complex Num = Complex ((MT_11 + MT_12*etaP_2)*etaP_0 - (MT_21 + MT_22*etaP_2));
	Complex Den = Complex ((MT_11 + MT_12*etaP_2)*etaP_0 + (MT_21 + MT_22*etaP_2));

	Complex R1 =  Complex (Num/Den);
	
	R =  sqrt(pow(R1.real(),2) + pow(R1.imag(),2));
	
	return pow(R,2);

}