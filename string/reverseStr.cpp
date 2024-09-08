class Solution {
public:
    string reverseStr(string s, int k)
    {
        int start=0,end=2*k;

        //for循环的最后一个条件可以控制每一次的步长，因此不要局限于i++
        for(int i=0;i<s.size();i+=2*k)
        {
            //1.每隔2k反转钱前k个
            //2.剩余字符小于2k但是大于k个，则反转前k个。
           if(i+k<=s.size())
            {
                reverse(s.begin()+i,s.begin()+i+k);
            }
            else//剩下的字符少于k个
            {
                reverse(s.begin()+i,s.end());
            }
        }
        return s;
    }
};