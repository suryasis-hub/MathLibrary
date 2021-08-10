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
		return pow(variance(distributionVector), 0.5);
	}

	template<typename T>
	T mode(const std::vector<T>& distributionVector)
	{
		std::unordered_map<T, int> frequencyMap;
		std::for_each(distributionVector.begin(), distributionVector.end(), [&](T a) { frequencyMap[a]++;  });
		int maxCount = 0;
		std::for_each(frequencyMap.begin(), frequencyMap.end(), [&](auto a) { maxCount = std::max(maxCount, a.second); });
		T answer;
		std::for_each(frequencyMap.begin(), frequencyMap.end(), [&](auto a) { if (maxCount == a.second) { answer = a.first; } });
		return answer;
	}
}
