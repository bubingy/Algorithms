#include <iostream>
#include <string>
#include "FullPermutation.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	FullPermutation* p = new FullPermutation("abcd");
	p->ListAllPermutation();
}