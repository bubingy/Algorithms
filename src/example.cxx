#include <iostream>
#include "EggDroppingPuzzle.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	auto trials = EggDropping(2, 10);
	cout << trials << endl;

}