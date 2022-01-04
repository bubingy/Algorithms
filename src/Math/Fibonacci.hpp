#pragma once

class Fibonacci
{
public:
	Fibonacci();
	~Fibonacci();
	size_t get(size_t n);

private:
	size_t N, previous, current;
};

Fibonacci::Fibonacci() { N = 2, previous = 1, current = 1; }

Fibonacci::~Fibonacci() {}

size_t
Fibonacci::get(size_t n)
{
	if (n == 1 || n == 2) return 1;
	size_t _n = n;
	size_t tmp;
	if (_n >= N)
		while (_n > N)
		{
			tmp = previous + current;
			previous = current;
			current = tmp;
			_n--;
		}
	if (_n < N)
		while (_n <N)
		{
			tmp = current - previous;
			current = previous;
			previous = tmp;
		}

	N = n;
	return current;
}