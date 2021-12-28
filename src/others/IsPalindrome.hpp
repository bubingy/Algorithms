#pragma once

#include <vector>
#include <assert.h>

/// <summary>
/// verify if the given interger is a palindrome. 
/// </summary>
/// <param name="integer">A postive integer.</param>
/// <returns>return 1 if the given interger is a palindrome, otherwise return 0.</returns>
bool IsPalindrome(long long integer)
{
	assert(integer >= 0);

	std::vector<char> digit_sequence;
	long long divisor = 10;
	while (integer / divisor != 0)
	{
		digit_sequence.push_back(integer % divisor);
		integer = integer / divisor;
	}
	digit_sequence.push_back(integer);

	size_t i = 0, j = digit_sequence.size() - 1;

	while (i <= j)
	{
		if (digit_sequence[i] != digit_sequence[j]) return false;
		i++, j--;
	}
	return true;
}