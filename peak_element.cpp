class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int lo = 0, hi = nums.size() - 1, mid;

        // READ LEETCODE OFFICIAL SOLUTION (APPROACHES 2 AND 3) FOR
        // EFFECTIVE EXPLANATION.


        while (lo < hi)
        {
            mid = lo + (hi - lo) / 2;

            if (nums[mid] > nums[mid + 1])
                hi = mid;
            else
                lo = mid + 1;

        }
        return lo;
    }
};