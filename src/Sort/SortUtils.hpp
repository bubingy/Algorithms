#pragma once

#include <assert.h>

namespace sortutils {
	/// <summary>
	/// Swap value of two varables.
	/// </summary>
	/// <typeparam name="t"></typeparam>
	/// <param name="a">varable a</param>
	/// <param name="b">varable b</param>
	template<typename t> inline void
	Swap(t* a, t* b)
	{
		t temp = *a;
		*a = *b;
		*b = temp;
	};
}