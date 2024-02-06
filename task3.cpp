#include<bits/stdc++.h>
using namespace std;
void print(string s)
{

    if(s[0]=='/'&&s[1]=='/')cout<< "single comment line"<<endl;
    else if(s[0]=='/'&&s[1]=='*'&&s[s.size()-1]=='/'&&s[s.size()-2]=='*')
        cout<< "multiple line comment"<<endl;
        else cout<< "compilation error";


}
int main()
{
    string s;
    cin>>s;
    print(s);

}
