#include <vector>
#include "HeapSort.hpp"
#include "QuickSort.hpp"
#include "print.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	vector<int> arr = { 4,21,42,78,7,0,12,3,55 };
	PrintArray(arr.data(), arr.size());

	//HeapSort(arr.data(), arr.size(), false);
	QuickSort(arr.data(), 0, arr.size() - 1, false);
	PrintArray(arr.data(), arr.size());

	arr = { 4,21,42,78,7,0,12,3,55 };
	//HeapSort(arr.data(), arr.size(), true);
	QuickSort(arr.data(), 0, arr.size() - 1, true);
	PrintArray(arr.data(), arr.size());
	
	return 0;
}