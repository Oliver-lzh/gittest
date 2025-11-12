class Solution {
public:
    int numFriendRequests(vector<int>& ages)
    {
        int cnt[121]{};

        for(int age :ages)
        {
            cnt[age]++;
        }

        int result=0,cnt_window=0,age_y=0;

        for(int age_x=0;age_x<121;age_x++)
        {
            cnt_window+=cnt[age_x];

            //不能发送好友请求
            if(age_y*2<=age_x+14)
            {
                cnt_window-=cnt[age_y];
                age_y++;
            }

            if(cnt_window>0)
            {
                result+=cnt[age_x]*cnt_window-cnt[age_x];
            }
        }
    return result;
    }

   
};