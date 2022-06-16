#include <iostream>
#include "SwapSort.hpp"

using namespace std;
using namespace sort;

int main(int argc, char* argv[])
{
	int a[7] = { 10, 80, 30, 90, 40, 50, 70 };
	BubbleSort(a, 7);

	for (size_t i = 0; i < 7; i++)
		cout << a[i] << " ";
	
}