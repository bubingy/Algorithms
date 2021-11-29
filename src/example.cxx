#include <iostream>
#include "KMP.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	char* txt = "ttafdijmemageaprgmaddf";
	size_t txt_length = 22;
	char* parttern = "addf";
	size_t pattern_length = 4;
	auto index = MatchPattern(txt, txt_length, parttern, pattern_length);
	for (size_t i = 0; i < txt_length; i++)
	{
		if (i == index) cout << "{";
		cout << txt[i];
		if (i + 1 == index + pattern_length) cout << "}";
	}
}