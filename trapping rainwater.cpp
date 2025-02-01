class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int trappedWater = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                } else {
                    trappedWater += (leftMax - height[left]);
                }
                left++;
            } else {
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                } else {
                    trappedWater += (rightMax - height[right]);
                }
                right--;
            }
        }

        return trappedWater;
    }
};

/*
Approach:
This solution efficiently calculates the amount of trapped rainwater using the two-pointer approach.
The key observation is that the trapped water at any index depends on the minimum of the maximum heights
on the left and right sides of that index.

### Steps:

1. **Initialize Pointers and Variables:**
   - `left` and `right` pointers are set at the start and end of the array.
   - `leftMax` and `rightMax` store the maximum heights encountered so far from the left and right sides, respectively.
   - `trappedWater` stores the total trapped rainwater.

2. **Traverse the Array Using Two Pointers:**
   - We move the `left` and `right` pointers towards each other based on the smaller height.
   - If `height[left] < height[right]`, it means the amount of trapped water at `left` depends on `leftMax`.
   - If `height[right] <= height[left]`, the trapped water at `right` depends on `rightMax`.

3. **Update Maximum Heights:**
   - If `height[left] >= leftMax`, update `leftMax` since we found a new highest bar on the left.
   - Otherwise, add `leftMax - height[left]` to `trappedWater`, since this represents trapped water at `left`.
   - Similarly, update `rightMax` for the right pointer.

4. **Continue Until the Pointers Meet:**
   - The loop runs until `left` and `right` pointers cross each other.

### Time Complexity:
- **O(N)**, where `N` is the number of elements in `height`.
- Each element is processed at most once.

### Space Complexity:
- **O(1)**, as we only use a few integer variables.

### Why This Works:
- Water trapping at any index is determined by the shorter of the two maximum heights (`leftMax` and `rightMax`).
- The two-pointer technique allows us to process the array in a single pass without using extra space.
- By moving the pointer with the smaller height, we ensure that we are always working with a valid boundary.

### Example:
**Input:** `height = [0,1,0,2,1,0,1,3,2,1,2,1]`
**Processing:**
- Left and right pointers traverse towards the center.
- We maintain `leftMax` and `rightMax`, computing trapped water at each step.
**Output:** `6` units of trapped water.
*/