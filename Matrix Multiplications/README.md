# Matrix Multiplication using Strassen's Algorithm

This project implements matrix multiplication using two methods:
the classic method and the Strassen's algorithm.
The program allows users to input the dimensions of two matrices,
randomly fills them with values, and then performs the multiplication using the selected method.

## Features

- **Matrix Multiplication**: Supports classic and Strassen's algorithm for matrix multiplication.
- **User Input**: Takes matrix dimensions and allows users to choose the multiplication method.
- **Random Matrix Generation**: Fills matrices with random integers for testing purposes.
- **Execution Time Measurement**: Measures and displays the time taken for the multiplication process.

## Requirements

- C compiler (e.g., GCC)
- Standard C Library

## Files

- 'Multipe.c': The main source code file containing the implementation of matrix multiplication.

## How to Compile

To compile the program, open your terminal and navigate to the directory
containing 'Multiple.c'. Then use the following command:
```gcc -o Multiple Multiple.c```

## How to Run

After compiling, you can run the program using:
```./Multiple```
Follow the prompts to enter the dimensions of the matrices
and choose the multiplication method.

## Example Usage

1. Enter the number of rows and columns for matrix A.
2. Enter the number of rows and columns for matrix B.
   (The number of columns in A must equal the number of rows in B).
3. Choose the method of multiplication.
   (1 for Classic, 2 for Strassen).
4. The program will display the resulting matrix and the time taken for the multiplication.

## Notes

- Ensure that the number of columns in Matrix A
  matches the number of rows in Matrix B for multiplication to be valid.
- Strassen's algorithm is generally faster for larger matrices
  but may require more memory (It only works for square matrices).
