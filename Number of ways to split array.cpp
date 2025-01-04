class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
    if (n < 2) return 0;

    // Step 1: Calculate the total sum of the array
    long long totalSum = 0;
    for (int num : nums) {
        totalSum += num;
    }

    // Step 2: Iterate and calculate splits on-the-fly
    long long leftSum = 0;
    int validSplits = 0;

    for (int i = 0; i < n - 1; ++i) {
        leftSum += nums[i]; // Add the current element to the left sum
        long long rightSum = totalSum - leftSum; // Calculate the right sum

        if (leftSum >= rightSum) {
            ++validSplits;
        }
    }

    return validSplits;
    }
        
};

/*
- Problem: Count the number of valid ways to split the array into two non-empty parts
           such that the sum of the left part is greater than or equal to the sum of the right part.

- Approach:
  1. Calculate the total sum of the array (`totalSum`) in a single pass.
  
  2. Use a variable `leftSum` to track the cumulative sum of elements in the left part during iteration.

  3. Traverse the array from the beginning to the second-last element:
     - Add the current element to `leftSum`.
     - Compute `rightSum` as `totalSum - leftSum`.
     - Check if `leftSum >= rightSum`:
       - If true, increment the count of valid splits (`validSplits`).

  4. Return the count of valid splits.

- Complexity:
  - Time: O(n), where n is the size of the array, since we traverse the array twice (once for totalSum, once for splits).
  - Space: O(1), since we only use a few variables for computation.
*/
