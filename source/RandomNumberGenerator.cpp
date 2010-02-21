#include <math.h>
#include <values.h>
#include "RandomNumberGenerator.h"

using namespace std;

RandomNumberGenerator::RandomNumberGenerator(int a, int b, int c) {
	RandomNumberGenerator::a = a;
	RandomNumberGenerator::b = b;
	RandomNumberGenerator::c = c;
}

RandomNumberGenerator::~RandomNumberGenerator() {}

double RandomNumberGenerator::uniformDistribution(){

	static int n;
	static double d,x;

	d = (a + b + c) * 8192;
	x = fmod (d,4294967291.0);
	a = b; b = c; c= x;
	
	if (x < (float) 2147483648.0) {
		n = (int) x;
	} else { 
		n = (int) (x - 4294967296.0);
	}
	
	return (n * 2.3283064365e-10 + 0.5);
}

double RandomNumberGenerator::normalDistribution(){

	bool ok = false;
	double limit = sqrt(2/2.718281828);
	double X;
	
	do {
		double U = uniformDistribution();                     // generuj U o rozkładzie równomiernym U(0,1) 
		double V = 2 * limit * uniformDistribution() - limit; // generuj V o rozkładzie równomiernym U(-sqrt(2/e),sqrt(2/e))
		X = V / U;
		
		if (X*X <= 2*(3-U*(4+U))) {
			ok = true;
		} else if (X*X <= 2/U - 2*U) {
			if (X*X <= -4*log(U)) {
				ok = true;
			}
		}	
		
	} while (!ok);
	
	return X;
}

double RandomNumberGenerator::cauchyDistribution(){

	double X = uniformDistribution() * 2 - 1;	// generuj X o rozkładzie równomiernym U(-1,1)
	double U = uniformDistribution();			// generuj X o rozkładzie równomiernym U(0,1)

	if ((U + 0.27324) * (1+X*X) > 1.27324) {
		X = uniformDistribution() * 2 - 1;
	}
	
	if (uniformDistribution() > 0.5) {
		return X;
	} else {
		if (X != 0) {
			return (1/X);
		} else {
			return MAXDOUBLE;
		}
	}

}
