#include <vector>
#include "OrderStatistic.hpp"
#include "print.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	vector<int> arr = { 1,2,3,4,5,6,7,8,9 };
	PrintArray(arr.data(), arr.size());

	auto kth = orderstatistic::GetKthSmallest(arr.data(), 9, 0, arr.size() - 1);
	cout << kth << endl;
	return 0;
}