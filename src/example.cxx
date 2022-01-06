#include <iostream>
#include <string>
#include "KMP.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	const string pattern = "aaeaa";
	size_t pattern_size = pattern.size();
	KMP* kmp = new KMP(pattern);
	string input = "aaeaaeaae";
	for (size_t i = 0; i < input.size(); i++)
	{
		size_t state = kmp->TransitState(input[i]);
		if (state == pattern_size)
			cout << i - pattern_size + 1 << endl;
	}
}