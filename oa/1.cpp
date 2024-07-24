#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate factorial
int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

// Function to calculate combinations nCk
int combination(int n, int k) {
    if (k > n)
        return 0;
    return factorial(n) / (factorial(k) * factorial(n - k));
}

// Function to count numbers with n digits containing at least two zeros
int countNumbersWithTwoZeros(int n) {
    if (n < 2) 
        return 0;

    // Total numbers with n digits
    int total_numbers = pow(10, n) - 1; // All n-digit numbers from 1 to 10^n - 1

    // Calculate numbers without any zero
    int numbers_without_zeros = 9 * pow(9, n-1); // 9 choices for the first digit (1-9), 9 choices for each subsequent digit

    // Calculate numbers with exactly one zero
    int numbers_with_one_zero = n * pow(9, n-1); // n positions for zero, 9 choices for each other position

    // Calculate numbers with at least two zeros
    int numbers_with_at_least_two_zeros = total_numbers - numbers_without_zeros - numbers_with_one_zero;

    return numbers_with_at_least_two_zeros;
}

int main() {
    int n;
    cout << "Enter the number of digits (n): ";
    cin >> n;

    if (n < 2) {
        cout << "Invalid input. Number of digits must be at least 2." << endl;
        return 1;
    }

    int count = countNumbersWithTwoZeros(n);
    cout << "Number of integers with " << n << " digits containing at least two zeros: " << count << endl;

    return 0;
}
