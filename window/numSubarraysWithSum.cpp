class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal)
    {
        return solve(nums, goal)-solve(nums, goal+1);
    }

    int solve(vector<int>& nums, int goal)
    {
        int left=0,right=0;
        int result=0;
        int middle=0;

        if (goal == 0) return nums.size() * (nums.size() + 1) / 2;

        for(;right<nums.size();right++)
        {
            middle+=nums[right];
            while(middle>=goal)
            {
                middle-=nums[left];
                left++;
            }
            result+=left;
        }
        return result;
    }
};