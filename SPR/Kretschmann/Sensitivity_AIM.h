#define SENSITIVITY_AIM_H

class SENSITIVITY_AIM{

private:

	typedef std::complex<double> Complex; 			// Sensitivity for Angular Interrogation method
	double S_AIM;
	
public:

	double Sensitivity (double, double, double);

}s;

double SENSITIVITY_AIM::Sensitivity(double e_mr, double n_prism, double n_analyte){

	// ***
	// Sensitivity for Angular Interrogation Mode
	// ***
	
	Complex N = Complex (e_mr * sqrt(-e_mr));
	double  D = (e_mr + pow(n_analyte,2)) * sqrt(e_mr*(pow(n_analyte,2) - pow(n_prism,2)) - pow(n_analyte,2)*pow(n_prism,2));

	return (abs(N / D));  // Return sensitivity value for the three-layer system
}
