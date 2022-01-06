#include <math.h>

double
EstimatePI()
{
	double N = 1000000;
	double dx = 1 / N;

	double I = 0;

	for (double i = 0; i < 12 * N;)
	{
		double x = -(i * dx) * (i * dx);
		I = I + exp(x) * dx;
		i = i + 1;
	}
	double pi = 4 * I * I;
	return pi;
}