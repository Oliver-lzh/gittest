class Solution {
public:
    int numIdenticalPairs(vector<int>& nums)
    {
        unordered_map<int,int> cnt;
        int result=0;
      
        for(int x:nums)
        {
            result+=cnt[x];//加这个键值的出现的个数
            cnt[x]++;//这里是枚举右 入账的过程
        }    
        return result;
    }
};