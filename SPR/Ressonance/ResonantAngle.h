#define ResonantAngle_H

class ResonantlAngle{
	
	private:

		double theta_spr;
		
	public:	
	
		double SPR_Angle (double, double, double); // SPR angle function
	
}t_spr;

double ResonantlAngle::SPR_Angle(double e_3r, double n_prism, double e_analyte){

	double param = sqrt((e_analyte * abs(e_3r)) / (abs(e_3r) - e_analyte)) / n_prism;

	theta_spr = asin (param) * (180 / M_PI);

	return (theta_spr);

}