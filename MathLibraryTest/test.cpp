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