#ifndef QUADRATIC_EQUATION_H  // QUADRATIC_EQUATION_H
#define QUADRATIC_EQUATION_H  // QUADRATIC_EQUATION_H

// Enumeration for the possible number of roots of a quadratic equation
enum {
  NO_SOLUTION = -1,  // Infinite solution
  ZERO_ROOTS,        // No real roots
  ONE_ROOT,          // One real root
  TWO_ROOTS          // Two real roots
};

// Structure to store the results of solving a quadratic equation.
typedef struct roots_s {
  int num_roots;
  double first_root;
  double second_root;
} roots_t;

/**
 *  This function solves a quadratic equation of the form: ax^2 + bx + c = 0
 *  This function finds the roots of a quadratic equation given its coefficients
 * a, b, and c. Returns a roots_t structure with the number and values of the
 * roots.
 */
roots_t solve_equation(double a, double b, double c);

#endif  // QUADRATIC_EQUATION_H