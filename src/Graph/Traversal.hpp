#pragma once

#include <list>

namespace graph {
	template <typename T> void
	    DepthFirstSearch(T* graph_matrix,
						bool* visit_state, 
						size_t node_number, 
						size_t current_node_index, 
						std::list<size_t>* output_sequence)
	{
		if (visit_state[current_node_index] == true) return;
		output_sequence->push_back(current_node_index);
		visit_state[current_node_index] = true;

		for (size_t i = 0; i < node_number; i++)
		{
			if (graph_matrix[current_node_index][i] == 0) continue; // ignore unreachable nodes
			if (visit_state[i] == true) continue; // ignore visited nodes
			if (i == current_node_index) continue; // ignore the itself
			
			DepthFirstSearch(graph_matrix, visit_state, node_number, i, output_sequence);
		}
	}

	template <typename T> void
		BreadthFirstSearch(T* graph_matrix,
							size_t node_number,
							std::list<size_t>* output_sequence)
	{
		bool* visit_state = new bool[node_number];
		if (node_number >= 1)
		{
			output_sequence->push_back(0);
			visit_state[0] = true;
		}
		
		size_t current_node_index;
		for (std::list<size_t>::iterator iter = output_sequence->begin();
			iter != output_sequence->end(); iter++)
		{
			current_node_index = *iter;
			for (size_t i = 0; i < node_number; i++) 
			{
				if (graph_matrix[current_node_index][i] == 0) continue; // ignore unreachable nodes
				if (visit_state[i] == true) continue; // ignore visited nodes
				if (i == current_node_index) continue; // ignore the itself
				output_sequence->push_back(i);
				visit_state[i] = true;
			}
		}

		delete[] visit_state;
	}
}