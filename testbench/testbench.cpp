#include "../GeneralClasses/IncludeFile.h"

int main (){

    ofstream out_R;
    out_R.open("reflectance.txt");

    double r_metal;         // Metal refractive index (real part)
    double i_metal;         // Metal refractive index (imaginary part)
    double n_prism; 		// Prism refractive index

	double wavelength;		// Incident wavelength

    float theta_i = 0;

    int N;                  // Number of Layers
	int count;

    double real[N], *r;
    r = &real[0]; 

    double imag[N], *i;        
    i = &imag[0];

    // ***
    // Set Layers thickness values (nm)
    // ***

    double d_metal = 50;

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

        getchar();

        *(r+count) = r_metal; //valor é gravado no endereço apontado pelo ponteiro
        *(i+count) = i_metal; //valor é gravado no endereço apontado pelo ponteiro

    }

    while (theta_i <= 90){
             
        out_R << theta_i << "\t\t" << spr.Reflectance(theta_i, n_prism, wavelength, d_metal, real[1], imag[1]) << endl;
        theta_i = theta_i + 0.1;
        
    }
    
    cout <<
    "---------------------------------------------------------------------------------------" << "\n"
    "------------------------------------ Sim-SPR - REPORT ---------------------------------" << "\n\n";
    
    cout << "Number of Layers: " << N << endl << endl;
    cout << "Wavelength: " << wavelength << "nm" << endl << endl;
    cout << "Prism refractive index:\t" << n_prism << endl << endl;

    for (count = 1; count < N; count++) {

        cout << "Layer " << count << ": " << real[count] << "+" << imag[count] << "j" << endl;
                      
    }

    cout << endl;
    cout << "--> You can check your simulation results (Incident angle x Reflectivity) in the output file" << "\n\n";

    out_R.close();
    return 0;
}