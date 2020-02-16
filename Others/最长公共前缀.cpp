// 编写一个函数来查找字符串数组中的最长公共前缀。
// 如果不存在公共前缀，返回空字符串 ""。
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        string prefix = strs[0];
        for(int i = 1; i < strs.size(); i++)
        {
            while(strs[i].find(prefix) != 0)
            {
                prefix = prefix.substr(0, prefix.size() - 1);
                if(prefix.empty())
                    return "";
            }
        }
        return prefix;
    }
};