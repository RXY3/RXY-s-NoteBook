#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    string reverseWords(string s) {
        int num = s.size();
        //cut the string into words
        vector<string> words;
        for (int i = 0; i < num; i++) {
            if (s[i] != ' ') {
                int j = i;
                while (j < num && s[j] != ' ') {
                    j++;
                }
                words.push_back(s.substr(i, j - i));
                i = j;
            }
        }
        //reverse the words
        string res;
        for (int i = words.size() - 1; i >= 0; i--) {
            res += words[i];
            if (i != 0) {
                res += " ";
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    cout << s.reverseWords("   the   sky  is   blue    ") << endl;
    return 0;
}