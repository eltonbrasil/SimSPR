#ifndef FRESNEL_H
#define FRESNEL_H

#include <include/GeneralClasses/PhysicalConstants.h>

class Fresnel
{
private:
	int n_air = 1;
	int n_glass = 1.5168;

public:
	void FresnelTerms();
};
