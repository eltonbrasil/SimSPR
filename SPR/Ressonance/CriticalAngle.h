#define CriticalAngle_H

class CriticalAngle{
	
	private:

		double theta_c;
		
	public:	
	
		double TIR (double, double); // Total Internal Reflection function to determine the critical angle
	
}c_spr;

double CriticalAngle::TIR(double n_analyte, double n_prism){

	double param = (n_analyte / n_prism);

	theta_c = asin (param) * (180 / PI);

	return (theta_c);

}