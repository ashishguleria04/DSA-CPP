class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++){
            if (nums[i] > nums[(i+1) % n]){
                count++;
            }
            if (count > 1) return false;
        }
        return true;
    }
};


// Checks if the array is sorted and rotated.
// Counts breaks where nums[i] > nums[(i + 1) % n].
// - If breaks > 1 → return false (invalid rotation).
// - If breaks ≤ 1 → return true (sorted or valid rotation).
// Uses O(n) time and O(1) space.
