#define SENSITIVITY_AIM_H

class SENSITIVITY_AIM{

private:

	typedef std::complex<double> Complex; 			// Sensitivity for Angular Interrogation method
	
public:

	double Sensitivity (double, double, double);

}s;

double SENSITIVITY_AIM::Sensitivity(double theta_i, double n_prism, double n_analyte){

	Complex j = Complex (0,1);		  				// Complex imaginary number

	// ***
	// Determining the real part of the dielectric constant of metal layer by coupling condition
	// ***

	double num = (pow(n_analyte,2)*pow(n_prism,2)*pow(sin(theta_i*(M_PI/180)),2));
	double den = (pow(n_analyte,2)-pow(n_prism,2)*pow(sin(theta_i*(M_PI/180)),2));

	double e_mr = num/den;

	// ***
	// Sensitivity for Angular Interrogation Mode
	// ***

	return (e_mr);  // Return sensitivity value for the three-layer system
}