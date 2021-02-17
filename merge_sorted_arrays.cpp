class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        // The idea is to go from the last indexes of both arrays, compare and put elements from either A or B to the final position, which can easily get since we know that A have enough space to store them all and we know size of A and B. Please refer to the comments for details.


        int ptr1 = m - 1;
        int ptr2 = n - 1;
        int ptr3 = m + n - 1;   // running pointer


        // go from the back by A and B and compare and put to the A element which is larger
        while (ptr1 >= 0 && ptr2 >= 0)
        {
            if (nums1[ptr1] > nums2[ptr2])
            {
                nums1[ptr3] = nums1[ptr1];
                ptr3--;
                ptr1--;
            }
            else
            {
                nums1[ptr3] = nums2[ptr2];
                ptr3--;
                ptr2--;
            }

        }

        // if B is longer than A just copy the rest of B to A location, otherwise no need to do anything
        while (ptr2 >= 0)
        {
            nums1[ptr3] = nums2[ptr2];
            ptr3--;
            ptr2--;
        }



    }
};