#include <iostream>
#include <string>
#include <iomanip>
#include "EstimatePI.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	double pi = EstimatePI();
	cout << setprecision(32) << "PI: " << pi << endl;
}