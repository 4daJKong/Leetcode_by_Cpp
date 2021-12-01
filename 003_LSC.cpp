#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    public:
    int lengthOfLongestSubstring(string s) {

        map <int, int> dict_sub;
        int n = s.size();
        if (n == 1)
        {
            return 1;
        }
        int left = 0;
        int len_sub = 0;
        for (int right = 0; right < n; right++)
        {
            if(dict_sub.find(s[right]) != dict_sub.end())
            {
                left = max(left, dict_sub[s[right]] + 1);
            }
            len_sub = max(len_sub, right - left + 1);
            dict_sub[s[right]] = right;
        }
        return len_sub;       
    }
};
    



int main(){
    Solution Sol1;
    cout << Sol1.lengthOfLongestSubstring("abcabcbb") << endl; //3
    cout << Sol1.lengthOfLongestSubstring("bbbb") << endl;//1
    cout << Sol1.lengthOfLongestSubstring("pwwkew") << endl;//3
    cout << Sol1.lengthOfLongestSubstring("dvdf") << endl; //3  
    cout << Sol1.lengthOfLongestSubstring("") << endl;  //0 
    cout << Sol1.lengthOfLongestSubstring(" ") << endl;//1
    cout << Sol1.lengthOfLongestSubstring("tmmzuxt") << endl;//5
    
    return 0;
}