#include <iostream>
#include "KMP.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	char* txt = "aaaaaaaaaafdee";
	size_t txt_length = 14;
	char* parttern = "aafde";
	size_t pattern_length = 5;
	auto index_list = MatchPattern(txt, txt_length, parttern, pattern_length);
	for (auto index : index_list)
	{
		for (size_t i = 0; i < txt_length; i++)
		{
			if (i == index) cout << "{";
			cout << txt[i];
			if (i + 1 == index + pattern_length) cout << "}";
		}
		cout << endl;
	}
	
}