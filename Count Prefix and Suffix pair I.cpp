class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
    int n = words.size();
    
    // Define the helper function inside this function
    auto isPrefixAndSuffix = [](const string& str1, const string& str2) -> bool {
        int len1 = str1.size(), len2 = str2.size();
        if (len1 > len2) return false; // str1 cannot be prefix and suffix if it's longer than str2
        return str2.substr(0, len1) == str1 && str2.substr(len2 - len1) == str1;
    };

    // Iterate through all pairs (i, j) where i < j
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (isPrefixAndSuffix(words[i], words[j])) {
                count++;
            }
        }
    }
    
    return count;
}
    
};

/*
- Problem: Count how many pairs of words in the list `words` have the property
           that one word is both a prefix and a suffix of the other.

- Approach:
  1. **Helper function `isPrefixAndSuffix`**:
     - Takes two strings (`str1` and `str2`).
     - If `str1` is longer than `str2`, return false immediately (it can't be both a prefix and a suffix).
     - Check if `str1` is a prefix and a suffix of `str2` using `substr()`:
       - `substr(0, len1)` checks the prefix.
       - `substr(len2 - len1)` checks the suffix.

  2. **Iterate through all pairs of words**:
     - Use two nested loops to compare all pairs `(i, j)` where `i < j`.
     - For each pair, call the helper function to check if the condition is met.
     - If true, increment the `count`.

  3. **Return the final count**.

- Complexity:
  - Time: O(n^2 * k), where `n` is the number of words, and `k` is the average length of the words (due to `substr()`).
  - Space: O(1) additional space, since only a few variables are used outside the input.

*/
