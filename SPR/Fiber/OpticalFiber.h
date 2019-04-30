#define OpticalFiber_H

class OpticalFiber{

private:
	typedef std::complex<double> Complex; 		// Standard complex data type
	double R, K0, d0, d1, d2, n, k;

public:
	double Reflectance(double, double, double, double, double, double, double, double, double);
	double n_gold(double);
	double k_gold(double);
	double n_graphene(double);
	double k_graphene(double);
	double ReflectanceWIM(double, double, double, double, double, double, double, double, double);

}fiber_spr;

double OpticalFiber::n_graphene(double wavelength){
	
	// ***
	// Graphene refractive Index (n) for each wavelength
	// ***

	n = 3;

	return(n);
}

double OpticalFiber::k_graphene(double wavelength){
	
    // ***
	// Graphene extinction coefficient (k) for each wavelength
	// ***

	double wave = wavelength * pow(10,9);
	k = ((5.446*wave*pow(10,-6))/3);

	return(n);
}

double OpticalFiber::n_gold(double wavelength){

	// ***
	// Gold refractive Index (n) for each wavelength
	// ***

	double wave = wavelength * pow(10,9);
	n = 0.119598 + (1.424477 / (1 + pow(wave/497.67163,26.828965)));

	return (n);
}

double OpticalFiber::k_gold(double wavelength){

	// ***
	// Gold extinction coefficient (k) for each wavelength
	// ***

	double wave = wavelength * pow(10,9);
	double a, b, c, d, e;
	a = 74.338954;
	b = -0.50443003 * wave;
	c = 0.00055449218  * pow(wave,2) * log (wave);
	d = -0.00015735883 * pow(wave,2.5);
	e = 1.5828 * pow (10,-6) * pow(wave,3);
	k = a + b + c + d + e;

	return (k);
}


double OpticalFiber::Reflectance(double theta_i, double wavelength, double n_p, double d_silica, double eps_r, double eps_i, double d_metal, double n_a, double d_a){

	// ***
	// Initializing parameters based as input
	// ***

	Complex i = Complex (0,1);
	K0 = (2*M_PI) / (wavelength * pow(10,-9));
	d0 = d_silica * pow(10,-6);
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
	Complex etaP_0 = Complex (pow(n0,2) / etaS_0);								// for p-wave (TM)

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

double OpticalFiber::ReflectanceWIM(double theta_spr, double wavelength, double n_si, double d_si, double n, double k, double d_metal, double n_a, double d_a){

	// ***
	// Initializing parameters based as input
	// ***

	Complex i = Complex (0,1);
	K0 = (2*M_PI) / (wavelength);
	d0 = d_si 	  * pow(10,-6);
	d1 = d_metal  * pow(10,-9);
	d2 = d_a      * pow(10,-9);

	Complex n0      = Complex (n_si,0);
	Complex n_metal = Complex (n,k);
	Complex na      = Complex (n_a,0);

	// ***
	// Phase Factor (delta) for each layer
	// ***

	Complex delta_0 = K0 * d0 * Complex (sqrt(pow(n0,2)      - pow(n0,2)*pow(sin(theta_spr),2)));
	Complex delta_1 = K0 * d1 * Complex (sqrt(pow(n_metal,2) - pow(n0,2)*pow(sin(theta_spr),2)));
	Complex delta_2 = K0 * d2 * Complex (sqrt(pow(na,2)      - pow(n0,2)*pow(sin(theta_spr),2)));

	// ***
	// Optical Admittance (eta) as function of the polarization states
	// ***

	// First Layer: silica

	Complex etaS_0 = Complex (sqrt(pow(n0,2) - pow(n0,2)*pow(sin(theta_spr),2))); 	// for s-wave (TE)
	Complex etaP_0 = Complex (pow(n0,2) / etaS_0);									// for p-wave (TM)

	// Second Layer: metal

	Complex etaS_1 = Complex (sqrt(pow(n_metal,2) - pow(n0,2)*pow(sin(theta_spr),2))); // for s-wave (TE)
	Complex etaP_1 = Complex (sqrt(pow(n_metal,2) / etaS_1));						   // for p-wave (TM)

	// Third Layer: analyte

	Complex etaS_2 = Complex (sqrt(pow(na,2) - pow(n0,2)*pow(sin(theta_spr),2))); 	// for s-wave (TE)
	Complex etaP_2 = Complex (pow(na,2) / etaS_2);									// for p-wave (TM)

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