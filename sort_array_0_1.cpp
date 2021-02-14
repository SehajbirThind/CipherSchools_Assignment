// find first zero element:
int i = 0;
for (i = 0; i < nums.size(); i++)
{
    if (nums[i] == 0)
        break;
}

// now, find first non-zero element after the zero element, and swap it with the zero element
int j = i + 1;

for (; j < nums.size(); j++)
{
    if (nums[j] != 0)
    {
        swap(nums[j], nums[i]);
        i++;
    }
}