#include <iostream>
#include "KnapsackProblem.hpp"
#include "print.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	map<size_t, double> length_price_map;
	length_price_map[1] = 1;
	length_price_map[2] = 5;
	length_price_map[3] = 8;
	length_price_map[4] = 9;
	length_price_map[5] = 10;
	length_price_map[6] = 17;
	length_price_map[7] = 17;
	length_price_map[8] = 20;

	auto solution = MaximumValueKnapsack_Unbounded(10, length_price_map);
	PrintArray(solution.data(), solution.size());
}