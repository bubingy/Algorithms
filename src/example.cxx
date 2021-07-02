#include <vector>
#include "LongestIncreasingSubsequence.hpp"
#include "print.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	vector<int> arr = { 1,2,1,4,5,3,0,8 };
	PrintArray(arr.data(), arr.size());

	auto result = LongestIncreasingSubsequence(arr.data(), arr.size());
	PrintArray(result.data(), result.size());
	return 0;
}