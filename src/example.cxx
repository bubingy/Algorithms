#include <iostream>
#include <string>
#include "KMP.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	string txt = "aaafdeaaaaafdee";
	string pattern = "aafde";
	auto index_list = MatchPattern(txt.data(), txt.size(), pattern.data(), pattern.size());
	for (auto index : index_list)
	{
		for (size_t i = 0; i < txt.size(); i++)
		{
			if (i == index) cout << "{";
			cout << txt[i];
			if (i + 1 == index + pattern.size()) cout << "}";
		}
		cout << endl;
	}
	
}