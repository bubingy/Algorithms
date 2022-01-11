#pragma once

#include <cmath>
#include "DefiniteIntegral.hpp"

double N = pow(2, 20);
double dx = 1 / N;

double
IntegrandFunction(double x)
{
	return exp(- x * x);
}

double
EstimatePI()
{
	double I = SimpleDefiniteIntegral(IntegrandFunction, 0, 12, dx);
	double pi = 4 * I * I;
	return pi;
}