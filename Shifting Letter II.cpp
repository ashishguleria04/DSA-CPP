string shiftingLetters(string s, vector<vector<int>>& shifts) {
    int n = s.length();
    vector<int> diff(n + 1, 0);

    // Build the difference array
    for (const auto& shift : shifts) {
        int start = shift[0], end = shift[1], direction = shift[2];
        int value = (direction == 1) ? 1 : -1;

        diff[start] += value;
        diff[end + 1] -= value;
    }

    // Apply the cumulative shift directly to the string
    int cumulativeShift = 0;
    for (int i = 0; i < n; ++i) {
        cumulativeShift += diff[i];
        int shift = cumulativeShift % 26; // Wrap around within the alphabet range
        if (shift < 0) shift += 26;      // Handle negative shifts
        s[i] = 'a' + (s[i] - 'a' + shift) % 26;
    }

    return s;
}


/*
- Problem: Apply a series of shifts to a string `s`, where each shift specifies:
           - A range `[start, end]`.
           - A direction (1 for right shift, 0 for left shift).
           The goal is to modify the string based on these shifts.

- Approach:
  1. Use a **difference array (`diff`)** to efficiently apply shifts over ranges:
     - For each shift `[start, end, direction]`:
       - Add `+1` (or `-1` for left shift) to `diff[start]`.
       - Subtract `-1` (or `+1`) at `diff[end + 1]` to indicate the end of the shift's effect.

  2. Apply cumulative shifts to compute the final changes:
     - Traverse the string while maintaining a `cumulativeShift` variable.
     - Add the cumulative shift value to each character:
       - Normalize the shift using `% 26` to wrap around the alphabet.
       - Handle negative shifts by adding 26 to keep the value within the valid range.

  3. Update the string characters:
     - Calculate the new character as `'a' + (current_char - 'a' + shift) % 26`.

  4. Return the modified string.

- Complexity:
  - Time: O(n + m), where:
       - `n` is the length of the string (for cumulative shift application).
       - `m` is the number of shifts (for updating the difference array).
  - Space: O(n) for the `diff` array.
*/
