#pragma once

#include <list>
#include <assert.h>

long long GreatestCommonDivisor(long long a, long long b)
{
	assert(a > 0 && b > 0);
	long long x = std::max(a, b);
	long long y = std::min(a, b);
	long long r;
	while (y != 0)
	{
		r = x % y;
		x = y;
		y = r;
	}
	return x;
}

std::list<long long> SieveOfEratosthenes(long long range)
{
	assert(range > 0);
	long long stop_divisor = sqrt(range);
	// initialize the list
	std::list<long long> prime_list = {2};
	for (long long i = 3; i < range; i += 2) prime_list.push_back(i);

	std::list<long long>::iterator outer_iter, inner_iter;
	outer_iter = prime_list.begin();
	outer_iter++;

	for (; outer_iter != prime_list.end(); outer_iter++)
	{
		if (*outer_iter > stop_divisor) break;
		if (*outer_iter == 0) continue;
		for (inner_iter = outer_iter; inner_iter != prime_list.end(); inner_iter++)
		{
			if (inner_iter == outer_iter) continue;
			if (*inner_iter == 0) continue;
			if ((*inner_iter) % (*outer_iter) == 0) *inner_iter = 0;
		}
	}
	prime_list.remove(0);
	return prime_list;
}