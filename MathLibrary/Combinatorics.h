// MathLibrary.cpp : Defines the functions for the static library.
//
#include "pch.h"
#include "framework.h"
#include <vector>
#include <iostream>
#include <limits>
#include <cstddef>

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
		return representableFactors.at(n);
	}

	inline long long gcd(long long a, long long b)
	{
		if (a % b == 0)
		{
			return b;
		}
		return gcd(b, (a % b));
	}

	long long combinations(int n, int r)
	{
		if (n < 0 || r < 0)
		{
			throw std::invalid_argument("Combinatorics::combinations - N and R cannot be less than 0");
		}
		if (n < r)
		{
			throw std::invalid_argument("Combinatorics::combinations - The value of r cannot be greater than n");
		}
		if (n - r < r)
		{
			r = n - r;
		}
		long long int denominatorProduct = 1;
		long long int numeratorProduct = 1;
		for (long long int denomCount = r, numCount = n ; denomCount >= 1; denomCount--, numCount--)
		{
			//TODO : Convert to limits
			if((LLONG_MAX / n) < numeratorProduct || (LLONG_MAX / n) < denominatorProduct)
			{
				throw std::invalid_argument("Combinatorics::combinations - The calculated value is too large, aborting.");
			}
			denominatorProduct *= denomCount;
			numeratorProduct *=  numCount;
			const long long gcdCommonFactor = gcd(denominatorProduct, numeratorProduct);
			denominatorProduct /= gcdCommonFactor;
			numeratorProduct /= gcdCommonFactor;
		}
		return (numeratorProduct / denominatorProduct);
	}

	long long permutations(int n, int r)
	{
		if (n < 0 || r < 0)
		{
			throw std::invalid_argument("Combinatorics::permutations - N and R cannot be less than 0");
		}
		if (n < r)
		{
			throw std::invalid_argument("Combinatorics::permutations - The value of r cannot be greater than n");
		}
		long long permutations = 1;
		for (int numeratorCount = n; numeratorCount >= (n - r + 1); numeratorCount--)
		{
			//TODO: Convert to limits
			if ((LLONG_MAX / n) < permutations)
			{
				throw std::invalid_argument("Combinatorics::permutations - The calculated value is too large, aborting");
			}
			permutations *= numeratorCount;
		}
		return permutations;
	}
}
