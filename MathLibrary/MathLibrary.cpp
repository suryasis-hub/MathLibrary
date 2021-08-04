// MathLibrary.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include <iostream>

// TODO: This is an example of a library function
namespace Combinatorics
{
	unsigned long long factorial(unsigned int n) 
	{
		unsigned long long fact = 1;
		for (int i = 1; i <= n; i++)
		{
			if (fact > ULLONG_MAX / n) 
			{
				throw std::invalid_argument("The argument is too large");
			}
			fact = fact * i;
		}
		return fact;
	}
}
