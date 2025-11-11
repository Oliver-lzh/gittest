class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k)
    {
        return resolve(nums,k)-resolve(nums,k+1);   
    }
    
    int resolve(vector<int>& nums, int k)
    {
        int left=0,right=0;
        int middle=0;
        int result=0;
        for(;right<nums.size();right++)
        {
            if(nums[right]%2==1)
            {
                middle++;
            }
            while(middle>=k)
            {
                if(nums[left]%2==1)
                {
                    middle--;
                }
                left++;
            }
            result+=left;
        }
        return result;
    }
};