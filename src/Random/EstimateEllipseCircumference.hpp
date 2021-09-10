#include <omp.h>
#include <assert.h>
#include <math.h>
#include <chrono>
#include <random>

double
EstimateI1(double a, double b, size_t poch = 10000000)
{
	assert(poch > 0);
	assert(b > 0);
	assert(a > b);

	std::uniform_real_distribution<double> distX(-a / 2.0, a / 2.0);
	std::uniform_real_distribution<double> distY(
		0, sqrt(1.0 + 4.0 * pow(b, 2) / 3.0 / pow(a, 2)));

	std::random_device engnX;
	std::random_device engnY;

	size_t circumference = 0;

	omp_lock_t lock;
	omp_init_lock(&lock);

#pragma omp parallel for
	for (long long i = 0; i < poch; i++)
	{
		auto x = distX(engnX);
		auto y = distY(engnY);
		if (pow(y, 2) - 1 < pow(b, 2) * pow(x, 2) / pow(a, 2) / (pow(a, 2) - pow(x, 2)))
		{
			omp_set_lock(&lock);
			circumference++;
			omp_unset_lock(&lock);
		}
	}
	omp_destroy_lock(&lock);
	return (double)circumference / (double)poch * a * sqrt(1.0 + 4.0 * pow(b, 2) / 3.0 / pow(a, 2));
}

double
EstimateI2(double a, double b, size_t poch = 10000000)
{
	assert(poch > 0);
	assert(b > 0);
	assert(a > b);

	std::uniform_real_distribution<double> distX(- sqrt(3) * b / 2.0, sqrt(3) * b / 2.0);
	std::uniform_real_distribution<double> distY(
		0, sqrt(1.0 + 3.0 * pow(a, 2) / pow(b, 2)));

	std::random_device engnX;
	std::random_device engnY;

	size_t circumference = 0;

	omp_lock_t lock;
	omp_init_lock(&lock);

#pragma omp parallel for
	for (long long i = 0; i < poch; i++)
	{
		auto x = distX(engnX);
		auto y = distY(engnY);
		if (pow(y, 2) - 1 < pow(a, 2) * pow(x, 2) / pow(b, 2) / (pow(b, 2) - pow(x, 2)))
		{
			omp_set_lock(&lock);
			circumference++;
			omp_unset_lock(&lock);
		}
	}
	omp_destroy_lock(&lock);
	return (double)circumference / (double)poch * sqrt(3) * b * sqrt(1.0 + 3.0 * pow(a, 2) / pow(b, 2));
}

/// <summary>
/// Estimate circumference of ellipse with Monte Carlo method.
/// </summary>
/// <param name="a">major axis.</param>
/// <param name="b">minor axis.</param>
/// a must be larger than b.
/// <param name="poch">sampling times.</param>
/// <returns>circumference of ellipse.</returns>
double
EstimateEllipseCircumference(double a, double b, size_t poch = 10000000)
{
	assert(poch > 0);
	assert(b > 0);
	assert(a > b);
	return 2 * (EstimateI1(a, b, poch) + EstimateI2(a, b, poch));
}
