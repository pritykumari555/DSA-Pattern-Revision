/*
Problem: Happy Number
LeetCode:https://leetcode.com/problems/happy-number/description/

Approach: Slow and Fast Pointers (Cycle Detection)

Explanation:
1. Calculate the sum of squares of the digits.
2. Repeat the process using the new number.
3. If the number becomes 1, it is a Happy Number.
4. If a cycle occurs before reaching 1, it is not a Happy Number.

Time Complexity: O(log n) per digit-sum operation; overall cycle detection depends on the sequence length.
Space Complexity: O(1) auxiliary space.
*/

class Solution {
public:
    int sumOfSquares(int n) {
        int sum = 0;

        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }

        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        do {
            slow = sumOfSquares(slow);
            fast = sumOfSquares(sumOfSquares(fast));
        } while (slow != fast);

        return slow == 1;
    }
};
