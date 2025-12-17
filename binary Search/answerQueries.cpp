class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries)
    {
        vector<int> result;

        ranges::sort(nums);
        vector<int> prefin(nums.size());
        partial_sum(nums.begin(),nums.end(),prefin.begin());

        for(int x:queries)
        {
            auto it=ranges::upper_bound(prefin,x);
            result.push_back(it-prefin.begin());
        }
        return result;
    }
};