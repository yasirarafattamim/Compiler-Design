#include<bits/stdc++.h>
using namespace std;
void result(string s)
{

    string s1="";
    for(int i=0;i<s.size();i++)
    {

        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='%'||s[i]=='=')
        {

            s1+=s[i];

        }

    }
    for(int i=0;i<s1.size();i++)
    {
       cout<< "operator"<<i++<< ":"<<s1[i]<<endl;
    }
}
int main()
{
    string s;
    cin>>s;
    result(s);

}
