#pragma once

#include <assert.h>
#include <iostream>
#include "Eigen/Core"
#include "unsupported/Eigen/MatrixFunctions"

double
SimpleDefiniteIntegral(double (*func)(double), double lower_limit, double upper_limit, double dx)
{
	assert(upper_limit > lower_limit);
	double I = 0;
	double block_size = 256;
	long long matrix_size;
	double steps;
	Eigen::ArrayXd x;
	Eigen::ArrayXd v;
	while (true)
	{
		steps = floor((upper_limit - lower_limit) / dx);
		matrix_size = std::min(steps, block_size);
		if (matrix_size <= 0) break;

		x = Eigen::ArrayXd::LinSpaced(matrix_size + 1, lower_limit, lower_limit + ((double)(matrix_size + 1)) * dx);
		x *= -x;
		v = x.unaryExpr(std::ref(func));
		v = v.array();
		I += (2 * v(Eigen::seq(1, matrix_size - 1)).sum() + v[0] + v[matrix_size]) * dx / 2;
		lower_limit += (double)matrix_size * dx;
	}
	return I;
}