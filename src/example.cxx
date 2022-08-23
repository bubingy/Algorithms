#include <iostream>
#include "Graph/Traversal.hpp"

using namespace std;
using namespace graph;

int main(int argc, char* argv[])
{
	bool visit_state[8] = { false };
	size_t graph_matrix[8][8] = { 0 };

	graph_matrix[0][1] = 1;
	graph_matrix[1][0] = 1;

	graph_matrix[1][3] = 1;
	graph_matrix[3][1] = 1;
	graph_matrix[1][4] = 1;
	graph_matrix[4][1] = 1;

	graph_matrix[7][3] = 1;
	graph_matrix[3][7] = 1;
	graph_matrix[7][4] = 1;
	graph_matrix[4][7] = 1;

	graph_matrix[0][2] = 1;
	graph_matrix[2][0] = 1;
	graph_matrix[5][2] = 1;
	graph_matrix[2][5] = 1;

	graph_matrix[6][2] = 1;
	graph_matrix[2][6] = 1;
	graph_matrix[6][5] = 1;
	graph_matrix[5][6] = 1;

	list<size_t>* output_sequence = new list<size_t>();
	graph::BreadthFirstSearch(graph_matrix, visit_state, 8, output_sequence);

	for (auto i : *output_sequence)
	{
		cout << i << " ";
	}
	cout << endl;
}