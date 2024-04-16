#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        int tail = len-1;
        int j=0;
        while(1){
        for(int i=0;i<tail;i++)
        {
            if(i+nums[i]>=tail){
                tail = i;
                j++;
                break;
            }
        }
        if(tail==0)break;
        }
        return j;
    }
};
int main()
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(4);
    Solution s;
    cout<<s.jump(nums);
    return 0;
}

