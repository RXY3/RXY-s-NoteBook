#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <iostream>

using namespace std;


// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         struct Node {
//             int exist;
//             int max_len;
//         };
//         unordered_map<int, Node> map;
//         // int max = -1e9;
//         // for (int i = 0; i < nums.size(); i++) {
//         //     if (max < nums[i]) {
//         //         max = nums[i];
//         //     }
//         // }
//         // cout << "max: " << max << endl;
//         // cout << map[1].exist << endl;
//         // cout << map[1].max_len << endl;
//         int max_len = 0;
//         for (int i = 0; i < nums.size(); i++) {
//             if(map[nums[i]].exist) {
//                 continue;
//             }
//             map[nums[i]].exist = 1;
//             map[nums[i]].max_len = 1;
//             map[nums[i]].max_len = map[nums[i] - 1].exist * map[nums[i] - 1].max_len + map[nums[i] + 1].exist * map[nums[i] + 1].max_len + 1;
//             if (max_len < map[nums[i]].max_len) {
//                 max_len = map[nums[i]].max_len;
//             }
//             if(map[nums[i] - 1].exist) {
//                 map[nums[i] - map[nums[i] - 1].max_len].max_len = map[nums[i]].max_len;
//             }
//             if(map[nums[i] + 1].exist) {
//                 map[nums[i] + map[nums[i] + 1].max_len].max_len = map[nums[i]].max_len;
//             }
//         }
//         return max_len;
//     }
// };

// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int head = 0;
//         int tail = nums.size() - 1;
//         int num_zero = 0;
//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i] == 0) {
//                 num_zero++;
//                 continue;
//             }
//             else {
//                 nums[head] = nums[i];
//                 head++;
//             }
//         }
//         for (int i = 0; i < num_zero; i++) {
//             nums[tail] = 0;
//             tail--;
//         }
//         // cout << "num_zero: " << num_zero << endl;
//         // for (int i = 0; i < nums.size(); i++) {
//         //     cout << nums[i] << " ";
//         // }
//         return;
//     }
// };
/*
此题思路：
1. 用两个指针head和tail分别指向数组的头和尾
2. 遍历数组，如果当前元素不为0，则将其赋值给head指向的元素，head指针向后移动
3. 遍历结束后，将tail指针之后的元素全部赋值为0
较为麻烦的是，需要考虑到0的个数，因为0不需要移动，所以需要一个变量来记录0的个数

修改后的思路
用两个指针代表未处理和处理好的元素的边界
1. 遍历数组，如果当前元素不为0，则左右指针交换，左指针向后移动
2. 遍历结束后，左指针之后的元素全部赋值为0


*/

/*
https://leetcode.cn/problems/trapping-rain-water/?envType=study-plan-v2&envId=top-100-liked
接雨水
思路待补充：

*/
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         //brute
//         // int sum = 0,index = 0;
//         // int head = 0,tail = height.size() - 1;
//         // while(head < tail) {
//         //     index++;
//         //     while(height[head] < index && head < tail) head++;
//         //     while(height[tail]<index && head < tail)tail--;
//         //     for(int i=head;i<tail;i++)
//         //     {
//         //         if(height[i]<index)sum++;
//         //     }
//         //     if(tail-head<=1)break;
//         // }
//         // return sum;
//         //better
//         int head = 0, tail = height.size() - 1,sum = 0;
//         while(height[head]==0) head++;
//         while(height[tail]==0)tail--;
//         int index;
//         while(head < tail){
//             int tmp_sum = 0;
//             index = head+1;
//             while(height[index] < height[head] && index < tail){
//                 tmp_sum += height[head] - height[index];
//                 index++;
//             }
//             if(index < tail)
//             {
//                 sum += tmp_sum;      
//                 head = index;
//                 tmp_sum = 0;
//             }
//             else break;
//         }
//         if(index == tail) {
//             height_all = min(height[head],height[tail]);
//             for(int i = head+1;i<tail;i++){
//                 sum += height_all - height[i];
//             }
//             return sum;
//         }
//         while(head < tail){
//             int tmp_sum = 0;
//             int index = tail-1;
//             while(height[index] <= height[tail] && index > head){
//                 tmp_sum += height[tail] - height[index];
//                 index--;
//             }
//             if(index >= head)
//             {
//                 sum += tmp_sum;
//                 tail = index;
//                 tmp_sum = 0;
//             }
//             else break;
//         }
//         return sum;
//     }
// };


// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p) {
//         //brute,too slow
//         // for(int i=0;i<s.size();i++)
//         // {
//         //     if(i+p.size()>s.size())break;
//         //     string tmp = s.substr(i,p.size());

//         //     sort(tmp.begin(),tmp.end());

//         //     sort(p.begin(),p.end());

//         //     if(tmp==p)res.push_back(i);
//         // }
//         vector<int> res;
//         unordered_map<char,int> map_s,map_p;
//         for(int i=0;i<p.size();i++)
//         {
//             map_p[p[i]]++;
//             map_s[s[i]]++;
//         }
//         int map_cmp(unordered_map<char,int> &map_s,unordered_map<char,int> &map_p)
//         {
//             for(auto it=map_p.begin();it!=map_p.end();it++)
//             {
//                 if(map_s[it->first]!=it->second)return 0;
//             }
//             return 1;
//         }
//         for(int i=0;i<s.size();i++)
//         {
//             if(i+p.size()>s.size())break;

//             if(map_cmp(map_s,map_p))res.push_back(i);
//             maps[s[i]]--;
//             if(maps[s[i]]==0)maps.erase(s[i]);
//             maps[s[i+p.size()]]++;
            
//         }
//         return res;
//     }
// };
// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         //brute
//         int res=0;
//         for(int i=0;i<nums.size();++i)
//         {
//             int sum=0;
//             for(int j=i;j>=0;--j)
//             {
//                 sum += nums[j];
//                 if(sum==k)res++;
//             }
//         }
//         return res;
//         //hash + presum
//         unordered_map<int, int> mp;
//         mp[0] = 1;//初始化，防止漏掉从头开始的子数组
//         int count = 0, pre = 0;
//         for (auto& x:nums) {
//             pre += x;
//             if (mp.find(pre - k) != mp.end()) {
//                 count += mp[pre - k];
//             }
//             mp[pre]++;
//         }
//         return count;

//     }
// };


// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int> res;
//         // //brute
//         // int max = -1e9,point = 0;
//         // for(int i=0;i<k;i++)
//         // {
//         //     if(nums[i]>=max){max = nums[i];point = i;}
//         // }
//         // res.push_back(max);
//         // for(int i=k;i<nums.size();i++)
//         // {
//         //     if(nums[i] >= max){
//         //         point = i;
//         //         max = nums[i];
//         //     }
//         //     else if(point < i-k+1)
//         //     {
//         //         max = -1e9;
//         //         for(int j=i;j>=i-k+1;j--)
//         //         {
//         //             if(nums[j]>=max){max = nums[j];point = j;}
//         //         }
//         //     }
//         //     res.push_back(max);
//         // }
//         //brute
//         map<int,int> mp;
//         for(int i=0;i<k;i++)
//         {
//             mp[nums[i]] ++;
//         }
//         int max = mp.rbegin()->first;
//         res.push_back(max);
//         for(int i=k;i<nums.size();i++)
//         {
//             mp[nums[i]]++;
//             mp[nums[i-k]]--;
//             if(mp[nums[i-k]]==0)mp.erase(nums[i-k]);
//             max = mp.rbegin()->first;
//             res.push_back(max);
//         }
//         return res;
//     }
// };
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {

//         //dp
//         int res = nums[0];
//         for(int i=1;i<nums.size();i++)
//         {
//             if(nums[i-1]>0)nums[i] += nums[i-1];
//             res = max(res,nums[i]);
//         }
//         return res;
//     }
// };
// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         vector<vector<int>> res;
//         //brute
//         sort(intervals.begin(),intervals.end());
//         for(int i=0;i<intervals.size();i++)
//         {
//             if(res.empty() || res.back()[1] < intervals[i][0])res.push_back(intervals[i]);
//             else res.back()[1] = max(res.back()[1],intervals[i][1]);
//         }
//         return res;
//     }
// };
// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         //翻转
//         reverse(nums.begin(),nums.end());
//         reverse(nums.begin(),nums.begin+k);
//         reverse(nums.begin()+k+1,nums.end());
//     }
// };
// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         vector<int> pre_product(nums.size(),1);
//         vector<int> pro_product(nums.size(),1);
//         vector<int> res;
//         pre_product[0] = nums[0];
//         for(int i=1; i < nums.szie();i++){
//             pre_product[i] = (pre_product[i-1]*nums[i]);
//         }
//         pro_product[0] = nums[nums.size()-1];
//         for(int i=nums.size()-2; i >=0 ; i--){
//             pro_product[i] = (pre_product[i+1]*nums[i]);
//         }
//         for(int i=0; i < nums.size();i++){
//             cout << pre_product[i] << " ";
//         }
//         for(int i=0; i < nums.size();i++){
//             cout << pro_product[i] << " ";
//         }
//         res.push_back(pro_product[1]);
//         for(int i=1; i < nums.szie()-1;i++){
//             res.push_back(pro_product[i+1] * pre_product[i-1]);
//         }
//         res.push_back(pre_product[nums.size()-2]);
//         return res;
//     }
// };
// class Solution {
// public:
//     int firstMissingPositive(vector<int>& nums) {
//         int res = 1,head = 0,tail = nums.size()-1,index = -1;
//         for(int i=0;i<nums.size();i++)
//         {
//             if(nums[i]<=0)nums[i] = -1e9;
//             if(nums[i]>nums.size())nums[i] = -1e9;
//         }
//         for(int i=nums.size()-1;i>=0;i--)
//         {
//             if(nums[i] == -1e9 || nums[i] == 0)continue;
//             else {
//                 int tmp = nums[nums[i]-1];
//                 nums[nums[i]-1] = 0;
//                 nums[i] = -1e9;
//                 while(tmp!=0 && tmp!= -1e9)
//                 {
//                     int tmp2 = nums[tmp-1];
//                     nums[tmp-1] = 0;
//                     tmp = tmp2;
//                 }
//             }
//         }
//         for(int i=0;i<nums.size();i++)
//         {
//             if(nums[i] != 0){
//                 return i+1;
//             }
//         }
//         return nums.size()+1;
//     }
// };
// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         int line = 0,row = 0;

//         for(int i=0;i<m;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 if(matrix[i][j] == 0 && i!=0 && j!=0)
//                 {
//                     matrix[i][0] = 0;
//                     matrix[0][j] = 0;
//                 }
//                 else if(matrix[i][j] == 0 )
//                 {
//                     if(i==0)line = 1;
//                     if(j==0)row = 1;
//                 }
//             }
//         }
//         for(int i=0;i<m;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 cout << matrix[i][j] << " ";
//             }
//             cout << endl;
//         }
//         for(int i=1;i<m;i++)
//         {
//             if(matrix[i][0] == 0)
//             {
//                 for(int j=0;j<n;j++)
//                 {
//                     matrix[i][j] = 0;
//                 }
//             }
//         }
//         for(int j=1;j<n;j++)
//         {
//             if(matrix[0][j] == 0)
//             {
//                 for(int i=0;i<m;i++)
//                 {
//                     matrix[i][j] = 0;
//                 }
//             }
//         }
//         if(matrix[0][0] == 0)
//         {
//             for(int i=0;i<m;i++)
//             {
//                 matrix[i][0] = 0;
//             }
//             for(int j=0;j<n;j++)
//             {
//                 matrix[0][j] = 0;
//             }
//         }
//         if(line == 1)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 matrix[0][j] = 0;
//             }
//         }
//         if(row == 1)
//         {
//             for(int i=0;i<m;i++)
//             {
//                 matrix[i][0] = 0;
//             }
//         }
//         return;

        
//     }
// };
// class Solution {
// public:
//     vector<int> spiralOrder(vector<vector<int>>& matrix) {
//         vector<int> res;
//         int m = matrix.size();
//         int n = matrix[0].size();
//         int head = 0,tail = m-1,left = 0,right = n-1;
//         while(m>0 && n>0)
//         {
//             for(int i=left;i<=right;i++)
//             {
//                 res.push_back(matrix[head][i]);
//             }

//             for(int i=head+1;i<=tail;i++)
//             {
//                 res.push_back(matrix[i][right]);
//             }
//             if(m>1)
//             {
//                 for(int i=right-1;i>=left;i--)
//                 {
//                     res.push_back(matrix[tail][i]);
//                 }
//             }
//             if(n>1)
//             {
//                 for(int i=tail-1;i>=head+1;i--)
//                 {
//                     res.push_back(matrix[i][left]);
//                 }
//             }
//             m -= 2;
//             n -= 2;
//             head++;
//             tail--;
//             left++;
//             right--;
//         }
//         return res;
//     }

// };
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         //使用二分查找
//         if(target < matrix[0][0])return false;
//         int m = matrix.size();
//         int n = matrix[0].size();
//         int left_line = 0,right_line = m-1;
//         int left_row = 0,right_row = n-1;
//         int mid_line = (left_line + right_line) / 2;//目标是找到第一个大于target的行
//         int mid_row = (left_row + right_row) / 2;//目标是找到第一个大于target的列
//         while(left_line <= right_line)
//         {
//             mid_line = (left_line + right_line) / 2;
//             if(matrix[mid_line][0] == target)return true;
//             else if(matrix[mid_line][0] < target)
//             {
//                 left_line = mid_line + 1;
//             }
//             else
//             {
//                 right_line = mid_line - 1;
//             }
//         }
//         while(left_row <= right_row)
//         {
//             mid_row = (left_row + right_row) / 2;
//             if(matrix[right_line][mid_row] == target)return true;
//             else if(matrix[right_line][mid_row] < target)
//             {
//                 left_row = mid_row + 1;
//             }
//             else
//             {
//                 right_row = mid_row - 1;
//             }
//         }
//         for(int i=0;i<mid_line;i++)
//         {
//             //对于i这一行，使用二分查找
//             left_row = 0;
//             right_row = mid_row;
//             while(left_row <= right_row)
//             {
//                 mid_row = (left_row + right_row) / 2;
//                 if(matrix[i][mid_row] == target)return true;
//                 else if(matrix[i][mid_row] < target)
//                 {
//                     left_row = mid_row + 1;
//                 }
//                 else
//                 {
//                     right_row = mid_row - 1;
//                 }
//             }
//         }
//         return false;
//     }
// };


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         int skipA = 0,skipB = 0 ,insect = 0;
//         //走到尾部
//         ListNode *tmpA = headA;
//         ListNode *tmpB = headB;
//         while(tmpA->next != NULL)
//         {
//             tmpA = tmpA->next;
//             skipA++;
//         }
//         while(tmpB->next != NULL)
//         {
//             tmpB = tmpB->next;
//             skipB++;
//         }
//         if(tmpA != tmpB)return NULL;
//         int len_diff = abs(skipA - skipB);
//         if(skipA > skipB)
//         {
//             tmpA = headA;
//             tmpB = headB;
//             for(int i=0;i<len_diff;i++)
//             {
//                 tmpA = tmpA->next;
//             }
//             while(tmpA != tmpB)
//             {
//                 tmpA = tmpA->next;
//                 tmpB = tmpB->next;
//             }
//             return (*tmpA).val;
//         }
//         else
//         {
//             tmpA = headA;
//             tmpB = headB;
//             for(int i=0;i<len_diff;i++)
//             {
//                 tmpB = tmpB->next;
//             }
//             while(tmpA != tmpB)
//             {
//                 tmpA = tmpA->next;
//                 tmpB = tmpB->next;
//             }
//             return 
//         }
        
//     }
// };
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         //迭代
//         ListNode *pre = NULL;
//         ListNode *cur = head;
//         while(cur != NULL)
//         {
//             ListNode *tmp = cur->next;
//             cur->next = pre;
//             pre = cur;
//             cur = tmp;
//         }
//         return pre;
//         //递归
//         if(head == NULL || head->next == NULL)return head;
//         ListNode *p = reverseList(head->next);
//         head->next->next = head;
//         head->next = NULL;
//         return p;
//     }
// };
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         //brute
//         //计算链表长度
//         int len = 0;
//         ListNode *tmp = head;
//         while(tmp != NULL)
//         {
//             len++;
//             tmp = tmp->next;
//         }
//         //翻转前半部分
//         ListNode *pre = NULL;
//         ListNode *cur = head;
//         for(int i=0;i<len/2;i++)
//         {
//             ListNode *tmp = cur->next;
//             cur->next = pre;
//             pre = cur;
//             cur = tmp;
//         }
//         //判断是否回文
//         if(len % 2 == 1)cur = cur->next;
//         while(pre != NULL && cur != NULL)
//         {
//             if(pre->val != cur->val)return false;
//             pre = pre->next;
//             cur = cur->next;
//         }
//         return true;
//         //快慢指针做法，实际上是找到中点，然后翻转后半部分，和brute方法一样
//         ListNode *slow = head;
//         ListNode *fast = head;
//         while(fast != NULL && fast->next != NULL)
//         {
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         if(fast != NULL)slow = slow->next;
//         ListNode *pre = NULL;
//         ListNode *cur = slow;
//         while(cur != NULL)
//         {
//             ListNode *tmp = cur->next;
//             cur->next = pre;
//             pre = cur;
//             cur = tmp;
//         }
//         while(pre != NULL)
//         {
//             if(pre->val != head->val)return false;
//             pre = pre->next;
//             head = head->next;
//         }
//     }
// };
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         ListNode *slow = head;
//         ListNode *fast = head;
//         while(fast != NULL && fast->next != NULL)
//         {
//             slow = slow->next;
//             fast = fast->next->next;
//             if(slow == fast)return true;
//         }
//         return false;
//     }
//     ListNode *detectCycle(ListNode *head) {
//         ListNode *slow = head;
//         ListNode *fast = head;
//         int slowCnt = 0,fastCnt = 0;
//         int flag = 0;
//         while(fast != NULL && fast->next != NULL)
//         {
//             slow = slow->next;
//             slowCnt++;
//             fast = fast->next->next;
//             if(slow == fast)flag = 1;
//         }
//         if(flag == 0)return NULL;
//         ListNode *tmp = head;
//         while(1){
//             int tmpCnt = slowCnt;
//             while(tmpCnt > 0)
//             {
//                 if(tmp == slow)return tmp;
//                 slow = slow->next;
//                 tmpCnt--;
//             }
//             tmp = tmp->next;
//         }
//         return NULL;
//     }
// };
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         ListNode* tmp1 = list1;
//         ListNode* tmp2 = list2;
//         ListNode* tmp = new ListNode(0);
//         ListNode* head = tmp;
//         cout << "head";
//         while(tmp1!=NULL && tmp2!=NULL)
//         {
//             if(tmp1->val>=tmp2->val)
//             {
//                 tmp->val = tmp2->val;
//                 tmp = tmp->next;
//                 tmp2 = tmp2->next;
//             }
//             else
//             {
//                 tmp->val = tmp1->val;
//                 tmp->next = ListNode(0);
//                 tmp = tmp->next;
//                 tmp1 = tmp1->next;
//             }
//         }
//        cout << "head";
//         if(tmp1==NULL)
//         {
//             while(tmp2!=NULL)
//             {
//                 tmp->next = tmp2;
//                 tmp = tmp->next;
//                 tmp2 = tmp2->next;
//             }
//         }
//         else {
//             while(tmp1!=NULL)
//             {
//                 tmp->next = tmp1;
//                 tmp = tmp->next;
//                 tmp1 = tmp1->next;
//             }
//         }
//         cout << "head";
//         return head;
//     }
// };
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         ListNode* res;
//         if(lists.size()==0)return NULL;
//         if(lists.size()==1)return lists[0];
//         int head=0,tail=lists.size()-1;
//         while (tail > 0)
//         {
//         head = 0;
//         while(head < tail)
//         {
//             lists[head] = mergeTwoLists(lists[head],lists[tail]);
//             head++; tail--;
//         }
//         }
//         res = lists[0];
//         return res;
//     }
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         ListNode* tmp1 = list1;
//         ListNode* tmp2 = list2;
//         if(tmp1==NULL)return tmp2;
//         if(tmp2==NULL)return tmp1;
//         ListNode* tmp = new ListNode(0);
//         ListNode* head = tmp;
//         cout << "head";
//         while(tmp1!=NULL && tmp2!=NULL)
//         {
//             if(tmp1->val>=tmp2->val)
//             {
//                 tmp->val = tmp2->val;
//                 tmp->next = new ListNode(0);
//                 tmp = tmp->next;
//                 tmp2 = tmp2->next;
//             }
//             else
//             {
//                 tmp->val = tmp1->val;
//                 tmp->next = new ListNode(0);
//                 tmp = tmp->next;
//                 tmp1 = tmp1->next;
//             }
//         }
//        cout << "head";
//         if(tmp1==NULL)
//         {
//             while(tmp2!=NULL)
//             {
//                 tmp->val = tmp2->val;
//                 tmp2 = tmp2->next;
//                 if(tmp2)
//                 {tmp->next = new ListNode(0);
//                 tmp = tmp->next;}
                
//             }
//         }
//         else {
//             while(tmp1!=NULL)
//             {
//                 tmp->val = tmp1->val;
//                 tmp1 = tmp1->next;
//                 if(tmp1)
//                 {tmp->next = new ListNode(0);
//                 tmp = tmp->next;}
//             }
//         }
//         cout << "head";
//         return head;
//     }
// };
// class LRUCache {
// public:
//     LRUCache(int capacity) {
//         //初始化
//         this->capacity = capacity;
//     }
    
//     int get(int key) {
//         if(cache.find(key) != cache.end())
//         {
//             //把key放到最前面
//             key_list.erase(find(key_list.begin(),key_list.end(),key));
//             key_list.insert(key_list.begin(),key);
//             return cache[key];
//         }
//         else
//         {
//             return -1;
//         }
//     }
    
//     void put(int key, int value) {
//         if(cache.find(key) != cache.end())
//         {
//             cache[key] = value;
//             key_list.insert(key_list.begin(),key);
//         }
//         else
//         {
//             if(cache.size() == capacity)
//             {
//                 int key_out = key_list.back();
//                 key_list.pop_back();
//                 cache.erase(key_out);
//             }
//             cache[key] = value;
//             key_list.insert(key_list.begin(),key);
//         }
//     }
// private:
//     int capacity;
//     map<int,int> cache;
//     vector<int> key_list;
// };


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector <int> res;
//         if(root->left==NULL&&root->right==NULL){
//             res.push_back(root->val);
//             return res;
//         }
//         if(root->left!=NULL){
//             vector<int> tmp = inorderTraversal(root->left);
//             res.insert(res.end(),tmp.begin(),tmp.end());
//         }
//         res.push_back(root->val);
//         if(root->right!=NULL){
//             vector<int> tmp = inorderTraversal(root->right);
//             res.insert(res.end(),tmp.begin(),tmp.end());
//         }
//         return res;
        
//     }
// };
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)return res;
        res[0].push_back(root->val);
        if(!root->left && !root->right)return res;
        vector<TreeNode*> tmp;
        if(root->left)tmp.push_back(root->left);
        if(root->right)tmp.push_back(root->right);
        
    }
};
int main() {
    vector< vector<int> > nums ;
    
    Solution s;
    s.setZeroes(nums);
    return 0;
}