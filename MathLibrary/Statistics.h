#include <vector>
#include <numeric>
#include <string>
#include <functional>
#include <unordered_map>

namespace Statistics
{
	template <typename T>
	T average(const std::vector<T> &distributionVector)
	{
		if (distributionVector.size() == 0)
		{
			throw std::invalid_argument("Statistics::average - The distribution provided is empty");
		}
		return std::accumulate(distributionVector.begin(), distributionVector.end(), T()) 
			/ (distributionVector.size());
	}

	template <typename T>
	T variance(const std::vector<T> &distributionVector)
	{
		if (distributionVector.size() == 0)
		{
			throw std::invalid_argument("Statistics::expectation - The distribution provided is empty");
		}
		T meanOfSquare = average(distributionVector);
		return (std::accumulate(distributionVector.begin(), distributionVector.end(), T(), [=](T a,T b) { return a + (b - meanOfSquare )*(b - meanOfSquare); })/distributionVector.size());
	}

	template <typename T>
	T standardDeviation(const std::vector<T>& distributionVector)
	{
		return std::sqrt(variance(distributionVector));
	}

	template<typename T>
	T mode(const std::vector<T>& distributionVector)
	{
		if (distributionVector.size() == 0)
		{
			throw std::invalid_argument("Statistics::mode - The distribution provided is empty.");
		}
		std::unordered_map<T, int> frequencyMap;
		std::for_each(distributionVector.begin(), distributionVector.end(), [&](T a) { frequencyMap[a]++;  });
		return std::max_element(frequencyMap.begin(), frequencyMap.end(),[](auto a, auto b) { return (a.second < b.second); })->first;
	}
}
