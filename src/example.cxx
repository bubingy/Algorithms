#include <iostream>
#include "CoinChange.hpp"
#include "print.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	std::vector<size_t> face_values = {1,5,10,20,50};
	auto solution = CoinChange(face_values, 39);
	PrintArray(solution.data(), solution.size());
}