class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours)
    {
        unordered_map<int,int> cnt;
        long long result=0;

        for(int i=0;i<hours.size();i++)
        {
            int num=hours[i]%24;
            int complement=(24-num)%24;
            result+=cnt[complement];
            cnt[num]++;
        }    
        return result;
    }
};