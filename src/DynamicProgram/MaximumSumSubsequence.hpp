#include <assert.h>
#include <vector>
#include <list>

template<typename t> std::list<t>
MaximumSumSubsequence(t* array, size_t array_size)
{
	assert(array_size > 0);
	t max_sum = 0;
	t temp_sum = 0;
	size_t left_bound = 0;
	size_t right_bound = 0;

	std::vector<t> sum_records;

	for (size_t i = 0; i < array_size; i++)
	{
		temp_sum = std::max(temp_sum + array[i], array[i]);
		sum_records.push_back(temp_sum);

		if (temp_sum > max_sum)
		{
			max_sum = temp_sum;
			right_bound = i;
		}
	}

	std::list<t> MaximumSumSubsequence;
	for (size_t i = right_bound; i >= 0; i--)
	{
		if (sum_records[i] <= 0)
			break;
		MaximumSumSubsequence.push_front(array[i]);
	}

	return MaximumSumSubsequence;
}