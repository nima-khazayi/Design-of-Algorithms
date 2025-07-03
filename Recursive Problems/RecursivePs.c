#include <stdio.h>

// Function prototypes
int sum(int n);
int factorial(int n);
int power(int base, int exp);
int integerDivision(int dividend, int divisor);
int modulus(int dividend, int divisor);
int gcd(int a, int b);
int combination(int n, int r);

int main() {
    
    int choice, n, r, base, exp, dividend, divisor;

    // Display menu
    printf("Choose a problem to solve:\n");
    printf("1. Sum of 1 to n\n");
    printf("2. Factorial of n\n");
    printf("3. Power of a number (base^exp)\n");
    printf("4. Integer division (dividend / divisor)\n");
    printf("5. Modulus (dividend %% divisor)\n");
    printf("6. GCD of two numbers\n");
    printf("7. Combination (n choose r)\n");
    printf("Enter your choice (1-7): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter n: ");
            scanf("%d", &n);
            printf("Sum of 1 to %d is: %d\n", n, sum(n));
            break;
        case 2:
            printf("Enter n: ");
            scanf("%d", &n);
            printf("Factorial of %d is: %d\n", n, factorial(n));
            break;
        case 3:
            printf("Enter base and exponent: ");
            scanf("%d %d", &base, &exp);
            printf("%d raised to the power of %d is: %d\n", base, exp, power(base, exp));
            break;
        case 4:
            printf("Enter dividend and divisor: ");
            scanf("%d %d", &dividend, &divisor);
            printf("Integer division of %d by %d is: %d\n", dividend, divisor, integerDivision(dividend, divisor));
            break;
        case 5:
            printf("Enter dividend and divisor: ");
            scanf("%d %d", &dividend, &divisor);
            printf("Modulus of %d by %d is: %d\n", dividend, divisor, modulus(dividend, divisor));
            break;
        case 6:
            printf("Enter two numbers: ");
            scanf("%d %d", &n, &r);
            printf("GCD of %d and %d is: %d\n", n, r, gcd(n, r));
            break;
        case 7:
            printf("Enter n and r (n >= r): ");
            scanf("%d %d", &n, &r);
            printf("Combination C(%d, %d) is: %d\n", n, r, combination(n, r));
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}

// Recursive function to calculate sum of 1 to n
int sum(int n) {
    if (n <= 0) return 0;
    return n + sum(n - 1);
}

// Recursive function to calculate factorial of n
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// Recursive function to calculate power of base^exp
int power(int base, int exp) {
    if (exp == 0) return 1;
    return base * power(base, exp - 1);
}

// Recursive function for integer division
int integerDivision(int dividend, int divisor) {
    if (dividend < divisor) return 0;
    return 1 + integerDivision(dividend - divisor, divisor);
}

// Recursive function for modulus
int modulus(int dividend, int divisor) {
    if (dividend < divisor) return dividend;
    return modulus(dividend - divisor, divisor);
}

// Recursive function to calculate GCD of a and b
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Recursive function to calculate combinations C(n, r)
int combination(int n, int r) {
    if (r == 0 || r == n) return 1;
    return combination(n - 1, r - 1) + combination(n - 1, r);
}
