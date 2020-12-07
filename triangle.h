#if !defined(TRIANGLE_H)
#define TRIANGLE_H

namespace triangle {
  enum class flavor{equilateral, isosceles, scalene};
  flavor kind(double side_1, double side_2, double side_3, double tolerance = 1e-5);
}  // namespace triangle

#endif // TRIANGLE_H
