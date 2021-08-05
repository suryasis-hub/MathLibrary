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