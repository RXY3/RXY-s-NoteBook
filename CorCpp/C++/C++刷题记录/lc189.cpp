#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
        


    }
};


int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(7);
    int k = 3;
    Solution s;
    s.rotate(nums,k);
    for(int i=0;i<nums.size();i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}