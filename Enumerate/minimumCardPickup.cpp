//滑动窗口
class Solution {
public:
    int minimumCardPickup(vector<int>& cards)
    {
        int result=INT_MAX;
        int left=0,right=0;
        unordered_map<int,int> cnt;

        for(;right<cards.size();right++)   
        {
            cnt[cards[right]]++;

            while(cnt[cards[right]]>=2)
            {
                result=min(result,right-left+1);
                cnt[cards[left]]--;
                left++;
            }
        } 
        return result==INT_MAX? -1:result;
    }
};

//枚举
class Solution {
public:
    int minimumCardPickup(vector<int>& cards)
    {
        int result=INT_MAX;
        int left=0,right=0;
        unordered_map<int,int> cnt;

        for(;right<cards.size();right++)   
        {
            if(cnt.find(cards[right])!=cnt.end())
            {
                //找到有重复的
                result=min(result,right-cnt[cards[right]]+1);

            }
            cnt[cards[right]]=right;
        } 
        return result==INT_MAX? -1:result;
    }
};