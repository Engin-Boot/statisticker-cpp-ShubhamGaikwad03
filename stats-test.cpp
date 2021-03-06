#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "stats.h"
#include <cmath>
#include<math.h>

TEST_CASE("reports average, minimum and maximum") {
    auto computedStats = Statistics::ComputeStatistics({1.5, 8.9, 3.2, 4.5});
    float epsilon = 0.001;
    REQUIRE(std::abs(computedStats.average - 4.525) < epsilon);
    REQUIRE(std::abs(computedStats.max - 8.9) < epsilon);
    REQUIRE(std::abs(computedStats.min - 1.5) < epsilon);
}

TEST_CASE("reports average, minimum and maximum when atleast one input is NAN") {
    auto computedStats = Statistics::ComputeStatistics({1.5,NAN, 8.9, 3.2, 4.5});
    float epsilon = 0.001;
    REQUIRE(std::abs(computedStats.average - 4.525) < epsilon);
    REQUIRE(std::abs(computedStats.max - 8.9) < epsilon);
    REQUIRE(std::abs(computedStats.min - 1.5) < epsilon);
}

TEST_CASE("average is NaN for empty array") {
    //All fields of computedStats (average, max, min) must be
    //NAN (not-a-number), as defined in math.h 
    //Use http://www.cplusplus.com/reference/cmath/isnan/
    auto computedStats = Statistics::ComputeStatistics({});
    REQUIRE(isnan(computedStats.average)==true);
    REQUIRE(isnan(computedStats.max)==true);
    REQUIRE(isnan(computedStats.min)==true);
}
