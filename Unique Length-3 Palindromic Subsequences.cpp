class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
    vector<int> before(26, 0), after(26, 0);
    unordered_set<string> uniquePalindromes;

    // Fill the `after` array with frequencies of each character
    for (char c : s) {
        after[c - 'a']++;
    }

    // Traverse the string and check for palindromes
    for (int i = 0; i < n; i++) {
        char middle = s[i];

        // Decrement the count of the current character from the `after` array
        after[middle - 'a']--;

        // Check all possible `X_YX` combinations
        for (char x = 'a'; x <= 'z'; x++) {
            if (before[x - 'a'] > 0 && after[x - 'a'] > 0) {
                string palindrome = string(1, x) + middle + x;
                uniquePalindromes.insert(palindrome);
            }
        }

        // Increment the count of the current character in the `before` array
        before[middle - 'a']++;
    }

    // Return the number of unique palindromes
    return uniquePalindromes.size();
    }
};


/*
- Problem: Count unique palindromic subsequences of the form "X_YX" in the string.

- Approach:
  1. Use two frequency arrays:
     - `before`: Tracks character frequencies before the current index.
     - `after`: Tracks character frequencies after the current index.
     
  2. Initialize `after` with the frequencies of all characters in the string.

  3. Traverse the string, treating each character as the middle (`Y`) of the palindrome:
     - Decrement its count in `after` since it's now processed.
     - For each character `X` ('a' to 'z'):
       - Check if `X` appears in both `before` and `after`.
       - If true, form the palindrome "X_YX" and store it in a set (to ensure uniqueness).
     - Update the `before` array to include the current character.

  4. The size of the set represents the total number of unique palindromic subsequences.

- Complexity:
  - Time: O(n * 26) ≈ O(n), where n is the length of the string.
  - Space: O(26) for frequency arrays + space for the set of palindromes.
*/

