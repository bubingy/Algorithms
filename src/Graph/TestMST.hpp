#pragma once

#include <list>
#include <tuple>

namespace graph {
	class TestGraphMST
	{
		const size_t graph_matrix[6][6] = {
			{0,6,1,5,0,0},
			{6,0,5,0,3,0},
			{1,5,0,5,6,4},
			{5,0,5,0,0,2},
			{0,3,6,0,0,6},
			{0,0,4,2,6,0} };

		void TestPrim()
		{
			std::list<std::tuple<size_t, size_t>>* output_sequence = new std::list<std::tuple<size_t, size_t>>();
			Prim(graph_matrix, 0, 6, output_sequence);
		}

		void TestKruskal()
		{
			std::list<std::tuple<size_t, size_t>>* output_sequence = new std::list<std::tuple<size_t, size_t>>();
			Kruskal(graph_matrix, 6, output_sequence);
		}
	}
}