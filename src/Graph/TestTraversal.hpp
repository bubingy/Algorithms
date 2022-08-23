#pragma once

#include <list>

namespace graph {
	class TestGraphTraversal
	{
		const size_t graph_matrix[8][8] = { 0 };
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

	};

	void TestDepthFirstSearch()
	{
		bool visit_state[8] = { false };
		std::list<size_t>* output_sequence = new std::list<size_t>();
		DepthFirstSearch(graph_matrix, visit_state, 8, 0, output_sequence);
	}

	void TestBreadthFirstSearch()
	{
		bool visit_state[8] = { false };
		BreadthFirstSearch(graph_matrix, 8, output_sequence);
	}

	
}