#include "../GeneralClasses/IncludeFile.h"

int main (){

    ofstream out_R;
    out_R.open("reflectance.txt");

    double r_metal;         // Metal refractive index (real part)
    double i_metal;         // Metal refractive index (imaginary part)
    double d_metal;         // Layer thickness value (nm)
    double n_prism; 		// Prism refractive index

	double wavelength;		// Incident wavelength
    double wavelength_2;    // Incident wavelength for WIM operation

    double theta_i = 0;      // Incident angle
    double theta_SPR;        // Surface Plasmon Resonance angle

    int N = 3;              // Number of Layers
	int interface, mode;

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

	cout << "## This Open Source works using Kretschmann configuration for N layers" << endl << endl;

    cout << "## Choose the operation mode | AIM (1) or WIM (2) |: " << endl;
	cin >> mode;

    cout << "## Type the prism refractive index:" << endl;
    cin >> n_prism;

    if(mode == 1){

        cout << "## Type the incident light wavelength (nm):" << endl;
        cin >> wavelength;

    }

    if(mode == 2){

        cout << "## First value  | Incident light wavelength (nm) range:" << endl;
        cin >> wavelength;

        cout << "## Second value | Incident light wavelength (nm) range:" << endl;
        cin >> wavelength_2;

        cout << "## SPR angle:" << endl;
        cin >> theta_SPR;

    }

    for (interface = 1; interface < N; interface++) {

        cout << "Layer | Type the refractive index:" << endl;
        cout << interface << "\t" << "Real part" << "\t\t:";
        cin >> r_metal;
        
        cout << "Layer | Type the refractive index:" << endl;
        cout << interface << "\t" << "Imaginary part" << "\t\t:";
        cin >> i_metal;

        cout << "Layer | Type the layer thickness:" << endl;
        cout << interface << "\t" << "Layer thickness" << "\t\t:";
        cin >> d_metal;

        getchar();

        *(r+interface) = r_metal; 
        *(i+interface) = i_metal; 
        *(d+interface) = d_metal; 

    }

    if(mode == 1){

        while (theta_i <= 90){
                    
            out_R << theta_i << "\t\t" << spr.Reflectance(theta_i, wavelength, thickness[1], real[1], imag[1], real[2], imag[2], thickness[2], n_prism) << endl;
            theta_i = theta_i + 0.1;

        }
    }

    if(mode == 2){

        while (wavelength <= wavelength_2){
                    
            out_R << wavelength << "\t\t" << spr.Reflectance(theta_SPR, wavelength, thickness[1], real[1], imag[1], real[2], imag[2], thickness[2], n_prism) << endl;
            wavelength = wavelength + 0.1;

        }
    }

    cout <<
    "---------------------------------------------------------------------------------------" << "\n"
    "------------------------------------ Sim-SPR - REPORT ---------------------------------" << "\n\n";
    
    if(mode == 1){

        cout << "Operation mode: AIM" << endl << endl;

        cout << "Wavelength: " << wavelength << " nm" << endl << endl;

    }

    if(mode == 2){
        
        cout << "Operation mode: WIM" << endl << endl;

        cout << "SPR angle: " << theta_SPR << endl << endl;

    }

    cout << "Number of Layers: " << N << endl << endl;

    cout << "Prism refractive index:\t" << n_prism << endl << endl;

    for (interface = 1; interface < N; interface++) {

        cout << "Layer " << interface << ": " << real[interface] << "+" << imag[interface] << "j" << endl << endl;
        cout << "Thickness " << interface << ": " << thickness[interface] << " nm" << endl << endl;
                      
    }

    cout << "--> You can check your simulation results (Incident angle x Reflectivity) in the output file" << "\n\n";

    out_R.close();
    return 0;
}