#include <iostream>
#include "Huffman.hpp"
#include "Traversal.hpp"

using namespace std;
using namespace tree;

int main(int argc, char* argv[])
{
	int sequence[8] = { 5, 29, 7, 8, 14, 23, 3, 11 };

	auto root = HuffmanTree(sequence, 8);
	list<int>* out_sequence = new list<int>();
	InOrder(root, out_sequence);
	for (auto i : *out_sequence)
	{
		cout << i << " ";
	}
	cout << endl;
}