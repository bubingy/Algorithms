#pragma once

#include <string>
#include <map>
#include <set>

class KMP
{
public:
	KMP(std::string pattern);
	~KMP();
	size_t TransitState(char input_char);
	void Reset();

private:
	std::map<size_t, std::map<char, size_t>> transition_map;
	size_t pattern_size;
	std::set<char> input_box;
	size_t state;
};

/// <summary>
/// Generate state transition map.
/// </summary>
/// <param name="pattern">pattern string.</param>
KMP::KMP(std::string pattern):
	pattern_size(pattern.size()),
	input_box(pattern.begin(), pattern.end()),
	state(0)
{
	for (size_t i = 0; i < pattern_size; i++)
	{
		std::map<char, size_t> transition;
		for (char input_char : input_box)
		{
			long long _i = i;
			if (input_char != pattern[i])
			{
				while (_i >= 0)
				{
					if (pattern[_i] != input_char)
					{
						_i--;
						continue;
					}
					if (pattern.substr(0, _i + 1) == pattern.substr(i - _i, _i) + input_char)
						break;
					_i--;
				}
			}
			transition[input_char] = _i + 1;
		}
		transition_map[i] = transition;
	}

	std::map<char, size_t> transition;
	for (char input_char : input_box)
	{
		long long _i = pattern_size - 1;
		while (_i >= 0)
		{
			if (pattern[_i] != input_char)
			{
				_i--;
				continue;
			}
			if (pattern.substr(0, _i + 1) == pattern.substr(pattern_size - _i, _i) + input_char)
				break;
			_i--;
		}
		transition[input_char] = _i + 1;
	}
	transition_map[pattern_size] = transition;
};

KMP::~KMP() {};

size_t
KMP::TransitState(char input_char)
{
	if (input_box.find(input_char) == input_box.end())
		state = 0;
	else
		state = transition_map[state][input_char];

	return state;
};

void
KMP::Reset() { state = 0; };