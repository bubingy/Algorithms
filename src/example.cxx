#include <vector>
#include "MergeSort.hpp"
#include "print.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	vector<int> array = { -2,1,-3,4,8,2,11,-5,14 };

	mergesort::Sort(array.data(), array.size());
	PrintArray(array.data(), array.size());
}