#include <iostream>
#include "EstimateEllipseCircumference.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	size_t N = 1000000;
	cout << EstimateEllipseCircumference(4, 3, N) << endl;
}