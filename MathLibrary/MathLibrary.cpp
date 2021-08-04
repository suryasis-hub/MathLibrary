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
		if (n >= representableFactors.size())
		{
			throw std::invalid_argument("Combinatorics:factorial - The argument is too large");
		}
		return representableFactors[n];
	}

	inline unsigned long long gcd(unsigned long long a, unsigned long long b)
	{
		if (a % b == 0)
			return b;
		return gcd(b, (a % b));
	}

	unsigned long long combinations(int n, int r)
	{
		if (n - r < r)
			r = n - r;
		unsigned long long int denominatorProduct = 1, numeratorProduct = 1;
		for (int denomCount = r, numCount = n ; denomCount >= 1; denomCount--, numCount--)
		{
			denominatorProduct = denominatorProduct * denomCount;
			numeratorProduct = numeratorProduct * numCount;
			unsigned gcdCommonFactor = gcd(denominatorProduct, numeratorProduct);
			denominatorProduct /= gcdCommonFactor;
			numeratorProduct /= gcdCommonFactor;
		}
		return (numeratorProduct / denominatorProduct);
	}

}
