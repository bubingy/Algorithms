#include <vector>
#include "OrderStatistic.hpp"
#include "print.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	vector<int> arr = { 1,2,3,4,5,6,7,8 };
	PrintArray(arr.data(), arr.size());

	auto median = orderstatistic::GetMedian(arr.data(), arr.size());
	cout << median << endl;
	return 0;
}