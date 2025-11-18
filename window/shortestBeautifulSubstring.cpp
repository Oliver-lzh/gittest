class Solution {
public:
    string shortestBeautifulSubstring(string s, int k)
    {
        int left=0,right=0;
        int middle=0;
        int num_one=0;
        vector<string> sub_result;
        string result;    

        for(;right<s.size();right++)
        {
            if(s[right]=='1')
            {
                num_one++;
            }
            while(num_one>=k)
            {
                if(num_one==k && s[left]=='1')
                {
                    sub_result.push_back(s.substr(left,right-left+1));
                }
                if(s[left]=='1')
                {
                    num_one--;
                }
                left++;
            }
        }
        
        if(sub_result.empty())
        {
            return "";
        }

        int min_length=sub_result[0].size();
        int min_index=0;
        for(int i=0;i<sub_result.size();i++)
        {
            int current_length=sub_result[i].size();
            if(current_length<min_length)
            {
                min_length=current_length;
                min_index=i;
            }
            else if(current_length == min_length)
            {
                if(sub_result[i] < sub_result[min_index])
                {
                    min_index = i;
                }
            }
        }
    result=sub_result[min_index];
    return result;
    }
};