class Solution {
public:
    int maxScore(string s) {
        int leftZeros = 0;
        int rightOnes = count(s.begin(), s.end(), '1'); // Count all 1's in the string
        int maxScore = 0;

    // Traverse through the string up to the second last character
        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] == '0') {
                leftZeros++; // Increment left zeros count
            } else {
                rightOnes--; // Decrement right ones count
            }

        // Calculate the score at this split
            int score = leftZeros + rightOnes;
            maxScore = max(maxScore, score); // Update the maximum score
        }

        return maxScore;
    }
};


/*
- Problem: Find the maximum score of splitting the string `s` into two non-empty parts,
           where the score is the sum of zeros on the left and ones on the right.

- Approach:
  1. Precompute the total number of '1's in the string (`rightOnes`) initially.
     - This represents the number of ones in the entire string before splitting.

  2. Use two variables to track counts while iterating through the string:
     - `leftZeros`: Count of zeros on the left side of the split.
     - `rightOnes`: Count of ones on the right side of the split (decrement as you move).

  3. Traverse the string up to the second last character (valid split point):
     - If the current character is '0', increment `leftZeros`.
     - If the current character is '1', decrement `rightOnes`.
     - Calculate the score as `leftZeros + rightOnes` at each split.
     - Update the `maxScore` if the current score is higher.

  4. Return the maximum score after evaluating all split points.

- Complexity:
  - Time: O(n), where n is the length of the string, since we traverse it once.
  - Space: O(1), as only a few variables are used.
*/
