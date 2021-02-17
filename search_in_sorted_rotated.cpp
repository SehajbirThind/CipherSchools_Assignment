class Solution {
public:
    int search(vector<int>& nums, int target) {



        int lo = 0, hi = nums.size() - 1, mid;
        int n = nums.size();
        while (lo < hi)
        {
            mid = lo + (hi - lo) / 2;

            if (nums[mid] <= nums[n - 1])
                hi = mid;
            else
                lo = mid + 1;
        }

        if (nums[lo] == target)
            return lo;

        int start = lo;
        lo = 0, hi = n - 1;
        // NOW, WE WILL FIND WHICH SIDE OF THE PIVOT ELEMENT WE NEED TO APPLY BINARY SEARCH ON.

        if (target >= nums[start] && target <= nums[n - 1]) // this means target is on right side
        {
            lo = start;
        }
        else
        {
            hi = start - 1;
        }

        // T*F*, FIRST F
        // p(x): x < target
        while (lo < hi)
        {
            mid = lo + (hi - lo) / 2;

            if (nums[mid] < target)
            {
                lo =  mid + 1;
            }
            else
                hi = mid;
        }

        if (nums[lo] == target)
            return lo;


        return -1;

    }
};