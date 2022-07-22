#include <iostream>
#include "MergeSort.hpp"

using namespace std;
using namespace sort;

int main(int argc, char* argv[])
{
	int a[8] = { 10, 80, 85, 90, 20, 40, 50, 70 };
	int b[8] = { 0 };
	MergeSort(a, b, 0, 7);

	for (size_t i = 0; i < 8; i++)
		cout << b[i] << " ";
	
}