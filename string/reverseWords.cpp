class Solution {
public:

    void reverse(string &s,int start,int end)
    {
        for(int i=start,j=end;i<j;i++,j--)
        {
            swap(s[i],s[j]);
        }
    }

    void RemoveSpace(string &s)
    {

        int slow = 0;   //整体思想参考
        for (int i = 0; i < s.size(); ++i) { //
            if (s[i] != ' ')
            { //遇到非空格就处理，即删除所有空格。
                if (slow != 0) s[slow++] = ' '; //手动控制空格，给单词之间添加空格。slow != 0说明不是第一个单词，需要在单词前添加空格。
                //这里是直接处理一个单词
                while (i < s.size() && s[i] != ' ')
                { //补上该单词，遇到空格说明单词结束。
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow); //slow的大小即为去除多余空格后的大小。
    }
    
    string reverseWords(string s)
    {
    //移除多余空格
    RemoveSpace(s);
    //整个字符串反转
    reverse(s,0,s.size()-1);

    int start=0;
    for(int i=0;i<=s.size();++i)
    {
        //遍历到最后(只有一个单词的情况)或者是等于空格
        if(i==s.size() || s[i]== ' ')
        {
            reverse(s,start,i-1);
            start=i+1;
        }
    }
    return s;
    }
};