#include "../GeneralClasses/IncludeFile.h"

int main (void){

    ofstream out_R;
    out_R.open("reflectance.txt");

    double r_metal;          // Metal refractive index (real part)
    double i_metal;          // Metal refractive index (imaginary part)
    double d_metal;          // Layer thickness value (nm)
    double n_prism; 		 // Prism refractive index
    double n_d;              // Absorptance spectrums

	double wavelength;		 // Incident wavelength
    
    double theta_i = 0.1745; // Incident angle
    
    int N = 3;               // Set number of Layers
	int interface, choose;

    double e_mr = -129.17;   // Set the real part of the dielectric constant of the metal layer for each wavelength,
                             // if you want to check the sensitivity
    double real[N], *r;
    r = &real[0]; 

    double imag[N], *i;        
    i = &imag[0];

    double thickness[N], *d;        
    d = &thickness[0];

    Timer timer;

    cout <<
	"----------------------------------------------------------------------------------------" << "\n"
	"---------------------------------- Welcome to Sim-SPR ----------------------------------" << "\n\n" 
	" An Open-Source Surface Plasmon Resonance Simulator for Academic and Industrial Purposes" << "\n\n"
	"----------------------------------------------------------------------------------------" << "\n\n";

	cout << "## Choose the configuration and type the respective number:" << endl << endl;

    cout << "(1) Kretschmann-Raether" << endl;
    cout << "(2) Turbadar-Otto" << endl;
    
    cin >> choose;

    cout << endl;

    cout << "## Type the incident light wavelength (nm):" << endl;
    cin >> wavelength;

    cout << "## Type the prism refractive index:" << endl;
    cin >> n_prism;

    for (interface = 1; interface < N; interface++){

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

    // ***
    // Kretschmann-Raether configuration
    // ***

    if(choose == 1){
    // Start timer
        timer.start();
        while (theta_i <= 90){                    
            out_R << theta_i << "\t\t" << spr.Reflectance(theta_i, wavelength, n_prism, real[2], real[1], imag[1], thickness[1]) << endl;
            theta_i = theta_i + 0.1; 
        }
    // stop timer
    timer.stop();
    }

    // ***
    // Turbadar-Otto configuration
    // ***

    if(choose == 2){
    // Start timer
        timer.start();
        while (theta_i <= 1.5707){                    
            out_R << OttoSpr.Reflectance(wavelength, n_prism, real[1], theta_i, real[2], imag[2], thickness[1]) << endl;
            theta_i = theta_i + 0.01; 
        }
    // stop timer
    timer.stop();
    }    

    cout << real[1] << "\t\t" << real[2] << "\t\t" << imag[2] << "\t\t" << thickness[1] << endl;

    out_R.close();
    
    return 0;
}