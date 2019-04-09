#include "../GeneralClasses/IncludeFile.h"

int main (void){

    ofstream out;
    out.open("reflectance.dat");

    FILE *fp;

    fp = popen( "gnuplot -persist", "w" );

    double r_metal;                 // Metal refractive index (real part)
    double i_metal;                 // Metal refractive index (imaginary part)
    double d_metal;                 // Layer thickness value (nm)
    double n_prism; 		        // Prism refractive index
    double n_analyte;               // Analyte refractive index
	double wavelength;		        // Incident wavelength
    
    double theta_i = 0.1745;        // Start Incident Angle (in radians -> 10 degrees)
        
    unsigned int N = 3;             // Set number of Layers

    double step_scale = 0.001;      // Set the step scale interval
    
	int interface, choose;

    double real[N], *r;
    r = &real[0]; 

    double imag[N], *i;        
    i = &imag[0];

    double thickness[N], *d;        
    d = &thickness[0];

    Timer timer;

    cout <<
	"|----------------------------------------------------------------------------------------------|" << "\n"
	"|------------------------------------- Welcome to Sim-SPR -------------------------------------|" << "\n" 
	"| Sim-SPR is an open-source SPR simulator developed for the study of Surface Plasmon Resonance |" << "\n"
    "| of different materials using angular operation mode. In particular, Sim-SPR involved the     |" << "\n"
    "| numerical analysis of angular and spectral variation of reflectance calculated by using the  |" << "\n"
    "| characteristic transfer matrix method. Sim-SPR works for Kretschmann-Raether & Turbadar-Otto |" << "\n"
    "| configurations. The accuracy, efficiency and reliability of the Sim-SPR were validated by    |" << "\n"
    "| comparing results generated by using other simulation tools already consolidated in the lite-|" << "\n"
    "| rature and results of SPR experiments with standard samples.                                 |" << "\n"
	"|----------------------------------------------------------------------------------------------|" << "\n\n";

	cout << "# Choose the configuration and type the respective number:" << endl << endl;

    cout << "(1) Kretschmann-Raether" << endl;
    cout << "(2) Turbadar-Otto" << endl;

    cin >> choose;

    cout << endl;

    // ***
    // Angular Interrogation Mode (AIM)
    // ***    

    if(choose == 1 || choose == 2){

        cout << "# Type the incident light wavelength (nm):" << endl;
        cin >> wavelength;

        cout << "# Type the prism refractive index:" << endl;
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
    }

    // ***
    // Kretschmann-Raether configuration
    // ***

    if (choose == 1){
    
        if (N == 3){
            // Start timer
            timer.start();
            while (theta_i <= 1.5707){  // 90 in degrees                    
                out << (theta_i * (180/M_PI)) << "\t\t" << kre_3.Reflectance(wavelength, n_prism, real[2], theta_i, real[1], imag[1], thickness[1]) << endl;
                theta_i = theta_i + step_scale; 
            }
            // stop timer
            timer.stop();

            // ***
            // Critical Angle and Resonant Angle
            // ***  
        
            cout << "The critical angle for this SPR configuration is: " << c_spr.TIR(real[2], n_prism) << " degrees" <<endl;
            cout << "The resonant angle for this SPR configuration is: " << t_spr.SPR_Angle(real[1], n_prism, real[2]) << " degrees" <<endl;
        }
        if (N == 4){
            // Start timer
            timer.start();
            while (theta_i <= 1.5707){  // 90 in degrees                    
                out << (theta_i * (180/M_PI)) << "\t\t" << kre_4.Reflectance(theta_i, wavelength, n_prism, real[1], imag[1], real[2], imag[2], real[3], thickness[1], thickness[2]) << endl;
                theta_i = theta_i + step_scale; 
            }
            // stop timer
            timer.stop();

            // ***
            // Critical Angle and Resonant Angle
            // ***  
        
            cout << "The critical angle for this SPR configuration is: " << c_spr.TIR(real[3], n_prism) << " degrees" <<endl;
            cout << "The resonant angle for this SPR configuration is: " << t_spr.SPR_Angle(real[2], n_prism, real[3]) << " degrees" <<endl;
        }    

    }    

    // ***
    // Turbadar-Otto configuration
    // ***

    if(choose == 2){
    // Start timer
    timer.start();
        while (theta_i <= 1.5707){  // 90 in degrees                   
            out << (theta_i * (180/M_PI)) << "\t\t" << OttoSpr.Reflectance(wavelength, n_prism, real[1], theta_i, real[2], imag[2], thickness[1]) << endl;
            theta_i = theta_i + step_scale; 
        }
    // stop timer
    timer.stop();

    // ***
    // Critical Angle and Resonant Angle
    // ***  
    
    cout << "The critical angle for this SPR configuration is: " << c_spr.TIR(real[1], n_prism) << " degrees" <<endl;
    cout << "The resonant angle for this SPR configuration is: " << t_spr.SPR_Angle(real[2], n_prism, real[1]) << " degrees" <<endl;
   
    }

    // ***
    // An user C code can also activate gnuplot and pipe a gnuplot script into it. 
    // ***

    fprintf(fp, "set size ratio 0.5 \n");
    fprintf(fp, "set title  \'SPR Curve\'\n" );
    fprintf(fp, "set xlabel \'Incidence Angle (degrees)\'\n" );
    fprintf(fp, "set ylabel \'Reflectance\'\n" );
    fprintf(fp, "set grid \n");
    fprintf(fp, "set xrange [0:90] \n");                       
    fprintf(fp, "plot \'reflectance.dat\' using 1:2 with lines \n");
    fflush (fp);
    pclose(fp);

    // ***
    // 
    // ***

    cout << endl;

    out.close();
        
    return 0;
}