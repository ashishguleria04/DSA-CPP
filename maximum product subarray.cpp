class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0], minProd = nums[0], result = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < 0) swap(maxProd, minProd);
        maxProd = max(nums[i], maxProd * nums[i]);
        minProd = min(nums[i], minProd * nums[i]);
        result = max(result, maxProd);
    }
    return result;
    }
};


// explanation:
// The idea is to keep track of both the maximum and minimum product of subarrays that end at the current element.
// The maximum product ending at the current element can be either the current element itself or the product of the maximum product ending at the previous element and the current element.
// The minimum product ending at the current element can be either the current element itself or the product of the minimum product ending at the previous element and the current element.
// We also need to keep track of the maximum product overall, which is updated at each step by taking the maximum of the current maximum product and the maximum product ending at the current element.
// At each step, we update the maximum and minimum product ending at the current element, and the maximum product overall.
// Finally, we return the maximum product overall as the result.
// The time complexity of this approach is O(n), where n is the number of elements in the input array, as we iterate through the array only once. The space complexity is O(1), as we only use a constant amount of extra space to store the maximum and minimum product ending at the current element.