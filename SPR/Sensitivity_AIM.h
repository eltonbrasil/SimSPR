#define SENSITIVITY_AIM_H

class SENSITIVITY_AIM{

private:

	std::complex<double> S; 			// Sensitivity for Angular Interrogation method

public:

	double Sensitivity (double, double, double);

}sensi;

double SENSITIVITY_AIM::Sensitivity(double n_prism, double n_analyte, double e_mr){

	// ***
	// Defining local variables
	// ***

	std::complex<double> i(0, 1); // Defining an imaginary number
	std::complex<double> num (e_mr * sqrt(-e_mr));
				 double  den = ((e_mr + pow(n_analyte, 2)) * sqrt(e_mr * (pow(n_analyte, 2) - pow(n_prism,2)) - pow(n_analyte,2)*pow(n_prism,2)));
	
	// ***
	// Sensitivity for Angular Interrogation method
	// ***

	std::complex<double> S (num / den);

	return (abs(S));  // Return sensitivity value for the three-layer system
}