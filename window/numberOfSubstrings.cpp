class Solution {
public:
    int numberOfSubstrings(string s) 
    {
        
        unordered_map<char,int> cnt;
        int right=0,left=0;
        int result=0;

        for(;right<s.size();right++)
        {
            char d=s[right];
            cnt[d]++;

            while(cnt.size()>=3 )
            {
                char t=s[left];
                cnt[t]--;
                if(cnt[t]==0)
                {
                    cnt.erase(t);
                }
                left++;
            }
            result+=left;

        }
        return result;
    }
};