#define K4Layers_H

class K4Layers{
	
	private:

		typedef std::complex<double> Complex; // Standard complex data type

		double K0, omega, d2, d3, theta_1, R;
		
	public:	
	
		double Reflectance(double, double, double, double, double, double, double, double, double, double);
	
}kre_4;


double K4Layers::Reflectance(double theta_i, double wavelength, double n_p, double n2_r, double n2_i, double n3_r, double n3_i, double n_a, double d_2, double d_3){

	// ***
	// Initializing parameters based on input
	// ***

	K0 = (2*M_PI) / (wavelength * pow(10,-9));
	omega = K0 * obj_Const.c;
	d2 = d_2 * pow(10,-9);
	d3 = d_3 * pow(10,-9);
	
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
	Complex index2 = Complex (n2_r, n2_i);
	Complex index3 = Complex (n3_r, n3_i);	
	Complex index4 = Complex (n_a,0);		

	// ***
	// Calculate propagation angles within each layer
	// ***

	theta_1 = theta_i;
	Complex theta_2 = Complex (sqrt(real_number - pow((index1/index2),2)*pow(sin(theta_1),2)));
	Complex theta_3 = Complex (sqrt(real_number - pow((index1/index3),2)*pow(sin(theta_1),2)));
	Complex theta_4 = Complex (sqrt(real_number - pow((index1/index4),2)*pow(sin(theta_1),2)));

	// ***
	// Calculate terms for reflection at boundaries
	// ***

	Complex q1 = Complex (index1 * K0 * cos(theta_1));
	Complex q2 = Complex (index2 * K0 * theta_2);
	Complex q3 = Complex (index3 * K0 * theta_3);
	Complex q4 = Complex (index3 * K0 * theta_4);

	if(q2.imag() > 0){

		q2 = q2 * neg_number;

	}
		

	if(q3.imag() > 0){

		q3 = q3 * neg_number;
	
	}		

	if(q4.imag() > 0){

		q4 = q4 * neg_number;
	
	}	

	// ***
	// Calculation of first layer terms layer
	// ***

	Complex Z1 = Complex (q1 / (omega * pow(index1,2)));

	// ***
	// Calculation of second layer terms layer
	// ***

	Complex Z2 = Complex (q2 / (omega * pow(index2,2)));

	Complex qprod_2 = Complex (d2 * q2);

	// ***
	// Calculation of second layer terms layer
	// ***

	Complex A2 = Complex (cos(qprod_2));
	Complex B2 = Complex (sin(qprod_2) * (im_number * Z2));
	Complex C2 = Complex (((im_number * sin(qprod_2)) / Z2));
	Complex D2 = Complex (cos(qprod_2));

	// ***
	// Calculation of third layer terms layer
	// ***

	Complex Z3 = Complex (q3 / (omega * pow(index3,2)));
	Complex qprod_3 = Complex (d3 * q3);

	// ***
	// Calculation of third layer terms layer
	// ***

	Complex A3 = Complex (cos(qprod_3));
	Complex B3 = Complex (sin(qprod_3) * (im_number * Z3));
	Complex C3 = Complex (((im_number * sin(qprod_3)) / Z3));
	Complex D3 = Complex (cos(qprod_3));

	// ***
	// Calculation of fourth layer terms layer
	// ***

	Complex Z4 = Complex (q4 / (omega * pow(index4,2)));

	Complex A = Complex(A2*A3 + B2*C3);
	Complex B = Complex(A2*B3 + B2*D3);
	Complex C = Complex(C2*A3 + D2*C3);
	Complex D = Complex(C2*B3 + D2*D3);

	// ***
	// Reflectance 
	// ***

	Complex Rnum = Complex (A + (B/Z4) - Z1*(C+(D/Z4)));
	Complex Rdem = Complex (A + (B/Z4) + Z1*(C+(D/Z4)));
	Complex R1 =   Complex (Rnum/Rdem);
	
	R =    sqrt(pow(R1.real(),2) + pow(R1.imag(),2));
	
	return pow(R,2);
}