#include "quadratic_equation.h"

#include <math.h>

roots_t solve_equation(double a, double b, double c) {
  roots_t roots;
  double discriminant = b * b - 4 * a * c;
  if (a == 0) {      // If a is 0, it's a linear equation
    if (b == 0) {    // If b is also 0, no roots
      if (c == 0) {  // Infinite solutions
        roots.num_roots = NO_SOLUTION;
      } else {
        roots.num_roots = ZERO_ROOTS;  // No solutions
      }
    } else {  // If b is not 0, one root (linear equation)
      roots.num_roots = ONE_ROOT;
      roots.first_root = -c / b;
      roots.second_root = roots.first_root;
    }
  } else {                   // If a is not 0, it's a quadratic equation
    if (discriminant > 0) {  // If discriminant > 0, two real roots
      roots.num_roots = TWO_ROOTS;
      roots.first_root = (-b + sqrt(discriminant)) / (2 * a);
      roots.second_root = (-b - sqrt(discriminant)) / (2 * a);
    } else if (discriminant == 0) {  // If discriminant = 0, one real root (both
                                     // roots are the same)
      roots.num_roots = ONE_ROOT;
      roots.first_root = -b / (2 * a);
      roots.second_root = roots.first_root;
    } else {  // If discriminant < 0, no real roots
      roots.num_roots = ZERO_ROOTS;
    }
  }
  return roots;
}