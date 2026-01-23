class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points)
    {
        const int MOD=1'000'000'007;
        unordered_map<int,int> cnt;
        //统计y相同的点有多少
        for(auto &p:points)
        {
            cnt[p[1]]++;
        }
        long long ans=0,s=0;
        //这个写法是只考虑使用值，不考虑使用键
        //这里一层一层统计
        for(auto &[_,c]:cnt)
        {
            long long k=1LL*c*(c-1)/2;
            ans+=s*k;
            s+=k;
        }
        return ans%MOD;
    }
};