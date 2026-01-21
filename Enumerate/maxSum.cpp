class Solution {
public:
    int getmaxnum(int nums)
    {
        int result=0;
        while(nums)
        {
            int middle=nums%10;
            result=max(result,middle);
            nums/=10;
        }
    return result;
    }

    int maxSum(vector<int>& nums)
    {
        int result=-1;
        unordered_map<int,int> cnt;
        for(int i=0;i<nums.size();i++)
        {
            int middle=getmaxnum(nums[i]);
            if(cnt.find(middle)!=cnt.end())
            {
                result=max(result,nums[i]+cnt[middle]);
                if(nums[i]>cnt[middle])
                {
                    cnt[middle]=nums[i];
                }
            }
            else
                cnt[middle]=nums[i];
          
        }
        return result;
    }
};