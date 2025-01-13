class Solution {
public:
    int minimumLength(string s) {
        int ans = 0;
    vector<int> count(26);

    for (const char c : s)
      ++count[c - 'a'];

    for (int i = 0; i < 26; ++i)
      if (count[i] > 0)
        ans += count[i] % 2 == 0 ? 2 : 1;

    return ans;
    }
};


/*
    Explanation:
    The problem is to find the minimum length of a string `s` after performing operations 
    based on character frequencies.

    Key Observations:
    1. We are iterating through the string to calculate the frequency of each character.
    2. Each character contributes to the result as follows:
       - If the frequency of a character is even, the entire frequency can be used.
       - If the frequency of a character is odd, one occurrence can always be used to 
         contribute to the length, as we can have at most one unpaired character in a palindrome.

    Approach:
    1. Use a `vector<int>` of size 26 to count the frequency of each character ('a' to 'z').
    2. Iterate over the string and update the count array.
    3. Iterate over the count array:
       - If the count is even, add 2 (or the full count if it exceeds 2).
       - If the count is odd, add 1 to account for the usable part of the character.

    Complexity:
    - Time Complexity: \(O(n + 26) = O(n)\), where \(n\) is the length of the string.
      - \(O(n)\) for counting frequencies.
      - \(O(26)\) for iterating through the alphabet.
    - Space Complexity: \(O(1)\), as the count array is a fixed size of 26.

    This ensures the solution is efficient and works for large input sizes.
    */