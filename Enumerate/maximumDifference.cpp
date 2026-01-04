class Solution {
public:
    int maximumDifference(vector<int>& nums)
    {
        int ans=0;
        int pre_min=INT_MAX;
        for(int i=0;i<nums.size();i++)//枚举右
        {
            ans=max(ans,nums[i]-pre_min);
            pre_min=min(pre_min,nums[i]);//维护左 不管左边几个点我只要最小那个
        }
        return ans? ans:-1;
    }
};