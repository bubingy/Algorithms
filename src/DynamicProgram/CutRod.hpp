#include <vector>
#include <map>

/// <summary>
/// Cut up the rod, make the value maximum.
/// </summary>
/// <param name="rod_length">length of rod.</param>
/// <param name="length_price_map">length of rod and its price.</param>
/// <returns>list of length of cutted rods.</returns>
std::vector<size_t>
MaximumValueCuttingUp(size_t rod_length,
					  std::map<size_t, double>& length_price_map)
{
	std::vector<double> max_value(rod_length + 1, 0);
	double temp_value = 0;

	std::vector<std::tuple<size_t, size_t>> previous;
	previous.push_back(std::tuple<size_t, size_t>(0, 0));
	
	std::map<size_t, double>::iterator iter;

	for (size_t i = 1; i <= rod_length; i++)
	{
		size_t previous_length = 0;
		size_t current_length = 0;
		for (iter = length_price_map.begin();
			iter != length_price_map.end(); iter++)
		{
			if (i < iter->first)
				continue;

			temp_value = max_value[i - iter->first] + iter->second;
			if (temp_value > max_value[i])
			{
				max_value[i] = temp_value;
				previous_length = i - iter->first;
				current_length = iter->first;
			}
		}
		previous.push_back(std::tuple<size_t, size_t>(previous_length, current_length));
	}

	std::vector<size_t> solution;
	size_t index_of_current = rod_length;

	while (index_of_current != 0)
	{
		solution.push_back(std::get<1>(previous[index_of_current]));
		index_of_current = std::get<0>(previous[index_of_current]);
	}
	return solution;
}