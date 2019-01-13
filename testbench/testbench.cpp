#include "../GeneralClasses/IncludeFile.h"

int main (void){

    ofstream out_R;
    out_R.open("reflectance.txt");

    ofstream GaussianBeam;
    GaussianBeam.open("gaussian.txt");

    ofstream Grating;
    Grating.open("grating.txt");

    double r_metal;          // Metal refractive index (real part)
    double i_metal;          // Metal refractive index (imaginary part)
    double d_metal;          // Layer thickness value (nm)
    double n_prism; 		 // Prism refractive index
    double n_d;              // Absorptance spectrums

	double wavelength;		 // Incident wavelength
    
    double theta_i = 27;      // Incident angle
    
    int N = 4;               // Set number of Layers
	int interface, choose, L;

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
    cout << "(3) Combination of Grating and Prism Couplings" << endl << endl;

    cin >> choose;

    if (choose == 1){

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
        // Start timer
        timer.start();
        while (theta_i <= 90){                    
           out_R << theta_i << "\t\t" << spr.Reflectance(theta_i, wavelength, n_prism, real[2], real[1], imag[1], thickness[1]) << endl;
           theta_i = theta_i + 0.1; 
        }
        // stop timer
        timer.stop();           
    }

    else if (choose == 2){

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
        // Start timer
        timer.start();
        while (theta_i <= 90){                    
           out_R << theta_i << "\t\t" << spr.Reflectance(theta_i, wavelength, n_prism, real[2], real[1], imag[1], thickness[1]) << endl;
           theta_i = theta_i + 0.1; 
        }
        // stop timer
        timer.stop();           
    }

    else{

        cout << "## Type the incident light wavelength [nm]:" << endl;
        cin >> wavelength;

        cout << "## Type the prism refractive index [RIU]:" << endl;
        cin >> n_prism;

        cout << "## Type the grating period [nm]:" << endl;
        cin >> L;

        cout << "## Type the absorptance spectrums:" << endl;
        cin >> n_d;

        // Start timer
        timer.start();
        while (theta_i <= 90){                    
           Grating << theta_i << "\t\t" << grid.grating(wavelength, n_prism, theta_i, L, n_d) << endl;
           theta_i = theta_i + 0.1; 
        }
        // stop timer
        timer.stop(); 
    }

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

    cout << "Sensitivity [deg/RIU]:\t" << s.Sensitivity(e_mr, n_prism, real[2]) << endl << endl;

    cout << "Simulation Time: " << timer.getElapsedTimeInMilliSec() << " ms" << endl << endl;

    cout << "--> You can check your simulation results (Incident angle x Reflectivity) in the output file" << "\n\n";

    out_R.close();
    Grating.close();
    GaussianBeam.close();
    return 0;
}