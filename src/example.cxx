#include <iostream>
#include <tuple>
#include "Graph/MinimumCostSpanningTree.hpp"

using namespace std;
using namespace graph;

int main(int argc, char* argv[])
{
	size_t graph_matrix[6][6] = { 
		{0,6,1,5,0,0},
		{6,0,5,0,3,0},
		{1,5,0,5,6,4},
		{5,0,5,0,0,2},
		{0,3,6,0,0,6},
		{0,0,4,2,6,0}};

	list<tuple<size_t, size_t>>* output_sequence = new list<tuple<size_t, size_t>>();
	graph::Kruskal(graph_matrix, 6, output_sequence);

	for (auto i : *output_sequence)
	{
		cout << std::get<0>(i) << " " << std::get<1>(i) << endl;
	}
}