#define Metals_H

class Metals{

public:
	double n_gold(double);
	double n_graphene(double);
	double k_gold(double);
	double k_graphene(double);

}metal;

double Metals::n_gold(double wavelength){

	// ***
	// Gold refractive Index (n) for each wavelength
	// ***

	double wave = wavelength * pow(10,9);
	double n = 0.119598 + (1.424477 / (1 + pow(wave/497.67163,26.828965)));

	return (n);
}

double Metals::k_gold(double wavelength){

	// ***
	// Gold extinction coefficient (k) for each wavelength
	// ***

	double wave = wavelength * pow(10,9);
	double a, b, c, d, e, k;
	a = 74.338954;
	b = -0.50443003 * wave;
	c = 0.00055449218  * pow(wave,2) * log (wave);
	d = -0.00015735883 * pow(wave,2.5);
	e = 1.5828 * pow (10,-6) * pow(wave,3);
	k = a + b + c + d + e;

	return (k);
}

double Metals::n_graphene(double wavelength){

	return (3);
}

double Metals::k_graphene(double wavelength){

	double C = 5.446 * pow(10,-6);
	double k = (C*wavelength) / 3;
	return (k);
}