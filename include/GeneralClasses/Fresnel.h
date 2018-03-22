#include "PhysicalConstants.h"
#define FRESNEL_H

class Fresnel
{
public:
	int n_air = 1;
	int n_glass = 1.5168;

public:
	void FresnelTerms();
};
