#include <iostream>
#include <octave/oct.h>

int main (void){
  
    ComplexMatrix matrix;
    matrix = ComplexMatrix (2, 2);

    typedef std::complex<double> Complex;

    Complex n_metal = Complex (0.3, 0.7);

    Complex q = sqrt(pow(n_metal,2) - pow(1.5*sin(45*(M_PI/180)),2)) / pow(n_metal,2);

    for(int r = 0; r < 2; r++){
        for(int c = 0; c < 2; c++){
            matrix (r, c) = Complex (r + 1, c + 1);

        }
    }

    std::cout << q << std::endl;

    return 0;
}
