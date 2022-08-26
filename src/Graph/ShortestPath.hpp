#pragma once

#include <math.h>

namespace graph {
	template <typename T> void
		Floyd(T* graph_matrix,
			size_t node_number,
			T* cost_matrix)
	{
		// initialize cost matrix
		for (size_t i = 0; i < node_number; i++)
			for (size_t j = 0; j < node_number; j++)
				cost_matrix[i][j] = graph_matrix[i][j];

		// update cost matrix
		for (size_t i = 0; i < node_number; i++)
			for (size_t j = 0; j < node_number; j++)
				for (size_t k = 0; k < node_number; k++)
					if (cost_matrix[i][k] + cost_matrix[j][k] < cost_matrix[i][j]
						&& cost_matrix[i][k] != INFINITY && cost_matrix[j][k] != INFINITY)
						cost_matrix[i][j] = cost_matrix[i][k] + cost_matrix[j][k]
				
	}
}