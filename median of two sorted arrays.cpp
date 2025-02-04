class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) swap(nums1, nums2); // Ensure nums1 is smaller
        
        int x = nums1.size(), y = nums2.size();
        int low = 0, high = x;
        
        while (low <= high) {
            int partitionX = (low + high) / 2;
            int partitionY = (x + y + 1) / 2 - partitionX;
            
            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];
            
            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];
            
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                if ((x + y) % 2 == 0) {
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
                } else {
                    return max(maxLeftX, maxLeftY);
                }
            } else if (maxLeftX > minRightY) {
                high = partitionX - 1;
            } else {
                low = partitionX + 1;
            }
        }
        return 0.0; // Should never reach here
    }
};


// This function finds the median of two sorted arrays using a binary search approach.
// The key idea is to partition both arrays in such a way that the left half contains 
// the smaller elements and the right half contains the larger elements, ensuring 
// balance for finding the median.

// Step 1: Ensure nums1 is the smaller array for optimized binary search.
//         - If nums1 is larger, swap nums1 and nums2. This helps in keeping the 
//           binary search on the smaller array, reducing time complexity.

// Step 2: Perform binary search on nums1.
//         - The goal is to find a correct partition index in nums1 that satisfies 
//           the median condition.

// Step 3: Partitioning logic:
//         - partitionX is the midpoint of nums1’s search space.
//         - partitionY is calculated such that left half of nums1 and nums2 together 
//           contain half the total elements.
//         - maxLeftX and maxLeftY represent the largest values in the left partitions 
//           of nums1 and nums2, respectively.
//         - minRightX and minRightY represent the smallest values in the right 
//           partitions of nums1 and nums2, respectively.

// Step 4: Check if the partition is correct:
//         - If maxLeftX <= minRightY and maxLeftY <= minRightX, then the correct 
//           partition is found.
//         - If total length is even, return the average of maxLeft and minRight.
//         - If total length is odd, return the maximum of maxLeft values as the median.

// Step 5: Adjust search space if partitioning is incorrect:
//         - If maxLeftX > minRightY, move the partition left (high = partitionX - 1).
//         - If maxLeftY > minRightX, move the partition right (low = partitionX + 1).

// Time Complexity: O(log(min(m, n))), where m and n are sizes of nums1 and nums2.
// Space Complexity: O(1), as no extra space is used.
