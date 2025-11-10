class Solution {
public:
    int longestOnes(vector<int>& nums, int k)
    {
        int right=0,left=0;
        int middle=0;
        int result=0;
        int fal=0;

        for(;right<nums.size();right++)
        {
            if(nums[right]==0)
            {
                fal++;
            }
        
            while(fal>k)
            {
                if(nums[left]==0)
                {
                    fal--;
                }
                left++;
            }
            result=max(result,right-left+1);
        }    
        return result;
    }
};

