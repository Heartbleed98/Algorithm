#include<iostream>
#include<string>
#include<vector>
using namespace std;

const int ASCII_SIZE = 128;

int sunday(string str1, string str2) 
{
    int size1 = str1.size();
    int size2 = str2.size();
    if(size2 == 0) return 0; // 类似strstr(), 模式串为空时应该返回0
    vector<int> move(ASCII_SIZE);

    for(int i = 0; i < ASCII_SIZE; i++)
        move[i] = size2 + 1;
    for(int i = 0; i < size2; i++) 
        move[str2[i]] = size2 - i;

    int s = 0, j;
    while (s <= size1- size2)
    {
        j = 0;
        while (str1[s+j] == str2[j])
        {
            j++;
            if (j >= size2)
                return s;
        }
        s += move[str1[s+size2]];
    }
    return -1;
}

int main()
{
    string str1 = "appletree";
    string str2 = "tree";

    cout<<sunday(str1, str2)<<endl;

    return 0;
}