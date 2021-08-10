#include "pch.h"
#include <vector>
#include "../MathLibrary/Combinatorics.h"
#include "../MathLibrary/Statistics.h"

void compareDoubles(double a, double b)
{
    const double THRESHOLD = 0.01;
    ASSERT_TRUE(abs(a - b) < THRESHOLD);
}

TEST(Combinatorial_Factorial, small_ints)
{
    EXPECT_EQ(Combinatorics::factorial(0), 1);
    EXPECT_EQ(Combinatorics::factorial(1), 1);
    EXPECT_EQ(Combinatorics::factorial(5), 120);
    EXPECT_EQ(Combinatorics::factorial(20), 2432902008176640000);
}

TEST(Combinatorial_Factorial, too_big)
{
    EXPECT_THROW(Combinatorics::factorial(500), std::invalid_argument);
}

TEST(Combinatorial_Combinations, small_ints)
{
    EXPECT_EQ(Combinatorics::combinations(5,5), 1);
    EXPECT_EQ(Combinatorics::combinations(5, 0), 1);
    EXPECT_EQ(Combinatorics::combinations(5, 1), 5);
    EXPECT_EQ(Combinatorics::combinations(20,10),184756);
    EXPECT_EQ(Combinatorics::combinations(40, 35),658008);
}

TEST(Combinatorial_Combinations, negative_n)
{
    EXPECT_THROW(Combinatorics::combinations(-5, 5), std::invalid_argument);
}

TEST(Combinatorial_Combinations, r_greater_than_n)
{
    EXPECT_THROW(Combinatorics::combinations(4, 5), std::invalid_argument);
}

TEST(Combinatorial_Combinations, overflow)
{
    EXPECT_THROW(Combinatorics::combinations(100, 50), std::invalid_argument);
}

TEST(Combinatorial_Permutations, small_ints)
{
    EXPECT_EQ(Combinatorics::permutations(5, 5), 120);
    EXPECT_EQ(Combinatorics::permutations(5, 0), 1);
    EXPECT_EQ(Combinatorics::permutations(5, 2), 20);
    EXPECT_EQ(Combinatorics::permutations(10, 2), 90);
    EXPECT_EQ(Combinatorics::permutations(40, 3), 59280);
    EXPECT_EQ(Combinatorics::permutations(40, 7), 93963542400);
    EXPECT_EQ(Combinatorics::permutations(50, 4), 5527200);
}

TEST(Combinatorial_Permutations, r_negative)
{
    EXPECT_THROW(Combinatorics::permutations(5, -5), std::invalid_argument);
}

TEST(Combinatorial_Permutations, n_negative)
{
    EXPECT_THROW(Combinatorics::permutations(-5, 5), std::invalid_argument);
}

TEST(Combinatorial_Permutations,r_greater)
{
    EXPECT_THROW(Combinatorics::permutations(5, 6), std::invalid_argument);
}

TEST(Combinatorial_Permutations,overflow)
{
    EXPECT_THROW(Combinatorics::permutations(50,46), std::invalid_argument);
}

TEST(Statistics_mean, small_distributions)
{
    std::vector<int> testVector = { -2,-1,0,1,2 };
    EXPECT_EQ(Statistics::average(testVector), 0);
    std::vector<double> testVectorDouble = {5,5,6,6};
    compareDoubles(Statistics::average(testVectorDouble), 5.5);
}

TEST(Statistics_mean, empty_distribution)
{
    std::vector<int> testVector;
    EXPECT_THROW(Statistics::average(testVector), std::invalid_argument);
}

TEST(Statistics_variance, small_distribution)
{
    std::vector<double> testVector = { 0,0 };
    compareDoubles(Statistics::variance(testVector), 0);
    std::vector<double> testVector2 = {1,2,3,4};
    compareDoubles(Statistics::variance(testVector2), 1.25);
    std::vector<double> testVectorRandom = { 1,2,3,4,6,8,9,34,45,78,89 };
    compareDoubles(Statistics::variance(testVectorRandom), 938.2314);
}

TEST(Statistics_standarddev, small_distribution)
{
    std::vector<double> testVector = { 0,0 };
    compareDoubles(Statistics::standardDeviation(testVector), 0);
    std::vector<double> testVector2 = { 1,2,3,4 };
    compareDoubles(Statistics::standardDeviation(testVector2), 1.11803);
    std::vector<double> testVectorRandom = { 1,2,3,4,6,8,9,34,45,78,89 };
    compareDoubles(Statistics::standardDeviation(testVectorRandom), 30.6305);
}

TEST(Statistics_mode, small_distribution)
{
    std::vector<int> testVector = { 32,32, 45, 12,32};
    EXPECT_EQ(Statistics::mode(testVector), 32);
    std::vector<int> testVector1 = { 32,32,32 };
    EXPECT_EQ(Statistics::mode(testVector1), 32);
    std::vector<int> testVector2 = {0};
    EXPECT_EQ(Statistics::mode(testVector2), 0);
}

TEST(Statistics_mode, empty_distribution)
{
    std::vector<int> testVector;
    EXPECT_THROW(Statistics::mode(testVector), std::invalid_argument);
}