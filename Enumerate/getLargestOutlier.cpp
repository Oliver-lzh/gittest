class Solution 
{
public:
    int getLargestOutlier(vector<int>& nums)
    {
        unordered_map<int,int> cnt;
        int result=INT_MIN;
        int total_sum=0;
        for(auto &i:nums)
        {
            total_sum+=i;
            cnt[i]++;
        }

         for(auto &i:nums)
        {
            cnt[i]--;
            int rest=total_sum-i;

            if(rest%2==0)
            {
                if(cnt[rest/2]>0)
                {
                    result=max(result,i);
                }
            }
            cnt[i]++;
        }
       return result;
    }
};