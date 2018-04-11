
#define PHYSICALCONSTANTS_H

#define _USE_MATH_DEFINES

class PhysicalConstants
{ 

public:
	
	// c is the light`s velocity (m/s)
	constexpr static double c = 299792458;

	// u_0 is the permeability of free space (H/m)
	constexpr static double u_0 = 4*M_PI*pow(10,-7);

	// e_0 is the electric permitivity of free space (F/m)
	constexpr static double e_0 = 8.854 * pow(10,-12);

	// Thickness of prism (mm)
	constexpr static double d_0 = 3 * pow(10,-3); 
 
}obj_Const; 