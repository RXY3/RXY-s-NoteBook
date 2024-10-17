#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        for(int i=0;i<citations.size();i++)
        {
            if(citations[i]>=citations.size()-i)
            {
                return citations.size()-i;
            }
        }
    }
};
int main()
{

    return 0;
}