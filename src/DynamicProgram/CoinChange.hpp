#pragma once

#include <vector>

/// <summary>
/// we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins,
/// make change for N cents, make number of coins minimum.
/// </summary>
/// <param name="face_values">valued coins.</param>
/// <param name="value">N cents to make change.</param>
/// <returns>solution.</returns>
std::vector<size_t>
CoinChange(std::vector<size_t> face_values, size_t value)
{
	std::vector<size_t> given_change( 
		value + 1, 
		std::numeric_limits<size_t>::max() 
	);
	given_change[0] = 0;

	std::vector<std::vector<size_t>> solutions;
	std::vector<size_t> null_solution{};
	solutions.push_back(null_solution);
	size_t last_level = 0;

	for (size_t i = 1; i <= value; i++)
	{
		for (size_t face_value : face_values)
		{
			if (i < face_value) continue;

			if (given_change[i - face_value] + 1 < given_change[i])
			{
				given_change[i] = given_change[i - face_value] + 1;
				last_level = i - face_value;
			}
		}
		std::vector<size_t> solution(solutions[last_level]);
		solution.push_back(i - last_level);
		solutions.push_back(solution);
	}

	return solutions[value];
}