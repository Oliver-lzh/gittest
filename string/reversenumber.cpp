#include <iostream>
using namespace std;

int main()
{
    string s;
    while(cin>>s) //标准输入流 输入一个字符串
    {
        int Oright=s.size()-1;//字符的末尾指针
        int count=0;//统计数字的个数
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='0'&&s[i]<='9')
            {
                count++;
            }
        }
        
        s.resize(s.size()+count*5);
        int Nright=s.size()-1;
        
        while(Oright>=0)//指向旧字符串
        {
            // 旧字符串出现数字，就在新字符串后反着生成number
            if(s[Oright]>='0'&&s[Oright]<='9')
            {
                s[Nright--] = 'r';
                s[Nright--] = 'e';
                s[Nright--] = 'b';
                s[Nright--] = 'm';
                s[Nright--] = 'u';
                s[Nright--] = 'n';
            }
            else
            {
                s[Nright--]=s[Oright];
            }
            Oright--;
        }
        cout<<s<<endl;
    }
}