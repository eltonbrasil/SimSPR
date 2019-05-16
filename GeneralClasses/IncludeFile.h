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
#include "Metals.h"
#include "Timer.h"
#include "Timer.cpp"

#include "../SPR/Kretschmann/K3Layers.h"
#include "../SPR/Otto/Otto3Layers.h"
#include "../SPR/Fiber/OpticalFiber.h"
#include "../SPR/Ressonance/CriticalAngle.h"
#include "../SPR/Ressonance/ResonantAngle.h"