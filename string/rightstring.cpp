#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int n;//要反转的个数
    string s;
    
    cin>>n;
    cin>>s;

    int len=s.size();
    
    reverse(s.begin(),s.end());
    reverse(s.begin(),s.begin()+n);
    reverse(s.begin()+n,s.end());
        
     
     cout<<s<<endl;
    
}





