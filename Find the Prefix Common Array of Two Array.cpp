class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        const int n = A.size();
    int prefixCommon = 0;
    vector<int> ans;
    vector<int> count(n + 1);

    for (int i = 0; i < A.size(); ++i) {
      if (++count[A[i]] == 2)
        ++prefixCommon;
      if (++count[B[i]] == 2)
        ++prefixCommon;
      ans.push_back(prefixCommon);
    }

    return ans;
    }
};



/*
    Explanation:
    The problem is to find the prefix common array between two given arrays `A` and `B`.

    Key Observations:
    1. The goal is to count how many elements are common in the prefix of arrays `A` and `B` at each index.
    2. A "prefix common" element is an element that appears at the same position in both arrays `A` and `B` (but the element may not necessarily be at the same index in each array).
    3. The idea is to track the frequency of each element seen so far using a `count` array.
    4. For each index `i`, we check whether the element `A[i]` or `B[i]` has appeared twice, meaning it has appeared in both arrays. If so, we increment `prefixCommon`.

    Approach:
    1. Use a `count` array of size `n + 1` to track the frequency of each element.
    2. Iterate through the arrays `A` and `B` simultaneously, and for each element:
       - Increase its count in the `count` array.
       - If the count reaches 2, increment the `prefixCommon` counter.
    3. After processing each element, push the current `prefixCommon` count into the result vector `ans`.

    Complexity:
    - Time Complexity: \(O(n)\), where \(n\) is the length of the arrays.
      - We iterate over the arrays once.
    - Space Complexity: \(O(n)\) due to the `count` and `ans` arrays.
    
    This approach is efficient for large input sizes, as it only requires a single pass through the arrays.
    */