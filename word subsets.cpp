class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxFreq(26, 0); // To store the maximum frequency of each character in words2
    
    // Calculate the maximum frequency required for each character across all words in words2
    for (const string& word : words2) {
        vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            maxFreq[i] = max(maxFreq[i], freq[i]);
        }
    }
    
    vector<string> result;
    
    // Check if each word in words1 satisfies the frequency requirement
    for (const string& word : words1) {
        vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }
        
        bool isUniversal = true;
        for (int i = 0; i < 26; i++) {
            if (freq[i] < maxFreq[i]) {
                isUniversal = false;
                break;
            }
        }
        
        if (isUniversal) {
            result.push_back(word);
        }
    }
    
    return result;
    }
};


/*
Approach:
1. **Calculate Maximum Frequency of Characters in `words2`:**
   - Create a vector `maxFreq` of size 26 initialized to 0, which will store the maximum frequency of each character across all words in `words2`.
   - For each word in `words2`, calculate the frequency of each character using a temporary vector `freq` of size 26.
   - Update `maxFreq` to store the maximum frequency of each character observed across all words in `words2`.

2. **Check Universal Words in `words1`:**
   - Iterate through each word in `words1` and calculate its frequency of characters using a `freq` vector of size 26.
   - For each word, check if it satisfies the frequency requirements defined in `maxFreq`:
     - For each character (indexed from 0 to 25), ensure that the frequency of the character in the current word is greater than or equal to its required frequency in `maxFreq`.
     - If any character does not meet the requirement, mark the word as not universal.
   - If the word satisfies the frequency requirements for all characters, add it to the result vector.

3. **Return the Result:**
   - Return the vector `result`, which contains all universal words from `words1` that satisfy the frequency requirements of `words2`.
This approach ensures efficient comparison using frequency counts and avoids redundant character checks for each word.
*/
