class Solution {
public:
    bool isValid(string s)
    {
        //不是偶数不成对，因此无法实现。
        if(s.size()%2!=0) return false;
        stack<char> st;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')       st.push(')');
            else if(s[i]=='{')  st.push('}');
            else if(s[i]=='[')  st.push(']');

            //栈不为空的情况，就是左侧多余了括号 括号的类型不匹配
            else if(st.empty() || st.top()!=s[i]) return false;
            else st.pop();//这里就是栈的元素和遍历后面的相同，出现出栈操作
        }
        return st.empty();  
    }
};