class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        // MAPPING OF INDICES OF 2-D ARRAY INTO 1-D INDICES
        // GIVEN SOME INDEX K IN THE 1-D ARRAY, FIND AN EQUIVALENT (I, J) IN THE MATRIX

        if (matrix.size() == 0) return false;

        int m = matrix.size(), n = matrix[0].size(), lo, hi, mid, i, j;

        if (n == 0) return false;

        lo = 0, hi = m * n - 1;


        while (lo < hi) {
            mid = lo + (hi - lo + 1) / 2;

            i = mid / n;
            j = mid % n;

            if (matrix[i][j] > target)
                hi = mid - 1;
            else
                lo = mid;

        }

        // Sanity check
        i = lo / n;
        j = lo % n;

        if (matrix[i][j] == target)
            return true;

        return false;

    }
};