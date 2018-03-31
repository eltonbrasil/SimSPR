#define SINGLELAYERSPR_H

class SLayerSPR{

public:

	std::complex<double> Reflectance;
	std::complex<double> Transmittance;

	double beta;
	double param;
		
public:

	double ParamSPR(double);
	double PhaseShift(double);
	
}obj_SLayer;

double SLayerSPR::ParamSPR(double theta_i){

	obj_Fresnel.FresnelTermP(theta_i); // Calculating Fresnel terms for P-polarized wave

	// Local variables
	std::complex<double> i(0, 1); // Defining an imaginary complex number i = sqrt(-1)
	std::complex<double> realN(1, 0); // Defining a real complex number   

	param = PhaseShift(theta_i);

	// Local variables
	std::complex<double> S_11 (exp(param*i) / obj_Fresnel.tp_wave); // First row & first column of the scattering matrix
	std::complex<double> S_21 (obj_Fresnel.rp_wave * S_11); // Second row & first column of the scattering matrix 

	std::complex<double> Reflectance (pow((S_21 / S_11), 2)); // To compute relectance for the one-layer system
	std::complex<double> Transmittance (pow((realN / S_11), 2)); // To compute transmittance for the one-layer system

	return(abs(Reflectance));
}

double SLayerSPR::PhaseShift(double theta_i){ 

	double k = (2* M_PI) / (obj_Const.lambda);

	beta = k*(obj_Fresnel.n_2)*(obj_Const.d)*cos(theta_i*(M_PI/180)); // Phase shift Beta describes in each layer of thickness

	return (beta);
}