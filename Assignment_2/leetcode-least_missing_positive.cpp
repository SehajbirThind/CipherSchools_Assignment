

// QUESTION: LEETCODE - FIRST MISSING POSITIVE

/*
Given an unsorted integer array, find the smallest missing positive integer.

Your algorithm should run in O(n) time and use constant extra space.



SOLUTION:

We take a number 'num' and initialize it to 1, since 1 is the least positive number.
Now, we find 'num' in the given vector. If it is not found, we return num. Else, we increment num to the next positive 
value, and so on....

*/




class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int num = 1;
        
        while(1)
        {
            vector< int >::iterator it = find(nums.begin(), nums.end(), num);
            if(it == nums.end())
            {
                return num;
            }
            else
                num++;
        }
        
        return num;
        
    }
};