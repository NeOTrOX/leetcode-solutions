/*
Micro Notes:

Problem:
Check if a positive integer n is a perfect number. 
A perfect number = sum of its positive divisors excluding itself.

Logic:
- Edge case: n <= 1 → cannot be perfect → return false.
- Initialize sumDiv = 1 (1 is always a divisor).
- Loop from 2 to sqrt(n):
    1. If n % d == 0 → d is a divisor.
    2. Add both d and n/d to sumDiv.
    3. Avoid adding sqrt(n) twice for perfect squares.
- Finally, check if sumDiv == n → true if perfect.

Time Complexity: O(√n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool checkPerfectNumber(int n) {
        // Edge case: 1 or below can never be perfect
        if (n <= 1) return false;

        int sumDiv = 1; // Start with 1 (always a divisor)

        // Loop from 2 to sqrt(n)
        for (int d = 2; d * d <= n; d++) {
            if (n % d == 0) {
