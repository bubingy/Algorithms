#include <iostream>
#include "MaximumSumSubsequence.hpp"
#include "print.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	vector<int> array = { -2,1,-3,4,-1,2,1,-5,4 };

	auto result = MaximumSumSubsequence<int>(array.data(), array.size());
	for (auto i:result)
	{
		cout << i << " ";
	}
	cout << endl;
}