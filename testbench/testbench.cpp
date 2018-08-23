#include "../GeneralClasses/IncludeFile.h"

int main (){

    ofstream out_R;
    out_R.open("reflectance.txt");

    fstream out_S;
    out_S.open("sensitivity.txt");

    double r_metal;          // Metal refractive index (real part)
    double i_metal;          // Metal refractive index (imaginary part)
    double d_metal;          // Layer thickness value (nm)
    double n_prism; 		 // Prism refractive index

	double wavelength;		 // Incident wavelength
    
    double theta_i = 0;      // Incident angle
    
    int N;                   // Set number of Layers
	int interface;

    double real[N], *r;
    r = &real[0]; 

    double imag[N], *i;        
    i = &imag[0];

    double thickness[N], *d;        
    d = &thickness[0];

    Timer timer;

    cout <<
	"---------------------------------------------------------------------------------------" << "\n"
	"---------------------------------- Welcome to Sim-SPR ---------------------------------" << "\n\n" 
	" An Open Source for Surface Plasmon Resonance Simulation Implemented in C++ Language   " << "\n\n"
	"---------------------------------------------------------------------------------------" << "\n\n";

	cout << "## This Open Source works using Kretschmann and Otto configuration for N layers" << endl << endl;

    cout << "## Number of layers:" << endl;
    cin >> N;

    cout << "## Type the prism refractive index:" << endl;
    cin >> n_prism;

    cout << "## Type the incident light wavelength (nm):" << endl;
    cin >> wavelength;
         

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

    // Start timer
    timer.start();

    while (theta_i <= 90){
                    
        out_R << theta_i << "\t\t" << spr.Reflectance(theta_i, wavelength, n_prism, real[2], real[1], imag[1], thickness[1]) << endl;
        out_S << theta_i << "\t\t" << s.Sensitivity(theta_i, n_prism, real[2]) << endl;
            
        theta_i = theta_i + 0.1;

    }
    // stop timer
    timer.stop();
    
    cout <<
    "---------------------------------------------------------------------------------------" << "\n"
    "------------------------------------ Sim-SPR - REPORT ---------------------------------" << "\n\n";
    
    cout << "Operation mode: AIM" << endl << endl;

    cout << "Wavelength: " << wavelength << " nm" << endl << endl;

    cout << "Number of Layers: " << N << endl << endl;

    cout << "Prism refractive index:\t" << n_prism << endl << endl;

    for (interface = 1; interface < N; interface++) {

        cout << "Layer " << interface << ": " << real[interface] << "+" << imag[interface] << "j" << endl << endl;
        cout << "Thickness " << interface << ": " << thickness[interface] << " nm" << endl << endl;
                      
    }

    cout << "Simulation Time: " << timer.getElapsedTimeInMilliSec() << " ms" << endl << endl;

    cout << "--> You can check your simulation results (Incident angle x Reflectivity) in the output file" << "\n\n";

    out_R.close();
    return 0;
}