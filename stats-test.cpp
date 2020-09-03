#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "stats.h"
#include <cmath>

using namespace std;

TEST_CASE("reports average, minimum and maximum") {
    auto computedStats = Statistics::ComputeStatistics({1.5, 8.9, 3.2, 4.5});
    float epsilon = 0.001;
    REQUIRE(abs(computedStats.average - 4.525) < epsilon);
    REQUIRE(abs(computedStats.max - 8.9) < epsilon);
    REQUIRE(abs(computedStats.min - 1.5) < epsilon);
}

TEST_CASE("average is NaN for empty array") {
    //All fields of computedStats (average, max, min) must be
    //NAN (not-a-number), as defined in math.h 
    //Use http://www.cplusplus.com/reference/cmath/isnan/
    auto computedStats = Statistics::ComputeStatistics({});
    
    REQUIRE(isnan(computedStats.average)==true);
    REQUIRE(isnan(computedStats.min)==true);
    REQUIRE(isnan(computedStats.max)==true);
}
