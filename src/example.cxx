#include <iostream>
#include "EstimatePI.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	size_t N = 10000;
	cout << EstimatePI(N) << endl;
}