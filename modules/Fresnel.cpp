
#include <tests/main.cpp>
class RefractiveIndices
{
private:
	int n_air = 1;
	int n_glass = 1.5168;

public:
	void FresnelTerms();
};