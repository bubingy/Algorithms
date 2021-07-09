#include <assert.h>

template<typename t> std::vector<size_t>
MaximumSumSubsequence(t* array, size_t array_size)
{
	assert(array_size > 0);
	for (size_t i = 0; i < array_size; i++)
	{
		if (array[i] < 0)
			continue;
		for (size_t j = i; j < array_size; j++)
		{

		}
	}
}