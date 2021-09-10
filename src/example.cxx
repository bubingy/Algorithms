#include <iostream>
#include "EstimateEllipseCircumference.hpp"
#include "EstimatePI.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	size_t N = 10000000;
	cout << EstimateEllipseCircumference(22, 12, N) << endl;
}