#pragma once

#include <cmath>
#include "DefiniteIntegral.hpp"

double N = pow(2, 20);
double dx = 1 / N;

double
EstimatePI()
{
	double I = SimpleDefiniteIntegral(exp, 0, 12, dx);
	double pi = 4 * I * I;
	return pi;
}