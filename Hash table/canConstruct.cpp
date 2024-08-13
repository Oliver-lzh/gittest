class Solution {
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int nums1[26]={0};

        if(ransomNote.size()>magazine.size())
        {
            return false;
        }

        //遍历magic 记录每个字母出现的次数
        for(int i=0;i<magazine.size();i++)
        {
            nums1[magazine[i]-'a']+=1;
        }

        for(int i=0;i<ransomNote.length();i++)
        {
            nums1[ransomNote[i]-'a']--;

            //如果小于0 说明Note中的字符magic没有
            if(nums1[ransomNote[i]-'a']<0)
            {
                return false;
            }
        }
        return true;
    }
};