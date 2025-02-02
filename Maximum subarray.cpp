class solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int n = nums.size();
            int maxSum = nums[0];
            int currSum = nums[0];
            
            for (int num : nums){
            if (currSum < 0)
                currSum = 0;
            currSum += num;
            maxSum = max(maxSum, currSum);
            }
            return maxSum;
        }
}

// Finds the maximum sum of a contiguous subarray.
// Uses Kadane's algorithm to find the maximum sum.
// - If the current sum is negative, reset it to 0.
// - Update the current sum and maximum sum.
// Uses O(n) time and O(1) space.
