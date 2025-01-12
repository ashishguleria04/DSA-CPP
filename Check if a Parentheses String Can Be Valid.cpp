class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
    
    // If the length of the string is odd, it can't be a valid parentheses string.
    if (n % 2 != 0) return false;
    
    int openUnlocked = 0, balance = 0;
    
    // Forward Pass
    for (int i = 0; i < n; ++i) {
        if (locked[i] == '0') {
            openUnlocked++;
        } else if (s[i] == '(') {
            balance++;
        } else {
            balance--;
        }
        
        // Use openUnlocked to cover excess ')'
        if (balance < 0) {
            if (openUnlocked > 0) {
                openUnlocked--;
                balance++;
            } else {
                return false;
            }
        }
    }
    
    // Reset counters for backward pass
    openUnlocked = 0;
    balance = 0;
    
    // Backward Pass
    for (int i = n - 1; i >= 0; --i) {
        if (locked[i] == '0') {
            openUnlocked++;
        } else if (s[i] == ')') {
            balance++;
        } else {
            balance--;
        }
        
        // Use openUnlocked to cover excess '('
        if (balance < 0) {
            if (openUnlocked > 0) {
                openUnlocked--;
                balance++;
            } else {
                return false;
            }
        }
    }
    
    return true;
    }
};


/*
Explanation:
1. The problem requires determining if a parentheses string `s` can be made valid
   by changing certain characters based on the `locked` string.

2. Key Observations:
   - A valid parentheses string must maintain balance between '(' and ')'.
   - Each '(' must have a corresponding ')' and vice versa.
   - `locked[i] == '1'` means the character at index `i` cannot be changed.
   - `locked[i] == '0'` means the character at index `i` can be changed to either '(' or ')'.
   - If the length of the string is odd, it is impossible to balance the parentheses.

3. Approach:
   - Perform two linear passes:
     a) **Forward Pass**: Ensure that there are enough '(' to balance ')' as we iterate left-to-right.
     b) **Backward Pass**: Ensure that there are enough ')' to balance '(' as we iterate right-to-left.
   - Use a variable `balance` to track the locked parentheses and another `openUnlocked` to track 
     the count of unlocked characters that can be adjusted to fix imbalances.

4. Forward Pass:
   - Increment `balance` for every locked '(' and decrement for every locked ')'.
   - Use `openUnlocked` to compensate for excess locked ')'.
   - If `balance` becomes negative and `openUnlocked` is 0, return false.

5. Backward Pass:
   - Reset `balance` and `openUnlocked`.
   - Traverse the string from right to left to ensure there are enough ')' to balance '('.

6. Time Complexity:
   - \(O(n)\): Each pass takes linear time, and there are two passes.
   - \(O(1)\): Uses only a few variables, so space complexity is constant.

7. Return `true` if the string can be made valid, otherwise return `false`.
*/