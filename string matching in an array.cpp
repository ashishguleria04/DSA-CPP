vector<string> stringMatching(vector<string>& words) {
    // Sort words by length
    sort(words.begin(), words.end(), [](const string& a, const string& b) {
        return a.length() < b.length();
    });

    vector<string> result; // To store the result

    // Check each word against longer words only
    for (int i = 0; i < words.size(); ++i) {
        for (int j = i + 1; j < words.size(); ++j) {
            if (words[j].find(words[i]) != string::npos) { 
                result.push_back(words[i]);
                break; // No need to check further
            }
        }
    }
    return result;
}


/*
- Problem: Find all words in the list `words` that are substrings of any other word in the list.

- Approach:
  1. Sort the words by length:
     - Sorting ensures smaller words are checked against larger ones, reducing unnecessary comparisons.

  2. Use nested loops to compare each word:
     - Outer loop (`i`): Iterates through the shorter words.
     - Inner loop (`j`): Iterates through longer words (only words after `i` due to sorting).

  3. Check if a shorter word (`words[i]`) is a substring of a longer word (`words[j]`):
     - Use `find()` to check if `words[i]` exists within `words[j]`.
     - If true, add `words[i]` to the result and stop further checks for it (break the inner loop).

  4. Return the result vector containing all matching words.

- Complexity:
  - Sorting: O(n log n), where n is the number of words.
  - Substring checks: O(n^2 * k), where k is the average length of the words (due to `find` operation).
  - Total complexity: O(n^2 * k) in the worst case.

- Space: O(n) for the result vector.
*/
