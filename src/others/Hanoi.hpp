#include <assert.h>
#include <iostream>

void Hanoi(size_t num_plate, char* pillar_a, char* pillar_b, char* pillar_c)
{
	assert(num_plate >= 1);
	if (num_plate == 1)
	{ 
		std::cout 
			<< "move " << num_plate 
			<< " from " << pillar_a 
			<< " to " << pillar_c 
			<< std::endl;
		return;
	}
	Hanoi(num_plate - 1, pillar_a, pillar_c, pillar_b);
	std::cout
		<< "move " << num_plate
		<< " from " << pillar_a
		<< " to " << pillar_c
		<< std::endl;
	Hanoi(num_plate - 1, pillar_b, pillar_a, pillar_c);
}