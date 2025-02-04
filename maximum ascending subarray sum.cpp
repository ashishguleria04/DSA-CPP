class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int currentSum = nums[i];
            for (int j = i + 1; j < n; j++) { // j should start from i+1
                if (nums[j] > nums[j - 1]) { // Check for ascending order
                    currentSum += nums[j];
                } else {
                    break; // Stop when order breaks
                }
            }
            maxSum = max(maxSum, currentSum); // Update maxSum after each subarray
        }

        return maxSum;
    }
};


// This function finds the maximum sum of a contiguous ascending subarray in the given array.

// Step 1: Initialize variables.
//         - maxSum keeps track of the highest sum found.
//         - Iterate through the array using an outer loop to consider each element 
//           as the start of a possible ascending subarray.

// Step 2: Traverse the array to find ascending subarrays.
//         - Start with currentSum as the current element.
//         - Use an inner loop to check if the next element is greater than the previous one.
//         - If the order is maintained (nums[j] > nums[j - 1]), add nums[j] to currentSum.
//         - If the order is broken, break out of the loop to start a new subarray.

// Step 3: Update maxSum after checking each ascending subarray.

// Step 4: Return the maximum sum found.

// Time Complexity: O(n^2) in the worst case since we have a nested loop iterating through the array.
// Space Complexity: O(1) as only a few integer variables are used.
