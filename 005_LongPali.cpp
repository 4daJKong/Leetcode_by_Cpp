#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
   /*the first one made by myself, however, it cost lots time and cannot access the test*/
    string longestPalindrome_mine(string s) {
        if (s.empty()) return "";
        if (s.size() == 1) return s;
        string res;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = n; j > i; j--)
            {

                if(res.size() > (j - i))
                {
                    break;
                }
                else 
                {
                    string sub_str = s.substr(i,(j - i));
                    string copy_str(sub_str);
                    reverse(copy_str.begin(), copy_str.end());
                    if (sub_str.compare(copy_str) == 0) 
                    {
                    res = s.substr(i,(j-i)); 
                    break;
                 
                    }
                }              
            }
        }
        return res;
        
    }
    /*second one,I find it on leetcode*/
    string longestPalindrome_inLeetcode(string s) {

        if (s.empty()) return "";
        if (s.size() == 1) return s;
        int max_len = 0;
        int start_idx = 0;
        int i = 0;
        while(i < s.size())
        {
            int r_ptr = i;
            int l_ptr = i;
            while(r_ptr < s.size()-1 && s[r_ptr] == s[r_ptr+1]) r_ptr++;
            i = r_ptr+1;
            while(r_ptr < s.size()-1 && l_ptr > 0 && s[r_ptr+1] == s[l_ptr-1])
            {
                r_ptr++;
                l_ptr--;
            }
            int new_len = r_ptr - l_ptr + 1;
            if (new_len > max_len)
            {
                start_idx = l_ptr;
                max_len = new_len;
            }

            
        }
        return s.substr(start_idx, max_len);

    }
    /*Manacher algorithm*/
    string longestPalindrome(string s) {
        string t = "$#";
        for (int i = 0; i < s.size(); i++)
        {
            t += s[i];
            t += "#";
        }
        vector <int> p(t.size(), 0);
        int mx = 0, id = 0, resLen = 0, resCenter = 0;
        for (int i = 1; i < t.size(); ++i)
        {
            p[i] = mx > i ? min(p[2*id - i], mx - i):1;
            while(t[i+p[i]] == t[i-p[i]]) ++p[i];
            if (mx < i + p[i])
            {
                mx = i + p[i];
                id = i;
            }
            if (resLen < p[i])
            {
                resLen = p[i];
                resCenter = i;
            }
        } 
        return s.substr((resCenter - resLen) / 2, resLen - 1);

    }


};

int main()
{

    // string s = "abcdefg";
    // int n = s.size();
    // // cout << n;
    // // cout << s;
    // for (int i = 0; i < n;  i++)
    // {
    //     for (int j = n; j > i; j--)
    //     {
    //     cout << s.substr(i,(j-i)) << endl;
    //     }
    // }
    // cout << s << endl;
    // cout << s.substr(1,4) << endl;
    // string copy(s.substr(1,4));
    // reverse(copy.begin(), copy.end());
    // cout << copy<< endl;

    Solution Sol1;
    //Sol1.longestPalindrome("cbbd");
    //Sol1.longestPalindrome("abracadabra");

    cout << Sol1.longestPalindrome("apqjpwedlhmvvpexxnntxheeynxmgzwxhnhfdvziuxnuusymklg \
    cacndoyhqkoahnkyaikohwkmnuphipftmzmihvmoetskioeypwjujvvusaxynzxxdugnebsisrtgeujkqkg \
    wjuplijhluumqcdurovyjsbowmnqndejwkihzbbdyxjunkduyqeihektaknbmkzgnnmgywylulxwyywrvie \
    qfenjeljofkqqqisdjsbfkvqgahxwkfkcucvrbbpyhwkfztjdboavtfynrudneieelwlcezqsuhmllcsadc \
    noyemsfdlrijoyj") <<endl;
    cout << Sol1.longestPalindrome("cbbd") << endl;
    cout << Sol1.longestPalindrome("bbbbb") << endl;
    cout << Sol1.longestPalindrome("abba") << endl;
    cout << Sol1.longestPalindrome("bananas") << endl;
    cout << Sol1.longestPalindrome("cbaabf") << endl;
    cout << Sol1.longestPalindrome("babad")<< endl;
    cout << Sol1.longestPalindrome("cbbd")<< endl;
    cout << Sol1.longestPalindrome("abracadabra")<< endl; //ada 
    cout << Sol1.longestPalindrome("level")<< endl;
    return 0;
}