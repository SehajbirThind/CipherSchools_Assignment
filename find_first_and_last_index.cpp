class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        if (nums.size() == 0)
            return { -1, -1};

        vector< int >res;

        int lo = 0, hi = nums.size() - 1, mid;

        while (lo < hi)
        {
            mid = lo + (hi - lo) / 2; // choice of mid.

            if (nums[mid] >= target)
                hi = mid;
            else
                lo = mid + 1;  // this implies, lower mid.
        }

        // SANITY CHECK
        if (nums[lo] == target)
            res.push_back(lo);
        else
            return { -1, -1};  // because the element doesn't exist


        // FOR FINDING LAST index:
        // If I reach here, that element exists,
        // and res contains the index of the starting position


        hi = nums.size() - 1;   // technically, we don't need to reset our lo
        while (lo < hi)
        {
            mid = lo + (hi - lo + 1) / 2;

            if (nums[mid] > target)
                hi = mid - 1;     // this implies, upper mid
            else
                lo = mid;
        }

        // SANITY CHECK IS NOT REQUIRED HERE, BECAUSE WE HAVE ALREADY HANDLED THE
        // CASE OF [-1, -1] in the UPPER CASE.

        res.push_back(lo);

        return res;




    }
};