# Quadratic Equation Solver
This project involves a basic C program designed to solve quadratic equations in the form of ax^2 + bx + c = 0.
## Quadratic Equation Solver Function
The solve_equation function requires three parameters: a, b, and c, representing the coefficients of a quadratic equation. Upon execution, it returns a roots_t struct that holds information about the number and values of the roots found. The function initially verifies whether the equation is linear by checking if a equals zero. If the equation is indeed linear, it proceeds to solve the equation bx + c = 0. However, if the equation is not linear, the function calculates the discriminant and determines the roots based on its value.
## Command Options
#### Compile Static Library:
```
make all
```
or 
```
make
```
#### Run Tests:
```
make check
```
#### Clean Compiled Files:
```
make clean
```
#### Errors check:

if you have used make check before this, you need to use make clean, recompile the static library (make or make all), and then use:
```
make valgrind
```

or use :
```
make
```
```
make valgrind
```
#### Rebuild project:
```
make rebuild
```
