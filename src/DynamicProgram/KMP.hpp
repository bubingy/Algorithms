#include <vector>

std::vector<size_t>
MatchPattern(char* txt, size_t txt_length, char* parttern, size_t parttern_length)
{
	std::vector<std::vector<size_t>> dp
	(parttern_length + 1, std::vector<size_t> (txt_length + 1, 0));
	for (size_t j = 1; j <= parttern_length; j++)
	{ 
		for (size_t i = j; i <= txt_length; i++)
		{
			if (dp[j - 1][i - 1] != j - 1) continue;
			if (txt[i - 1] == parttern[j - 1]) dp[j][i] = dp[j - 1][i - 1] + 1;
		}
	}

	std::vector<size_t> result;

	for (size_t i = 1; i <= txt_length; i++)
		if (dp[parttern_length][i] == parttern_length)
			result.push_back(i - parttern_length);
	
	return result;
}