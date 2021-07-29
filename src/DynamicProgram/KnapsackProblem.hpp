#include <vector>
#include <map>

std::vector<size_t>
MaximumValueKnapsack_0_1(size_t capacity,
	std::map<size_t, double>& weight_value_map)
{
	std::vector<double> max_value(capacity+1, 0);
	std::vector<size_t> solution;
	double solution_sum = 0;

	for (std::map<size_t, double>::iterator iter = weight_value_map.begin(); 
		iter != weight_value_map.end(); iter++)
	{
		for (long long i = capacity; i >= 0; i--)
		{
			if (iter->first <= i)
				max_value[i] = std::max(max_value[i],
					max_value[i-iter->first] + iter->second);
		}
		double maximum_max_value = max_value[capacity];
		size_t weight = capacity;
		for (; weight > 0; weight--)
			if (max_value[weight] < maximum_max_value)
				break;
		if (solution_sum<capacity)
		{
			solution.push_back(weight + 1);
			solution_sum += (weight + 1);
		}
	}
	return solution;
}


std::vector<size_t>
MaximumValueKnapsack_Unbounded(size_t capacity,
	std::map<size_t, double>& weight_value_map)
{
	std::vector<double> max_value(capacity + 1, 0);
	std::vector<std::tuple<size_t, size_t>> previous;
	previous.push_back(std::tuple<size_t, size_t>(0, 0));
	std::map<size_t, double>::iterator iter;

	for (size_t i = 1; i <= capacity; i++)
	{
		double temp_max_value = 0;
		size_t previous_weight = 0;
		size_t current_weight = 0;
		for (iter = weight_value_map.begin(); 
			iter != weight_value_map.end(); iter++)
		{
			if (i >= iter->first)
			{
				if (max_value[i - iter->first] + iter->second > temp_max_value)
				{
					temp_max_value = max_value[i - iter->first] + iter->second;
					previous_weight = i - iter->first;
					current_weight = iter->first;
				}
			}
		}
		previous.push_back(std::tuple<size_t, size_t>(previous_weight, current_weight));
		max_value[i] = temp_max_value;
	}

	size_t index_of_maximum = 0;
	double temp_max_value = 0;
	for (size_t i = 0; i < max_value.size(); i++)
	{
		if (max_value[i] > temp_max_value)
		{
			temp_max_value = max_value[i];
			index_of_maximum = i;
		}
	}

	std::vector<size_t> solution;

	while (index_of_maximum != 0)
	{
		solution.push_back(std::get<1>(previous[index_of_maximum]));
		index_of_maximum = std::get<0>(previous[index_of_maximum]);
	}
	return solution;
}