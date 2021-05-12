#include <vector>
#include "HeapSort.hpp"
#include "QuickSort.hpp"
#include "print.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	vector<int> arr = { 4,21,42,78,7,0,12,3,55 };
	PrintArray(arr.data(), arr.size());

	auto kth = heapsort::GetKthSmallest(arr.data(), 4, arr.size());
	PrintArray(arr.data(), arr.size());
	cout << kth << endl;
	return 0;
}