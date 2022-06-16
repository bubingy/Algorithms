#pragma once

namespace sort {

	template <typename T> inline void
		Swap(T& a, T& b)
	{
		T c = a;
		a = b;
		b = c;
	}

	template <typename T> inline size_t
		BinarySearch(T* sequence , size_t sequence_length, T key)
	{
		size_t i;
		for (i = 0; i < sequence_length; i++)
			if (sequence[i] > key) break;
		return i;
	}

	template <typename T> void
		StraightInsertionSort(T* sequence, size_t sequence_length)
	{
		if (sequence_length <= 1) return;
		
		for (size_t i = 1; i < sequence_length; i++)
			for (size_t j = i; j > 0; j--)
				if (sequence[j] < sequence[j-1])
					Swap(sequence[j], sequence[j - 1]);
	}

	template <typename T> void
		BinaryInsertionSort(T* sequence, size_t sequence_length)
	{
		if (sequence_length <= 1) return;
		for (size_t i = 1; i < sequence_length; i++)
		{
			size_t pos = BinarySearch(sequence, i, sequence[i]);
			for (size_t j = i; j > pos; j--)
				Swap(sequence[j], sequence[j - 1]);
		}
	}

	template <typename T> inline void
		ShellInsert(T* sequence, size_t sequence_length, size_t dt)
	{
		if (sequence_length < dt) return;
		for (size_t i = dt; i < sequence_length; i += dt)
			for (size_t j = i; j > 0; j -= dt)
				if (sequence[j] < sequence[j - dt])
					Swap(sequence[j], sequence[j - dt]);
	}

	template <typename T> void
		ShellSort(T* sequence, size_t sequence_length, size_t* dt_sequence, sizet_t dt_sequence_length)
	{
		for (size_t i = 0; i < dt_sequence_length; i++)
			ShellInsert(sequence, sequence_length, dt_sequence[i]);
	}
}
