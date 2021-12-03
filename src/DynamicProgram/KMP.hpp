#include <assert.h>
#include <list>

std::list<size_t>
MatchPattern(char* txt, size_t txt_length, char* pattern, size_t pattern_length)
{
	assert(pattern_length > 0);
	assert(txt_length > pattern_length);

	std::list<size_t> dp;
	std::list<size_t> temp_dp;
	
	for (size_t i = 0; i < txt_length; i++)
		if (txt[i] == pattern[0])
			dp.push_back(i);

	if (pattern_length <= 1)
		return dp;
				
	for (size_t i = 1; i < pattern_length; i++)
	{
		for (size_t j : dp)
		{
			if (j + 1 >= txt_length) break;
			if (txt[j + 1] == pattern[i]) temp_dp.push_back(j + 1);
		}
		dp = temp_dp;
		temp_dp.clear();
	}

	std::list<size_t>::iterator iter = dp.begin();
	while (iter != dp.end())
	{
		*iter = *iter + 1 - pattern_length;
		iter++;
	}
	return dp;
}