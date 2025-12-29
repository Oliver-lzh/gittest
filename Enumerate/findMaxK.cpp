class Solution {
public:
    int findMaxK(vector<int>& nums)
    {
        int result=-1;
        unordered_set<int> cnt;

        for(int i=0;i<nums.size();i++)
        {
            if(cnt.count(-nums[i]))
                result=max(result,abs(nums[i]));
            cnt.insert(nums[i]);
        }
        return result;
    }
};