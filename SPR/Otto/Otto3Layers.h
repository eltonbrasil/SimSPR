#define Otto3Layers_H

class Otto3Layers{
	
	private:

		typedef std::complex<double> Complex; // Standard complex data type

		double K0, omega, thickness, theta_1, R;
		
	public:	
	
		double Reflectance(double, double, double, double, double, double, double);
	
}OttoSpr;

double Otto3Layers::Reflectance(double wavelength, double n_p, double n_analyte, double theta_i, double n3_r, double n3_i, double d){

	// ***
	// Initializing parameters based as input
	// ***

	K0 = (2*M_PI) / (wavelength * pow(10,-9));
	omega = K0 * obj_Const.c;
	thickness = d * pow(10,-9);
	
	// ***
	// Real and Imaginary Complex Numbers
	// ***

	Complex neg_number =  Complex (-1,0);
	Complex im_number =   Complex (0,1);
	Complex real_number = Complex (1,0);

	// ***
	// Set here the refractive index for each layer
	// ***

	Complex index1 = Complex (n_p,0);
	Complex index2 = Complex (n_analyte,0);
	Complex index3 = Complex (n3_r, n3_i);	

	// ***
	// Calculate propagation angles within each layer
	// ***

	theta_1 = theta_i;
	Complex theta_2 = Complex (sqrt(real_number - pow((index1/index2),2)*pow(sin(theta_1),2)));
	Complex theta_3 = Complex (sqrt(real_number - pow((index1/index3),2)*pow(sin(theta_1),2)));

	// ***
	// Calculate terms for reflection at boundaries
	// ***

	Complex q1 = Complex (index1 * K0 * cos(theta_1));
	Complex q2 = Complex (index2 * K0 * theta_2);
	Complex q3 = Complex (index3 * K0 * theta_3);

	if(q2.imag() > 0){

		q2 = q2 * neg_number;

	}
		

	if(q3.imag() > 0){

		q3 = q3 * neg_number;
	
	}		

	// ***
	// Calculation of first layer terms
	// ***

	Complex Z1 = Complex (q1 / (omega * pow(index1,2)));

	// ***
	// Calculation of second layer terms
	// ***

	Complex Z2 = Complex (q2 / (omega * pow(index2,2)));

	Complex qprod = Complex (thickness * q2);

	Complex A = Complex (cos(qprod));
	Complex B = Complex (sin(qprod) * (im_number * Z2));
	Complex C = Complex (((im_number * sin(qprod)) / Z2));
	Complex D = Complex (cos(qprod));

	// ***
	// Calculation of third layer terms
	// ***

	Complex Z3 = Complex (q3 / (omega * pow(index3,2)));

	// ***
	// Reflectance 
	// ***

	Complex Rnum = Complex (A + (B/Z3) - Z1*(C+(D/Z3)));
	Complex Rdem = Complex (A + (B/Z3) + Z1*(C+(D/Z3)));
	Complex R1 =   Complex (Rnum/Rdem);
	
	R =    sqrt(pow(R1.real(),2) + pow(R1.imag(),2));
	
	return pow(R,2);
}