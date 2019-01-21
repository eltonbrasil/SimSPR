#define INCLUDEFILE_H

// Include math libraries

#include <complex>
#include <math.h>
#include <cmath>

// Include general libraries

#include <octave/oct.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// Include Files

#include "PhysicalConstants.h"
#include "Timer.h"
#include "Timer.cpp"

#include "../SPR/Kretschmann/SPR3Layers.h"
#include "../SPR/Kretschmann/GaussianBeam.h"
#include "../SPR/Kretschmann/Sensitivity_AIM.h"
#include "../SPR/Otto/Otto3Layers.h"
#include "../SPR/Grating/Grating.h"