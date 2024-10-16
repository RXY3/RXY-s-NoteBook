#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{   
    string s = "Hello World";
    int m = s.length();
    int count = 0;

    return 0;
}

class Solution {
public:
    int lengthOfLastWord(string s) {
        int m = s.length();
        int count = 0,i = m - 1;
        while(i >= 0 && s[i] == ' ')
        {
            i--;
        }
        for(;i >= 0 && s[i] != ' ';i--)
        {
            count++;
        }
        return count;

    }
};