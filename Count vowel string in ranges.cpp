class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
    // Step 1: Set for vowels
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    
    // Step 2: Precompute whether each word starts and ends with a vowel
    int n = words.size();
    vector<int> isValid(n, 0);
    
    for (int i = 0; i < n; i++) {
        if (vowels.count(words[i][0]) && vowels.count(words[i].back())) {
            isValid[i] = 1;  // Valid string
        }
    }
    
    // Step 3: Build prefix sum array
    vector<int> prefixSum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefixSum[i + 1] = prefixSum[i] + isValid[i];
    }
    
    // Step 4: Answer each query using prefix sum
    vector<int> result;
    for (const auto& query : queries) {
        int li = query[0];
        int ri = query[1];
        result.push_back(prefixSum[ri + 1] - prefixSum[li]);
    }
    
    return result;
}

int main() {
    // Example Input
    vector<string> words = {"aba", "bcb", "ece", "aa", "e"};
    vector<vector<int>> queries = {{0, 2}, {1, 4}, {1, 1}};
    
    // Call the function
    vector<int> result = vowelStrings(words, queries);
    
    // Print the results
    for (int res : result) {
        cout << res << " ";
    }
    cout << endl;
    
    return 0;
}
};

/*
- Problem: For each query, count how many words in the specified range start and end with a vowel.

- Approach:
  1. Use a set (`vowels`) to store the vowel characters ('a', 'e', 'i', 'o', 'u') for quick lookup.
  
  2. Precompute a validity array (`isValid`):
     - For each word, check if it starts and ends with a vowel.
     - If true, mark it as valid (1); otherwise, mark it as invalid (0).

  3. Build a prefix sum array (`prefixSum`) to efficiently calculate the count of valid words in any range:
     - Each element at index `i + 1` in `prefixSum` stores the cumulative sum of valid words up to index `i`.

  4. Answer each query using the prefix sum array:
     - For a query `[li, ri]`, calculate the result as `prefixSum[ri + 1] - prefixSum[li]`.
     - This gives the count of valid words in the range `[li, ri]`.

  5. Store the results for all queries in a `result` vector and return it.

- Complexity:
  - Preprocessing (validity and prefix sum): O(n), where n is the size of `words`.
  - Query answering: O(q), where q is the number of queries.
  - Total time complexity: O(n + q).
  - Space complexity: O(n) for the `isValid` and `prefixSum` arrays.
*/
