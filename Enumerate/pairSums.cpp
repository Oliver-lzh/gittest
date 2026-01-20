class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target)
    {
        vector<vector<int>> result;
        unordered_map<int,int> cnt;
        int k=0;
        for(auto i:nums)
        {
            if(cnt[target-i]>0)
            {
                result.push_back({i,target-i});
                cnt[target-i]--;
            }
            else
                cnt[i]++;
        }
        return result;
    }
};