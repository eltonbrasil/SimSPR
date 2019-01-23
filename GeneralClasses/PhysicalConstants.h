
#define PHYSICALCONSTANTS_H

#define _USE_MATH_DEFINES

#define PI 3.14159265

class PhysicalConstants
{ 

public:
	
	// c is the light`s velocity (m/s)
	constexpr static double c = 3*pow(10,8);

	// u_0 is the permeability of free space (H/m)
	constexpr static double u_0 = 4*M_PI*pow(10,-7);

	// e_0 is the electric permitivity of free space (F/m)
	constexpr static double e_0 = 8.854 * pow(10,-12);

}obj_Const; 
