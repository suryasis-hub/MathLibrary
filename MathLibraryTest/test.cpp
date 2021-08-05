#include "pch.h"
#include <iostream>
#include "../MathLibrary/MathLibrary.cpp"

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