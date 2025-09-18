/*
Micro Notes:

Problem:
Reverse the digits of a 32-bit signed integer. 
If reversing causes overflow, return 0.

Logic:
- Extract digits one by one using modulo (%) operator.
- Build the reversed number by multiplying current result by 10 and adding the new digit.
- Before updating the result, check for overflow:
    - If ans > INT_MAX/10 or ans < INT_MIN/10 → return 0.
- Continue until all digits are processed.

Time Complexity: O(log10(x))  // number of digits in x
Space Complexity: O(1)
*/

class Solution {
public:
    int reverse(int x) {
        int ans = 0;  // stores the reversed number

        while (x != 0) {
            int digit = x % 10;  // extract last digit

            // Check for overflow before multiplying by 10
            if ((ans > INT_MAX / 10) || (ans < INT_MIN / 10)) {
                return 0;
            }

            ans = ans * 10 + digit;  // append digit to reversed number
            x = x / 10;              // remove last digit
        }

        return ans;
    }
};
