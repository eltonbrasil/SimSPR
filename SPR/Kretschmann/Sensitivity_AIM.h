#define SENSITIVITY_AIM_H

class SENSITIVITY_AIM{

private:

	typedef std::complex<double> Complex; 			// Sensitivity for Angular Interrogation method
	
public:

	double Sensitivity (double, double, double);

}s;

double SENSITIVITY_AIM::Sensitivity(double theta_i, double n_prism, double n_analyte){

	// ***
	// Determining the real part of the dielectric constant of metal layer by coupling condition
	// ***

	// ***
	// Sensitivity for Angular Interrogation Mode
	// ***

	return (e_mr);  // Return sensitivity value for the three-layer system
}