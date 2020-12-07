#include "triangle.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <stdexcept>

namespace triangle {
  flavor kind(double side_1, double side_2, double side_3, double tolerance) {
    // Store sides in an array
    std::array<double, 3> sides{side_1, side_2, side_3};
    std::sort(sides.begin(), sides.end());
    
    // Check that smaller side is bigger than 0
    if (sides[0] <= 0) {
      throw std::domain_error("One of the sides is less or equal than 0");
    }

    // Check triangular inequality for largest side with respect to the two smaller ones
    if (sides[2] > sides[0] + sides[1]) {
      throw std::domain_error("Inputs can't correspond to real triangle");
    }

    // Calculate kind
    if (sides[2] - sides[0] < tolerance) {
      return flavor::equilateral;
    } else if (sides[1] - sides[0] < tolerance) {
      return flavor::isosceles;
    } else if (sides[2] - sides[1] < tolerance) {
      return flavor::isosceles;
    } else {
      return flavor::scalene;
    }
  }
}  // namespace triangle
