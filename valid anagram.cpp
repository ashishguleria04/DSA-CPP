class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end()); 
        if(s == t){
        return true;
    }else{
        return false;
    }
    }
    
};

// This function checks whether two given strings are anagrams of each other.
// An anagram is formed by rearranging the letters of one string to match another.

// Step 1: Sort both strings in ascending order.
//         - Sorting ensures that if two strings have the same characters in the 
//           same frequency, they will become identical after sorting.

// Step 2: Compare the sorted strings.
//         - If both sorted strings are equal, return true (they are anagrams).
//         - Otherwise, return false (they are not anagrams).

// Time Complexity: O(n log n) due to sorting, where n is the length of the longer string.
// Space Complexity: O(1), since sorting is done in-place.
