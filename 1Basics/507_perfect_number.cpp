class Solution {
public:
    bool checkPerfectNumber(int n) {
        // Edge case: 1 or below can never be perfect
        if (n <= 1) return false;

        int sumDiv = 1; // Start with 1 (always a divisor)

        // Loop from 2 to sqrt(n)
        for (int d = 2; d * d <= n; d++) {
            if (n % d == 0) {
                sumDiv += d;
                int q = n / d; // paired divisor

                if (q != d) { // avoid double-count in perfect squares
                    sumDiv += q;
                }
            }
        }

        return sumDiv == n;
    }
};