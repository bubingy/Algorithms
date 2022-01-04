#pragma once

#include <list>
#include <string> 
#include <iostream>


class FullPermutation
{
public:
	FullPermutation(const std::string origin_string);
	~FullPermutation();
	void ListAllPermutation();

private:
	void _ListAllPermutation(std::string input_string,
							 std::string current_string = "");
	std::list<std::string> all_permutation;
	std::string _origin_string;
	size_t _origin_string_size;
};

FullPermutation::FullPermutation(const std::string origin_string):
	_origin_string(origin_string), _origin_string_size(origin_string.size()) 
{ _ListAllPermutation(_origin_string, ""); };

FullPermutation::~FullPermutation() {};

void
FullPermutation::_ListAllPermutation(std::string input_string,
	std::string current_string)
{
	std::string _input_string, _current_string;
	size_t input_string_size = input_string.size();
	for (size_t i = 0; i < input_string_size; i++)
	{
		_input_string = input_string.substr(0, i) + input_string.substr(i + 1, input_string.size() - i - 1);
		_current_string = current_string + input_string[i];
		if (_current_string.size() == _origin_string_size)
		{
			all_permutation.push_back(_current_string);
			return;
		}
		_ListAllPermutation(_input_string, _current_string);
	}
};

void
FullPermutation::ListAllPermutation()
{
	for (auto value : all_permutation) std::cout << value << std::endl;
};