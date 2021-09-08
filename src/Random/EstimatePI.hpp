#include <thread>
#include <assert.h>
#include <chrono>
#include <random>

double
EstimatePI(size_t poch)
{
	assert(poch > 0);

	std::uniform_real_distribution<double> distX(-1.0, 1.0);
	std::uniform_real_distribution<double> distY(-1.0, 1.0);
	std::random_device engnX;
	std::random_device engnY;

	size_t pi = 0;

	for (size_t i = 0; i < poch; i++)
	{
		auto x = distX(engnX);
		auto y = distY(engnY);
		if (x * x + y * y < 1)
			pi++;
	}
	return 4.0 * (double)pi / poch;
}