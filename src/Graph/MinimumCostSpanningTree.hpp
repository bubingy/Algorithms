#pragma once

#include <list>
#include <tuple>

namespace graph {
	template <typename T> void
		Prim(T* graph_matrix,
			size_t root_node_index,
			size_t node_number,
			std::list<std::tuple<size_t, size_t>>* output_sequence)
	{
		bool* visit_state = new bool[node_number];
		for (size_t i = 0; i < node_number; i++) visit_state[i] = false;

		visit_state[root_node_index] = true;
		size_t min_cost, min_cost_i, min_cost_j;
		bool finished;

		while (true)
		{
			finished = true;
			min_cost = LLONG_MAX;
			for (size_t i = 0; i < node_number; i++)
			{
				if (visit_state[i] == false) continue; // choose nodes from U
				for (size_t j = 0; j < node_number; j++)
				{
					if (visit_state[j] == true) continue; // choose nodes from V-U

					if (graph_matrix[i][j] == 0) continue; // ignore unreachable nodes
					if (i == j) continue; // ignore the itself

					if (graph_matrix[i][j] < min_cost)
					{
						min_cost = graph_matrix[i][j];
						min_cost_i = i;
						min_cost_j = j;
					}
				}
			}

			output_sequence->push_back(
				std::make_tuple(min_cost_i, min_cost_j));
			visit_state[min_cost_j] = true;

			for (size_t i = 0; i < node_number; i++) finished = finished && visit_state[i];

			if (finished) break;
		}

		delete[] visit_state;
	}

	template <typename T> void
		Kruskal(T* graph_matrix,
			size_t node_number,
			std::list<std::tuple<size_t, size_t>>* output_sequence)
	{
		size_t* connected_component = new size_t[node_number];
		for (size_t i = 0; i < node_number; i++) connected_component[i] = i;

		size_t min_cost, min_cost_i, min_cost_j;
		bool finished;

		while (true)
		{
			finished = true;
			min_cost = LLONG_MAX;

			for (size_t i = 0; i < node_number; i++)
			{
				for (size_t j = 0; j < node_number; j++)
				{
					if (connected_component[i] == connected_component[j]) continue; // ignore node in same connected component
					if (graph_matrix[i][j] == 0) continue; // ignore unreachable nodes
					if (i == j) continue; // ignore the itself

					if (graph_matrix[i][j] < min_cost)
					{
						min_cost = graph_matrix[i][j];
						min_cost_i = i;
						min_cost_j = j;
					}
				}
			}

			output_sequence->push_back(
				std::make_tuple(min_cost_i, min_cost_j));

			size_t flag = connected_component[min_cost_j];
			for (size_t k = 0; k < node_number; k++)
			{ 
				if (connected_component[k] == flag)
					connected_component[k] = connected_component[min_cost_i];

				if (connected_component[k] != connected_component[0]) finished = false;
			}
				
			if (finished) break;
		}

		delete[] connected_component;
	}
}