class Solution {
public:
    long long countBadPairs(vector<int>& nums)
    {
        unordered_map<int,int> cnt;
        long long goodpairs=0;
        int result=0;

         long long n = nums.size();
        // 总对数 = n*(n-1)/2
        long long totalPairs = n * (n - 1) / 2;

        for(long long i=0;i<nums.size();++i)
        {
            long long diff=i-nums[i];
            goodpairs+=cnt[diff];
            cnt[diff]++;
        }
        return totalPairs-goodpairs;
    }

};