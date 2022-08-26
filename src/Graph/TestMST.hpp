#pragma once

#include <list>
#include <tuple>

namespace graph {
	class TestGraphMST
	{
		const size_t graph_matrix[6][6] = {
			{INFINITY,6,1,5,INFINITY,INFINITY},
			{6,INFINITY,5,INFINITY,3,INFINITY},
			{1,5,INFINITY,5,6,4},
			{5,INFINITY,5,INFINITY,INFINITY,2},
			{INFINITY,3,6,INFINITY,INFINITY,6},
			{INFINITY,INFINITY,4,2,6,INFINITY} };

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