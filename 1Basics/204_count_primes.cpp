/*
Micro Notes:

Problem:
Count the number of prime numbers less than a non-negative number n.

Logic:
- Use Sieve of Eratosthenes:
    1. Create a boolean array isPrime of size n, initialized to true.
    2. Mark 0 and 1 as non-prime.
    3. For each number i from 2 to sqrt(n):
        - If i is prime:
            - Mark all multiples of i (starting from i*i) as non-prime.
    4. Count all numbers marked as prime.

Time Complexity: O(n log log n)  // efficient prime sieve
Space Complexity: O(n)
*/

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;  // 0 and 1 are not prime

        // Sieve of Eratosthenes
        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;  // mark multiples as non-prime
                }
            }
        }

        // Count primes
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) count++;
        }
        return count;
    }
};
