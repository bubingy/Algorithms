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
	std::vector<double> max_value;
	max_value.push_back(0);
	double temp_max_value = 0;
	double temp_value = 0;

	std::vector<std::vector<size_t>> cutted_rods;
	std::vector<size_t> temp_cutted_rods;
	cutted_rods.push_back({0});
	
	std::map<size_t, double>::iterator iter;

	for (size_t i = 1; i <= rod_length; i++)
	{
		temp_max_value = 0;
		iter = length_price_map.begin();
		for (; iter != length_price_map.end(); iter++)
		{
			if (i < iter->first)
				continue;

			temp_value = max_value[i - iter->first] + iter->second;
			if (temp_value > temp_max_value)
			{
				temp_max_value = temp_value;
				temp_cutted_rods.assign(
					cutted_rods[i - iter->first].begin(),
					cutted_rods[i - iter->first].end()
				);
				temp_cutted_rods.push_back(iter->first);
			}
		}
		cutted_rods.push_back(temp_cutted_rods);
		max_value.push_back(temp_max_value);
	}

	auto result = cutted_rods[cutted_rods.size() - 1];
	result.erase(result.begin());
	return result;
}