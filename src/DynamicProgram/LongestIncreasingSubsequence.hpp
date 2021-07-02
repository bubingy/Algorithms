#include <assert.h>

/// <summary>
/// find the length of the longest subsequence of a given sequence 
/// such that all elements of the subsequence are sorted in increasing order.
/// </summary>
/// <typeparam name="t">Comparable.</typeparam>
/// <param name="array">input array.</param>
/// <param name="array_size">size of input array.</param>
/// <returns>size of longest increasing subsequence.</returns>
template<typename t> std::vector<size_t>
LongestIncreasingSubsequence(t* array, size_t array_size)
{
	assert(array_size > 0);
	std::vector<size_t> temp(array_size, 1);

	for (size_t i = 1; i < array_size; i++)
		for (size_t j = 0; j < i; j++)
			if (array[i] > array[j] && temp[j] + 1 > temp[i])
				temp[i] = temp[j] + 1;
	
	std::vector<size_t> result;
	size_t lis_size = 0;
	result.push_back(lis_size);
	for (size_t i = 1; i < array_size; i++)
		if (temp[i] > lis_size)
		{
			result.push_back(i);
			lis_size = temp[i];
		}

	return result;
};