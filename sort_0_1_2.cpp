class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, white = 0;  // white is running pointer, red is left-pointer
        int blue = nums.size() - 1;  // blue is right-pointer

        while (white <= blue)
        {
            if (nums[white] == 0)
            {
                swap(nums[white++], nums[red++]);
            }
            else if (nums[white] == 2)
            {
                swap(nums[white], nums[blue--]);
            }
            else
                white++;
        }

    }




};
