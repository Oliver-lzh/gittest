class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes)
    {
        int ans=0;
        int cnt[10][10]{};
        for(auto &num:dominoes)
        {
            if(num[0]>num[1])
            {
                swap(num[0],num[1]);
            }
            ans+=cnt[num[0]][num[1]];//这一对骨牌的数量,因为第一次遇到就是0次，2对一样算为一次配对。
            cnt[num[0]][num[1]]++;
        }
        return ans;
    }
};