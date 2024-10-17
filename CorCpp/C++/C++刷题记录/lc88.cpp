#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <vector>
using namespace std;


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p = m + n - 1;
        int p1 = m - 1;
        int p2 = n - 1;
        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                p1--;
            } else {
                nums1[p] = nums2[p2];
                p2--;
            }
            p--;
        }
        while (p2 >= 0) {
            nums1[p] = nums2[p2];
            p2--;
            p--;
        }
        while (p1 >= 0) {
            nums1[p] = nums1[p1];
            p1--;
            p--;
        }

    }
};

int main()
{   
    vector<int> nums1;
    vector<int> nums2;
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(3);
    nums1.push_back(0);
    nums1.push_back(0);
    nums1.push_back(0);
    nums2.push_back(2);
    nums2.push_back(5);
    nums2.push_back(6);

    Solution s;
    s.merge(nums1, 3, nums2, 3);
    for (int i = 0; i < nums1.size(); i++) {
        cout << nums1[i] << " ";
    }
    return 0;
}


// 169. 多数元素
// https://leetcode-cn.com/problems/majority-element/
// 方法一：排序
int majorityElement(vector<int>& nums) {
        int m = nums.size();
        sort(nums.begin(), nums.end());
        return nums[m / 2];   
    }
//time O(nlogn) space O(logn)

// 方法二：随机
int majorityElement(vector<int>& nums) {
        int n = nums.size();
        while (true) {
            int candidate = nums[rand() % n];
            int count = 0;
            for (int num : nums) {
                if (num == candidate) {
                    count++;
                }
            }
            if (count > n / 2) {
                return candidate;
            }
        }
        return -1;
    }
//time O(n) space O(1) ！！！！


//45. 跳跃游戏 II
