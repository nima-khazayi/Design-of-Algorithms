# Recursive Functions in C

This repository contains a C program that implements
various recursive functions to solve mathematical problems.
The program presents a menu to the user to choose the desired operation.

## Features

The following operations are implemented:

1. **Sum of numbers from 1 to n**
2. **Factorial of a number n**
3. **Power of a number (base^exp)**
4. **Integer division (dividend / divisor)**
5. **Modulus operation (dividend % divisor)**
6. **Greatest Common Divisor (GCD) of two numbers**
7. **Combinations (n choose r)**

## How to Compile and Run

1. Ensure you have a C compiler installed (e.g., GCC).
2. Save the provided code in a file named 'RecursivePs.c'.
3. Open your terminal and navigate to the directory where the file is saved.
4. Compile the code using the following command:
   ```bash
   gcc -o Recursive RecursivePs.c
   ```
5. Run the compiled program:
   ```./Rescursive```

## Usage 

Upon running the program, you will be presented with
a menu to choose one of the available operations.
Follow the prompts to enter the required inputs.
The program will display the result based on your selection.

## Example
```
Choose a problem to solve:
1. Sum of 1 to n
2. Factorial of n
3. Power of a number (base^exp)
4. Integer division (dividend / divisor)
5. Modulus (dividend / divisor)
6. GCD of two numbers
7. Combination (n choose r)
Enter your choice (1-7): 2
Enter n: 5
Factorial of 5 is: 120
```

## Functions

- sum(int n): Recursively calculates the sum of numbers from 1 to n.
- factorial(int n): Recursively calculates the factorial of n.
- power(int base, int exp): Recursively calculates base raised to the power of exp.
- integerDivision(int dividend, int divisor): Recursively performs integer division.
- modulus(int dividend, int divisor): Recursively calculates the modulus.
- gcd(int a, int b): Recursively computes the GCD of a and b.
- combination(int n, int r): Recursively calculates combinations C(n,r).

## Feel free to modify any section as needed.
