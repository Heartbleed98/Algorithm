#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

string Manacher(string str)
{
    string new_str = "$#";
    for(int i = 0; i < str.size(); i++)
    {
        new_str += str[i];
        new_str += "#";
    }

    vector<int> p(new_str.size(), 0);
    //mx是回文串能延伸到的最右端的位置
    //id是能延伸到最右端位置的回文串的中心点位置
    int mx = 0, id = 0, resLen = 0, resCentre = 0;
    for(int i = 1; i < new_str.size(); i++)
    {   
        
        p[i] = (mx > i) ? min(p[2*id-i], mx-i) : 1;
        while(new_str[i+p[i]] == new_str[i-p[i]])
            p[i]++;
        if(mx < i + p[i])
        {
            mx = i + p[i];
            id = i;
        }
        if(resLen < p[i])
        {
            resLen = p[i];
            resCentre = i;
        }
    }
    //返回最长回文子串
    //半径 - 1 = 回文串长度
    return str.substr((resCentre - resLen) / 2, resLen - 1);
}

int main()
{
    string str;
    getline(cin, str);
    cout<<Manacher(str)<<endl;
    return 0;
}