// MathLibrary.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include <vector>
#include <iostream>


// TODO: This is an example of a library function
namespace Combinatorics
{
	const std::vector<unsigned long long> representableFactors = {1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,
		479001600,6227020800,87178291200,1307674368000,20922789888000,355687428096000,6402373705728000,121645100408832000,2432902008176640000};

	unsigned long long factorial(unsigned int n) 
	{
		if (representableFactors.size() >= (n-1))
		{
			return representableFactors[n];
		}
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
