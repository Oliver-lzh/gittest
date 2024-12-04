class Solution {
public:
    string removeDuplicates(string s) 
    {
        stack<char> st;
       
        //找到不重复的字符串
        for(int i=0;i<s.size();i++)
        {
           
            if(st.empty() || st.top()!=s[i])
            {
                st.push(s[i]);
            }
            else
            {
                st.pop();
            }
        }

        //不重复字符串从栈中提取然后输出
        string result="";
        while(!st.empty())
        {
            result+=st.top();
            st.pop();
        }
        //反转字符串
        reverse(result.begin(),result.end());
        return result;
    }
};