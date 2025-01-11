class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
    int prefLen = pref.size();
    
    for (const string& word : words) {
        // Check if the word has the prefix using substr
        if (word.size() >= prefLen && word.substr(0, prefLen) == pref) {
            count++;
        }
    }
    
    return count;
    }
};

/*
Approach:
1. Initialize a counter variable `count` to 0, which will keep track of the number of words that start with the given prefix.
2. Calculate the length of the prefix `pref` and store it in `prefLen` for reuse during comparisons.
3. Iterate through each word in the vector `words` using a range-based for loop.
   - For each word, check if its length is greater than or equal to the length of the prefix (`prefLen`).
   - If the condition is satisfied, compare the substring of the word (from index 0 to `prefLen`) with the prefix `pref`.
   - If the substring matches the prefix, increment the counter `count`.
4. After processing all words in the vector, return the final value of `count` as the result.
This approach ensures that each word is checked efficiently for the given prefix using basic string operations.
*/

