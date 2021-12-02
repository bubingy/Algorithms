#include <vector>

std::vector<size_t>
MatchPattern(char* txt, size_t txt_length, char* parttern, size_t parttern_length)
{
	std::vector<size_t> dp(txt_length + 1, 0);
	size_t i = 0, j = 0, k = 0, temp = 0;
	for (j = 0; j < parttern_length - 1; j++)
	{ 
		k = temp;
		for (i = txt_length; i > k; i--)
		{
			if (dp[i - 1] == j && txt[i - 1] == parttern[j]) 
			{
				dp[i] = dp[i - 1] + 1;
				temp = i;
			}
		}
	}
				
	std::vector<size_t> result;

	for (i = txt_length; i >= k - 1; i--)
		if (dp[i - 1] == j && txt[i - 1] == parttern[j])
			result.push_back(i - parttern_length);

	return result;
}