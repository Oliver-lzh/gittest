bool isAnagram(char* s, char* t)
{
    int len1=strlen(s),len2=strlen(t);
    if(len1!=len2)
    {
        return false;
    }

    int map1[26]={0},map2[26]={0};
    for(int i=0;i<len1;i++)
    {
        //这里的意思是，从字符串数组中得到字母后，与‘a’相减得到对应的索引，并且在这个是索引中赋值。
        map1[s[i]-'a']+=1;
        map2[t[i]-'a']+=1;
    }

    for(int i=0;i<26;i++)
    {
        if(map1[i]!=map2[i])
        {
            return false;
        }
    }

    return true;
}