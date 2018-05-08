#include "../GeneralClasses/IncludeFile.h"

int main (){

    ofstream out_R;
    out_R.open("reflectance.txt");

    double r_metal;         // Metal refractive index (real part)
    double i_metal;         // Metal refractive index (imaginary part)
    double d_metal;         // Layer thickness value (nm)
    double n_prism; 		// Prism refractive index

	double wavelength;		// Incident wavelength

    float theta_i = 0;      // Incident angle

    int N;                  // Number of Layers
	int count;

    double real[N], *r;
    r = &real[0]; 

    double imag[N], *i;        
    i = &imag[0];

    double thickness[N], *d;        
    d = &thickness[0];

    cout <<
	"---------------------------------------------------------------------------------------" << "\n"
	"---------------------------------- Welcome to Sim-SPR ---------------------------------" << "\n\n" 
	" An Open Source for Surface Plasmon Resonance simulation implemented in C++ language   " << "\n\n"
	"---------------------------------------------------------------------------------------" << "\n\n";

	cout << "## This Open Source works using Kretschmann configuration for N metals" << endl << endl; 

    cout << "## Type the incident light wavelength (nm):" << endl;
    cin >> wavelength;

    cout << "## Type the prism refractive index:" << endl;
    cin >> n_prism;

	cout << "## Type the number (N) of layers:" << endl;
	cin >> N;

    for (count = 1; count < N; count++) {

        cout << "Layer | Type the refractive index:" << endl;
        cout << count << "\t" << "Real part" << "\t\t:";
        cin >> r_metal;
        
        cout << "Layer | Type the refractive index:" << endl;
        cout << count << "\t" << "Imaginary part" << "\t\t:";
        cin >> i_metal;

        cout << "Layer | Type the layer thickness:" << endl;
        cout << count << "\t" << "Layer thickness" << "\t\t:";
        cin >> d_metal;

        getchar();

        *(r+count) = r_metal; 
        *(i+count) = i_metal; 
        *(d+count) = d_metal; 

    }

    while (theta_i <= 90){

            out_R << theta_i << "\t\t" << spr.Reflectance(theta_i, n_prism, wavelength, thickness[1], thickness[count+1], real[1], imag[1], real[count+1], imag[count+1]) << endl;
            
            // out_R << theta_i << "\t\t" << s_SPR.Reflectance(theta_i, real[1], imag[1], real[2], imag[2], n_prism, wavelength, thickness[1], thickness[2]) << endl;

            theta_i = theta_i + 0.1;
        
    }

    cout <<
    "---------------------------------------------------------------------------------------" << "\n"
    "------------------------------------ Sim-SPR - REPORT ---------------------------------" << "\n\n";
    
    cout << "Number of Layers: " << N << endl << endl;
    cout << "Wavelength: " << wavelength << " nm" << endl << endl;
    cout << "Prism refractive index:\t" << n_prism << endl << endl;

    for (count = 1; count < N; count++) {

        cout << "Layer " << count << ": " << real[count] << "+" << imag[count] << "j" << endl << endl;
        cout << "Thickness " << count << ": " << thickness[count] << " nm" << endl << endl;
                      
    }

    cout << "--> You can check your simulation results (Incident angle x Reflectivity) in the output file" << "\n\n";

    out_R.close();
    return 0;
}