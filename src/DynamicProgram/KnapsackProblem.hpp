#pragma once

#include <vector>
#include <map>

/// <summary>
/// Given weights and values of n items, 
/// put these items in a knapsack of capacity W to get the maximum 
/// total value in the knapsack. In other words, 
/// given two integer arrays val[0..n-1] and wt[0..n-1] which 
/// represent values and weights associated with n items respectively. 
/// Also given an integer W which represents knapsack capacity, 
/// find out the maximum value subset of val[] such that 
/// sum of the weights of this subset is smaller than or equal to W. 
/// You cannot break an item, either pick the complete item 
/// or don’t pick it (0-1 property).
/// </summary>
/// <param name="capacity"></param>
/// <param name="weight_value_map"></param>
/// <returns></returns>
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

/// <summary>
/// A variation of 0-1 Knapsack Problem.
/// each item can be put to pack duplicately.
/// </summary>
/// <param name="capacity"></param>
/// <param name="weight_value_map"></param>
/// <returns></returns>
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
		size_t previous_weight = 0;
		size_t current_weight = 0;
		for (iter = weight_value_map.begin(); 
			iter != weight_value_map.end(); iter++)
		{
			if (i >= iter->first)
			{
				if (max_value[i - iter->first] + iter->second > max_value[i])
				{
					max_value[i] = max_value[i - iter->first] + iter->second;
					previous_weight = i - iter->first;
					current_weight = iter->first;
				}
			}
		}
		previous.push_back(std::tuple<size_t, size_t>(previous_weight, current_weight));
	}

	std::vector<size_t> solution;
	size_t index_of_current = capacity;

	while (index_of_current != 0)
	{
		solution.push_back(std::get<1>(previous[index_of_current]));
		index_of_current = std::get<0>(previous[index_of_current]);
	}
	return solution;
}