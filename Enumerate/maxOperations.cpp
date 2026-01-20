class Solution {
public:
    int maxOperations(vector<int>& nums, int k)
    {
        unordered_map<int,int> cnt;
        int result=0;
        for(int i=0;i<nums.size();i++)
        {
            if(cnt[k-nums[i]]>0)
            {
                result++;
                cnt[k-nums[i]]--;
            }
            else
                cnt[nums[i]]++;
        }
        return result;    
    }
};