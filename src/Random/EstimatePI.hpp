#include <omp.h>
#include <assert.h>
#include <chrono>
#include <random>

/// <summary>
/// Estimate PI with Monte Carlo method.
/// </summary>
/// <param name="poch">sampling times.</param>
/// <returns>PI</returns>
double
EstimatePI(size_t poch = 10000000)
{
	assert(poch > 0);

	std::uniform_real_distribution<double> distX(-1.0, 1.0);
	std::uniform_real_distribution<double> distY(-1.0, 1.0);
	std::random_device engnX;
	std::random_device engnY;

	size_t pi = 0;

	omp_lock_t lock;
	omp_init_lock(&lock);

#pragma omp parallel for
	for (long long i = 0; i < poch; i++)
	{
		auto x = distX(engnX);
		auto y = distY(engnY);
		if (x * x + y * y < 1)
		{
			omp_set_lock(&lock);
			pi++;
			omp_unset_lock(&lock);
		}
	}
	omp_destroy_lock(&lock);
	return 4.0 * (double)pi / poch;
}