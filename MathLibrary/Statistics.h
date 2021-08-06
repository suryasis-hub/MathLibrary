#include <vector>
#include <numeric>
#include <string>
#include <functional>

namespace Statistics
{
	template <typename T>
	T average(std::vector<T> distributionVector)
	{
		if (distributionVector.size() == 0)
		{
			throw std::invalid_argument("Statistics::average - The distribution provided is empty");
		}
		return std::accumulate(distributionVector.begin(), distributionVector.end(), T()) 
			/ (distributionVector.size());
	}

	template <typename T>
	T variance(std::vector<T> distributionVector)
	{
		if (distributionVector.size() == 0)
		{
			throw std::invalid_argument("Statistics::expectation - The distribution provided is empty");
		}
		T sumOfSquare = std::accumulate(distributionVector.begin(), distributionVector.end(), T(), [](T a,T b) { return a + b*b; });
		T meanOfSquare = sumOfSquare / distributionVector.size();
		T squareOfMean = (average(distributionVector)) * (average(distributionVector));
		return (meanOfSquare - squareOfMean);
	}
}
