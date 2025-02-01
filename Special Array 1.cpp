class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for(int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] % 2 == nums[i + 1] % 2) {
                return false;
            }
        }
        return true;
    }

};

 // The function checks if the array follows an alternating parity pattern,
 // meaning consecutive elements must have different parity (one even, one odd).       
// Iterate through the array and compare each element with the next one.
 // If two consecutive elements have the same parity (both even or both odd),
// return false, indicating the array is not special.
// If all consecutive elements alternate in parity, return true.