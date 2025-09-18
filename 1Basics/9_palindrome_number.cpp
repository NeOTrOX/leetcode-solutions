/*
Micro Notes:

Problem:
Check if an integer is a palindrome (reads the same forward and backward).

Logic:
- Negative numbers are not palindromes → return false immediately.
- Reverse the integer:
    - Extract digits using modulo (%) operator.
    - Build the reversed number by multiplying current reversed by 10 and adding the digit.
- Compare reversed number with original:
    - If equal → palindrome.
    - Else → not palindrome.

Time Complexity: O(log10(x))  // number of digits
Space Complexity: O(1)
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;  // negative numbers are not palindrome
        }

        long long reversed = 0;  // store reversed number
        long long temp = x;      // copy of x to manipulate

        while (temp != 0) {
            int digit = temp % 10;       // extract last digit
            reversed = reversed * 10 + digit;  // append digit
            temp /= 10;                  // remove last digit
        }
        
        return (reversed == x);  // check palindrome
    }
};
