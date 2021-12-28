#include <iostream>
#include <string>
#include "Fibonacci.h"

using namespace std;

int main(int argc, char* argv[])
{
	Fibonacci* f = new Fibonacci();
	for (size_t i = 1; i <= 10; i++)
	{
		cout << f->get(i) << endl;
	}
	
}