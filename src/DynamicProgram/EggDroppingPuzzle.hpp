#include <vector>

/// <summary>
/// solve egg dropping puzzle.
/// </summary>
/// <param name="num_of_eggs">number of eggs.</param>
/// <param name="num_of_floors">number of floors</param>
/// <returns>minimum trials with given eggs.</returns>
size_t
EggDropping(size_t num_of_eggs, size_t num_of_floors)
{
    std::vector<std::vector<size_t>> trials(num_of_eggs + 1,
                                            std::vector<size_t>(num_of_floors + 1));
	
	size_t res;
	size_t i, j, x;
	// one trial for one floor and 0 trials for 0 floors
	for (i = 0; i <= num_of_eggs; i++)
	{
		trials[i][0] = 0;
		trials[i][1] = 1;
	}
	// always need j trials for one egg and j floors.
	for (j = 0; j <= num_of_floors; j++) trials[1][j] = j;

	for (i = 2; i <= num_of_eggs; i++)
	{
		for (j = 2; j <= num_of_floors; j++)
		{
			trials[i][j] = SIZE_MAX;
			for (x = 1; x <= j; x++)
			{
				res = 1 + std::max(trials[i - 1][x - 1],
								   trials[i][j - x]);
				if (res < trials[i][j]) trials[i][j] = res;
			}
		}
	}

	return trials[num_of_eggs][num_of_floors];
};