/*
Micro Notes:

Problem:
Return the nth Fibonacci number.
Fibonacci sequence: F(0)=0, F(1)=1, F(n)=F(n-1)+F(n-2) for n>1.

Logic:
- Base cases: if n <= 1 → return n.
- Use two variables (a=F(0), b=F(1)) to store last two Fibonacci numbers.
- Iterate from i=2 to n:
    1. temp = b (current Fibonacci)
    2. b = a + b → update current Fibonacci
    3. a = temp → update previous Fibonacci
- Return b → F(n)

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;  // base cases

        int a = 0, b = 1;  // F(0), F(1)
        for(int i = 2; i <= n; i++){
            int temp = b;   // store current
            b = a + b;      // next Fibonacci
            a = temp;       // update previous
        }
        return b;           // F(n)
    }
};
