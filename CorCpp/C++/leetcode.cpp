#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <iostream>

using namespace std;


// class Solution {
// public:
//     long long longestConsecutive(vector<long long>& nums) {
//         struct Node {
//             long long exist;
//             long long max_len;
//         };
//         unordered_map<long long, Node> map;
//         // long long max = -1e9;
//         // for (long long i = 0; i < nums.size(); i++) {
//         //     if (max < nums[i]) {
//         //         max = nums[i];
//         //     }
//         // }
//         // cout << "max: " << max << endl;
//         // cout << map[1].exist << endl;
//         // cout << map[1].max_len << endl;
//         long long max_len = 0;
//         for (long long i = 0; i < nums.size(); i++) {
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
//     void moveZeroes(vector<long long>& nums) {
//         long long head = 0;
//         long long tail = nums.size() - 1;
//         long long num_zero = 0;
//         for (long long i = 0; i < nums.size(); i++) {
//             if (nums[i] == 0) {
//                 num_zero++;
//                 continue;
//             }
//             else {
//                 nums[head] = nums[i];
//                 head++;
//             }
//         }
//         for (long long i = 0; i < num_zero; i++) {
//             nums[tail] = 0;
//             tail--;
//         }
//         // cout << "num_zero: " << num_zero << endl;
//         // for (long long i = 0; i < nums.size(); i++) {
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
//     long long trap(vector<long long>& height) {
//         //brute
//         // long long sum = 0,index = 0;
//         // long long head = 0,tail = height.size() - 1;
//         // while(head < tail) {
//         //     index++;
//         //     while(height[head] < index && head < tail) head++;
//         //     while(height[tail]<index && head < tail)tail--;
//         //     for(long long i=head;i<tail;i++)
//         //     {
//         //         if(height[i]<index)sum++;
//         //     }
//         //     if(tail-head<=1)break;
//         // }
//         // return sum;
//         //better
//         long long head = 0, tail = height.size() - 1,sum = 0;
//         while(height[head]==0) head++;
//         while(height[tail]==0)tail--;
//         long long index;
//         while(head < tail){
//             long long tmp_sum = 0;
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
//             for(long long i = head+1;i<tail;i++){
//                 sum += height_all - height[i];
//             }
//             return sum;
//         }
//         while(head < tail){
//             long long tmp_sum = 0;
//             long long index = tail-1;
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
//     vector<long long> findAnagrams(string s, string p) {
//         //brute,too slow
//         // for(long long i=0;i<s.size();i++)
//         // {
//         //     if(i+p.size()>s.size())break;
//         //     string tmp = s.substr(i,p.size());

//         //     sort(tmp.begin(),tmp.end());

//         //     sort(p.begin(),p.end());

//         //     if(tmp==p)res.push_back(i);
//         // }
//         vector<long long> res;
//         unordered_map<char,long long> map_s,map_p;
//         for(long long i=0;i<p.size();i++)
//         {
//             map_p[p[i]]++;
//             map_s[s[i]]++;
//         }
//         long long map_cmp(unordered_map<char,long long> &map_s,unordered_map<char,long long> &map_p)
//         {
//             for(auto it=map_p.begin();it!=map_p.end();it++)
//             {
//                 if(map_s[it->first]!=it->second)return 0;
//             }
//             return 1;
//         }
//         for(long long i=0;i<s.size();i++)
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
//     long long subarraySum(vector<long long>& nums, long long k) {
//         //brute
//         long long res=0;
//         for(long long i=0;i<nums.size();++i)
//         {
//             long long sum=0;
//             for(long long j=i;j>=0;--j)
//             {
//                 sum += nums[j];
//                 if(sum==k)res++;
//             }
//         }
//         return res;
//         //hash + presum
//         unordered_map<long long, long long> mp;
//         mp[0] = 1;//初始化，防止漏掉从头开始的子数组
//         long long count = 0, pre = 0;
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
//     vector<long long> maxSlidingWindow(vector<long long>& nums, long long k) {
//         vector<long long> res;
//         // //brute
//         // long long max = -1e9,polong long = 0;
//         // for(long long i=0;i<k;i++)
//         // {
//         //     if(nums[i]>=max){max = nums[i];polong long = i;}
//         // }
//         // res.push_back(max);
//         // for(long long i=k;i<nums.size();i++)
//         // {
//         //     if(nums[i] >= max){
//         //         polong long = i;
//         //         max = nums[i];
//         //     }
//         //     else if(polong long < i-k+1)
//         //     {
//         //         max = -1e9;
//         //         for(long long j=i;j>=i-k+1;j--)
//         //         {
//         //             if(nums[j]>=max){max = nums[j];polong long = j;}
//         //         }
//         //     }
//         //     res.push_back(max);
//         // }
//         //brute
//         map<long long,long long> mp;
//         for(long long i=0;i<k;i++)
//         {
//             mp[nums[i]] ++;
//         }
//         long long max = mp.rbegin()->first;
//         res.push_back(max);
//         for(long long i=k;i<nums.size();i++)
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
//     long long maxSubArray(vector<long long>& nums) {

//         //dp
//         long long res = nums[0];
//         for(long long i=1;i<nums.size();i++)
//         {
//             if(nums[i-1]>0)nums[i] += nums[i-1];
//             res = max(res,nums[i]);
//         }
//         return res;
//     }
// };
// class Solution {
// public:
//     vector<vector<long long>> merge(vector<vector<long long>>& long longervals) {
//         vector<vector<long long>> res;
//         //brute
//         sort(long longervals.begin(),long longervals.end());
//         for(long long i=0;i<long longervals.size();i++)
//         {
//             if(res.empty() || res.back()[1] < long longervals[i][0])res.push_back(long longervals[i]);
//             else res.back()[1] = max(res.back()[1],long longervals[i][1]);
//         }
//         return res;
//     }
// };
// class Solution {
// public:
//     void rotate(vector<long long>& nums, long long k) {
//         //翻转
//         reverse(nums.begin(),nums.end());
//         reverse(nums.begin(),nums.begin+k);
//         reverse(nums.begin()+k+1,nums.end());
//     }
// };
// class Solution {
// public:
//     vector<long long> productExceptSelf(vector<long long>& nums) {
//         vector<long long> pre_product(nums.size(),1);
//         vector<long long> pro_product(nums.size(),1);
//         vector<long long> res;
//         pre_product[0] = nums[0];
//         for(long long i=1; i < nums.szie();i++){
//             pre_product[i] = (pre_product[i-1]*nums[i]);
//         }
//         pro_product[0] = nums[nums.size()-1];
//         for(long long i=nums.size()-2; i >=0 ; i--){
//             pro_product[i] = (pre_product[i+1]*nums[i]);
//         }
//         for(long long i=0; i < nums.size();i++){
//             cout << pre_product[i] << " ";
//         }
//         for(long long i=0; i < nums.size();i++){
//             cout << pro_product[i] << " ";
//         }
//         res.push_back(pro_product[1]);
//         for(long long i=1; i < nums.szie()-1;i++){
//             res.push_back(pro_product[i+1] * pre_product[i-1]);
//         }
//         res.push_back(pre_product[nums.size()-2]);
//         return res;
//     }
// };
// class Solution {
// public:
//     long long firstMissingPositive(vector<long long>& nums) {
//         long long res = 1,head = 0,tail = nums.size()-1,index = -1;
//         for(long long i=0;i<nums.size();i++)
//         {
//             if(nums[i]<=0)nums[i] = -1e9;
//             if(nums[i]>nums.size())nums[i] = -1e9;
//         }
//         for(long long i=nums.size()-1;i>=0;i--)
//         {
//             if(nums[i] == -1e9 || nums[i] == 0)continue;
//             else {
//                 long long tmp = nums[nums[i]-1];
//                 nums[nums[i]-1] = 0;
//                 nums[i] = -1e9;
//                 while(tmp!=0 && tmp!= -1e9)
//                 {
//                     long long tmp2 = nums[tmp-1];
//                     nums[tmp-1] = 0;
//                     tmp = tmp2;
//                 }
//             }
//         }
//         for(long long i=0;i<nums.size();i++)
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
//     void setZeroes(vector<vector<long long>>& matrix) {
//         long long m = matrix.size();
//         long long n = matrix[0].size();
//         long long line = 0,row = 0;

//         for(long long i=0;i<m;i++)
//         {
//             for(long long j=0;j<n;j++)
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
//         for(long long i=0;i<m;i++)
//         {
//             for(long long j=0;j<n;j++)
//             {
//                 cout << matrix[i][j] << " ";
//             }
//             cout << endl;
//         }
//         for(long long i=1;i<m;i++)
//         {
//             if(matrix[i][0] == 0)
//             {
//                 for(long long j=0;j<n;j++)
//                 {
//                     matrix[i][j] = 0;
//                 }
//             }
//         }
//         for(long long j=1;j<n;j++)
//         {
//             if(matrix[0][j] == 0)
//             {
//                 for(long long i=0;i<m;i++)
//                 {
//                     matrix[i][j] = 0;
//                 }
//             }
//         }
//         if(matrix[0][0] == 0)
//         {
//             for(long long i=0;i<m;i++)
//             {
//                 matrix[i][0] = 0;
//             }
//             for(long long j=0;j<n;j++)
//             {
//                 matrix[0][j] = 0;
//             }
//         }
//         if(line == 1)
//         {
//             for(long long j=0;j<n;j++)
//             {
//                 matrix[0][j] = 0;
//             }
//         }
//         if(row == 1)
//         {
//             for(long long i=0;i<m;i++)
//             {
//                 matrix[i][0] = 0;
//             }
//         }
//         return;

        
//     }
// };
// class Solution {
// public:
//     vector<long long> spiralOrder(vector<vector<long long>>& matrix) {
//         vector<long long> res;
//         long long m = matrix.size();
//         long long n = matrix[0].size();
//         long long head = 0,tail = m-1,left = 0,right = n-1;
//         while(m>0 && n>0)
//         {
//             for(long long i=left;i<=right;i++)
//             {
//                 res.push_back(matrix[head][i]);
//             }

//             for(long long i=head+1;i<=tail;i++)
//             {
//                 res.push_back(matrix[i][right]);
//             }
//             if(m>1)
//             {
//                 for(long long i=right-1;i>=left;i--)
//                 {
//                     res.push_back(matrix[tail][i]);
//                 }
//             }
//             if(n>1)
//             {
//                 for(long long i=tail-1;i>=head+1;i--)
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
//     bool searchMatrix(vector<vector<long long>>& matrix, long long target) {
//         //使用二分查找
//         if(target < matrix[0][0])return false;
//         long long m = matrix.size();
//         long long n = matrix[0].size();
//         long long left_line = 0,right_line = m-1;
//         long long left_row = 0,right_row = n-1;
//         long long mid_line = (left_line + right_line) / 2;//目标是找到第一个大于target的行
//         long long mid_row = (left_row + right_row) / 2;//目标是找到第一个大于target的列
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
//         for(long long i=0;i<mid_line;i++)
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
 *     long long val;
 *     ListNode *next;
 *     ListNode(long long x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     ListNode *getlong longersectionNode(ListNode *headA, ListNode *headB) {
//         long long skipA = 0,skipB = 0 ,insect = 0;
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
//         long long len_diff = abs(skipA - skipB);
//         if(skipA > skipB)
//         {
//             tmpA = headA;
//             tmpB = headB;
//             for(long long i=0;i<len_diff;i++)
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
//             for(long long i=0;i<len_diff;i++)
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
 *     long long val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(long long x) : val(x), next(nullptr) {}
 *     ListNode(long long x, ListNode *next) : val(x), next(next) {}
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
 *     long long val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(long long x) : val(x), next(nullptr) {}
 *     ListNode(long long x, ListNode *next) : val(x), next(next) {}
 * };
 */
// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         //brute
//         //计算链表长度
//         long long len = 0;
//         ListNode *tmp = head;
//         while(tmp != NULL)
//         {
//             len++;
//             tmp = tmp->next;
//         }
//         //翻转前半部分
//         ListNode *pre = NULL;
//         ListNode *cur = head;
//         for(long long i=0;i<len/2;i++)
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
 *     long long val;
 *     ListNode *next;
 *     ListNode(long long x) : val(x), next(NULL) {}
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
//         long long slowCnt = 0,fastCnt = 0;
//         long long flag = 0;
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
//             long long tmpCnt = slowCnt;
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
 *     long long val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(long long x) : val(x), next(nullptr) {}
 *     ListNode(long long x, ListNode *next) : val(x), next(next) {}
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
 *     long long val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(long long x) : val(x), next(nullptr) {}
 *     ListNode(long long x, ListNode *next) : val(x), next(next) {}
 * };
 */
// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         ListNode* res;
//         if(lists.size()==0)return NULL;
//         if(lists.size()==1)return lists[0];
//         long long head=0,tail=lists.size()-1;
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
//     LRUCache(long long capacity) {
//         //初始化
//         this->capacity = capacity;
//     }
    
//     long long get(long long key) {
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
    
//     void put(long long key, long long value) {
//         if(cache.find(key) != cache.end())
//         {
//             cache[key] = value;
//             key_list.insert(key_list.begin(),key);
//         }
//         else
//         {
//             if(cache.size() == capacity)
//             {
//                 long long key_out = key_list.back();
//                 key_list.pop_back();
//                 cache.erase(key_out);
//             }
//             cache[key] = value;
//             key_list.insert(key_list.begin(),key);
//         }
//     }
// private:
//     long long capacity;
//     map<long long,long long> cache;
//     vector<long long> key_list;
// };


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * long long param_1 = obj->get(key);
 * obj->put(key,value);
 */

// class Solution {
// public:
//     vector<long long> inorderTraversal(TreeNode* root) {
//         vector <long long> res;
//         if(root->left==NULL&&root->right==NULL){
//             res.push_back(root->val);
//             return res;
//         }
//         if(root->left!=NULL){
//             vector<long long> tmp = inorderTraversal(root->left);
//             res.insert(res.end(),tmp.begin(),tmp.end());
//         }
//         res.push_back(root->val);
//         if(root->right!=NULL){
//             vector<long long> tmp = inorderTraversal(root->right);
//             res.insert(res.end(),tmp.begin(),tmp.end());
//         }
//         return res;
        
//     }
// };
// class Solution {
// public:
//     vector<vector<long long>> levelOrder(TreeNode* root) {
//         vector<vector<long long>> res;
//         if(!root)return res;
//         vector<long long> tmp;
//         tmp.push_back(root->val);
//         res.push_back(tmp);

//         long long height = 0,head = 0,tail = 0;
//         if(!root->left && !root->right)return res;

//         vector<TreeNode*> tmp;
//         //思路： 用一个队列来存储每一层的节点，然后遍历这个队列，将每个节点的值存储到res中，然后将这个节点的左右节点存储到tmp中
//         tmp.push_back(root->left);
//         tmp.push_back(root->right);
//         tail = 1;
//         while(head <= tail)
//         {
//             vector<long long> tmp_res;
//             for(long long i=head;i<=tail;i++)
//             {
//                 if(tmp[i]->left)tmp.push_back(tmp[i]->left);
//                 if(tmp[i]->right)tmp.push_back(tmp[i]->right);
//                 tmp_res.push_back(tmp[i]->val);
//             }
//             res.push_back(tmp_res);
//             head = tail + 1;
//             tail = tmp.size() - 1;
//         }
//         return res;
//     }
// };
// class Solution {
// public:
//     TreeNode* sortedArrayToBST(vector<long long>& nums) {
//         long long len = nums.size();
//         if(len == 0)return NULL;
//         if(len == 1)return new TreeNode(nums[0]);
//         TreeNode* root = new TreeNode(nums[len/2]);
//         vector<long long> left(nums.begin(),nums.begin()+len/2);
//         vector<long long> right(nums.begin()+len/2+1,nums.end());
//         root->left = sortedArrayToBST(left);
//         root->right = sortedArrayToBST(right);
//         return root;
//     }
// };
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     long long val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:
//     struct Node{
//         TreeNode * head;
//         TreeNode * tail;
//     };
//     void flatten(TreeNode* root) {
//         root = preorder(root).head;
//         return;
//     }
//     Node preorder(TreeNode*root){
//         if(!root || (!root->left&&!root->right)){
//             Node n ;
//             n.head = root;
//             n.tail = root;
//             return n;
//         }
//         if(!root->left){
//             Node tmp = preorder(root->right);
//             Node n ;
//             n.head = root;
//             n.tail = tmp.tail;
//             return n;
//         }
//         if(!root->right){
//             Node tmp = preorder(root->left);
//             root->left = NULL;
//             root->right = tmp.head;
//             Node n ;
//             n.head = root;
//             n.tail = tmp.tail;
//             return n;
//         }
//         Node tmp = preorder(root->left);
//         TreeNode* left_head = tmp.head;
//         TreeNode* left_tail = tmp.tail;
//         tmp = preorder(root->right);
//         TreeNode* right_head = tmp.head;
//         TreeNode* right_tail = tmp.tail;
//         root->left = NULL;
//         root->right = left_head;
//         left_tail->right = right_head;
//         Node n ;
//         n.head = root;
//         n.tail = right_tail;
//         return n;
//     }
// };
// class Solution {
// public:
//     TreeNode* buildTree(vector<long long>& preorder, vector<long long>& inorder) {
//         TreeNode* root = new TreeNode();
//         root->val = preorder[0];
//         if(preorder.size() == 1)return root;
//         long long index;
//         for(long long i=0;i<inorder.size();i++)
//         {
//             if(inorder[i] == preorder[0]){
//                 index = i;
//                 break;
//             }
//         }
//         vector <long long> left_p,left_i,right_p,right_i;
//         left_p.insert(left_p.begin(),preorder.begin()+1,preorder.begin()+index+1);
//         left_i.insert(left_i.begin(),inorder.begin(),inorder.begin()+index);
//         for(long long i=0;i<left_p.size();i++)
//         {
//             cout << left_p[i] << " ";
//         }cout << endl;
//         for(long long i=0;i<left_i.size();i++)
//         {
//             cout << left_i[i] << " ";
//         }cout << endl;
//         TreeNode* leftT = buildTree(left_p,left_i);
//         right_i.insert(right_i.begin(),preorder.begin()+index+1,preorder.end());
//         right_p.insert(right_p.begin(),inorder.begin()+index+1,inorder.end());
//         for(long long i=0;i<right_p.size();i++)
//         {
//             cout << right_p[i] << " ";
//         }cout << endl;
//         for(long long i=0;i<right_i.size();i++)
//         {
//             cout << right_i[i] << " ";
//         }cout << endl;
//         TreeNode* rightT = buildTree(right_p,right_i);
//         root->left = leftT;
//         root->right = rightT;
//         return root;

//     }
// };
// class Solution {
// public:
//     long long pathSum(TreeNode* root, long long targetSum) {
//         if(root==NULL)return 0;
//         vector<long long> tmp;
//         if(root->left==NULL&&root->right==NULL){
//             if(root->val==targetSum)return 1;
//             else return 0;
//         }
//         long long lef=0,rig=0;
//         if(root->left!=NULL){
//             lef = pathSum(root->left,targetSum);
//         }
//         if(root->right!=NULL){
//             rig = pathSum(root->right,targetSum);
//         }
//         return lef+rig + check(root,root->val,targetSum);
//     }
//     long long check(TreeNode* root,long long sum,long long target)
//     {
//         long long res = (sum==target)?1:0;
//         if(root->left==NULL&&root->right==NULL){
//             if(sum==target)return 1;
//             else return 0;
//         }
//         if(root->left!=NULL){
//             res += check(root->left,sum+root->left->val,target);
//         }
//         if(root->right!=NULL){
//             res += check(root->right,sum+root->right->val,target);
//         }
//         return res;
//     }
// };
// class Solution {
// int maxsum;
// public:
//     int maxPathSum(TreeNode* root) {
        
//         if(!root)return 0;
//         maxsum = root->val;
//         int sum = findMaxLine(root->left) + findMaxLine(root->right) + root->val;
//         return sum;
//     }
    
//     int findMaxLine(TreeNode* root)
//     {
//         if(!root)return 0;
//         if(!root->left && ! root->right)return max(root->val,0);
//         return max((max(findMaxLine(root->left),findMaxLine(root->right)) + root->val),0);
//     }
// };
// class Solution {
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         int res = 0;
//         int line = grid.size(),row = grid[0].size();
//         for(int i=0;i<line;i++)
//         {
//             for(int j=0;j<row;j++)
//             {
//                 if(grid[i][j]=='0')continue;
//                 else if(grid[i][j] == '1')
//                 {
//                     res ++;
//                     dfs(grid,i,j);
//                 }
//             }
//         }
//         return res;
//     }
//     void dfs(vector<vector<char>>& grid,int i,int j)
//     {
//         if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size())return;
//         if(grid[i][j] == '0')return;
//         grid[i][j] = '0';
//         dfs(grid,i+1,j);
//         dfs(grid,i-1,j);
//         dfs(grid,i,j+1);
//         dfs(grid,i,j-1);
//     }
// };
// class Solution {
// public:
//     int orangesRotting(vector<vector<int>>& grid) {
//         int res = 0;
//         int line = grid.size(),row = grid[0].size();
//         queue<pair<int,int>> q;
//         for(int i=0;i<line;i++)
//         {
//             for(int j=0;j<row;j++)
//             {
//                 if(grid[i][j] == 2)q.push(make_pair(i,j));
//             }
//         }
//         while(!q.empty())
//         {
//             int size = q.size();
//             for(int i=0;i<size;i++)
//             {
//                 pair<int,int> tmp = q.front();
//                 q.pop();
//                 int x = tmp.first;
//                 int y = tmp.second;
//                 if(x-1>=0 && grid[x-1][y] == 1)
//                 {
//                     grid[x-1][y] = 2;
//                     q.push(make_pair(x-1,y));
//                 }
//                 if(x+1<line && grid[x+1][y] == 1)
//                 {
//                     grid[x+1][y] = 2;
//                     q.push(make_pair(x+1,y));
//                 }
//                 if(y-1>=0 && grid[x][y-1] == 1)
//                 {
//                     grid[x][y-1] = 2;
//                     q.push(make_pair(x,y-1));
//                 }
//                 if(y+1<row && grid[x][y+1] == 1)
//                 {
//                     grid[x][y+1] = 2;
//                     q.push(make_pair(x,y+1));
//                 }
//             }
//             res++;
//         }
//         for(int i=0;i<line;i++)
//         {
//             for(int j=0;j<row;j++)
//             {
//                 if(grid[i][j] == 1)return -1;
//             }
//         }
//         return res;
//     }
// };
// class Solution {
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // vector<int> canFinished(numCourses,-1);
        // vector< vector <int > > graph (numCourses,vector<int>(numCourses,0));
        // for(int i=0;i<prerequisites.size();i++)
        // {
        //     graph[prerequisites[i][0]][prerequisites[i][1]] = 1;
        // }
        // for(int i=0;i<numCourses;i++)
        // {
        //     for(int j=0;j<numCourses;j++)
        //     {
        //         cout << graph[i][j] << " ";
        //     }cout << endl;
        // }
        // queue<int> q;
        // //将所有入度为0的节点放入队列
        // for(int i=0;i<numCourses;i++)
        // {
        //     int flag = 0;
        //     for(int j=0;j<numCourses;j++)
        //     {
        //         if(graph[j][i] == 1)
        //         {
        //             flag = 1;
        //             break;
        //         }
        //     }
        //     if(flag == 0)q.push(i);
        // }

        // while(q.size())
        // {
        //     int tmp = q.front();
        //     q.pop();
        //     canFinished[tmp] = 1;
        //     for(int i=0;i<numCourses;i++)
        //     {
        //         if(graph[tmp][i] == 1)
        //         {
        //             graph[tmp][i] = 0;
        //             int flag = 0;
        //             for(int j=0;j<numCourses;j++)
        //             {
        //                 if(graph[j][i] == 1)
        //                 {
        //                     flag = 1;
        //                     break;
        //                 }
        //             }
        //             if(flag == 0)q.push(i);
        //         }
        //     }
        // }
        // for(int i=0;i<numCourses;i++)
        // {
        //     if(canFinished[i] == -1)return false;
       
        // }
        // return true;
//         vector< vector<int> > graph(numCourses,vector<int>());
//         unordered_map<int,int> indegree;
//         for(int i=0;i<prerequisites.size();i++)
//         {
//             graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
//             indegree[prerequisites[i][0]]++;
//         }
//         queue<int> q;
//         for(int i=0;i<numCourses;i++)
//         {
//             if(indegree[i] == 0)q.push(i);
//         }
//         while(q.size())
//         {
//             int tmp = q.front();
//             q.pop();
//             numCourses--;
//             for(int i=0;i<graph[tmp].size();i++)
//             {
//                 indegree[graph[tmp][i]]--;
//                 if(indegree[graph[tmp][i]] == 0)q.push(graph[tmp][i]);
//             }
//         }
//         return numCourses == 0;
//     }
// };

// class Trie {
// private:
//     bool isEnd;
//     Trie * nextT[26];
// public:
//     Trie() {
//         isEnd = true ;
//         for(int i=0;i<26;i++)
//         {
//             nextT[i] = NULL;
//         }
//     }
    
//     void insert(string word) {
//         this->isEnd = false;
//         Trie * tmp = this;
//         for(int i=0;i<word.size();i++)
//         {
//             if(tmp->nextT[word[i]-'a'] == NULL)
//             {
//                 tmp->nextT[word[i]-'a'] = new Trie();
//             }
//             tmp = tmp->nextT[word[i]-'a'];
//         }
//         tmp->isEnd = true;
//     }
    
//     bool search(string word) {
//         while(word.size())
//         {
//             if(this->nextT[word[0]-'a'] == NULL)return false;
//             this = this->nextT[word[0]-'a'];
//             word = word.substr(1);
//         }
//         return this->isEnd;
//     }
    
//     bool startsWith(string prefix) {
//         if(search(prefix))return true;
//         while(prefix.size())
//         {
//             if(this->nextT[prefix[0]-'a'] == NULL)return false;
//             this = this->nextT[prefix[0]-'a'];
//             prefix = prefix.substr(1);
//         }
//         return true;
//     }
// };


// /**
//  * Your Trie object will be instantiated and called as such:
//  * Trie* obj = new Trie();
//  * obj->insert(word);
//  * bool param_2 = obj->search(word);
//  * bool param_3 = obj->startsWith(prefix);
//  */


// class Solution {
// public:
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         //将candidates从大到小排序
//         sort(candidates.begin(),candidates.end(),greater<int>());
//         vector <vector<int>> res;
//         vector <int> tmp;
//         backtracking(res,tmp,candidates,0,0,target);
//     }
//     void backtracking(vector<vector<int>> & res,vector<int> &tmp,vector<int> &candidates,int index,int sum,int target)
//     {
//         if(index == candidates.size())return;
//         if(sum == target && find(res.begin(),res.end(),tmp) == res.end())
//         {
//             res.push_back(tmp);
//             return;
//         }
//         int tmp_sum = sum;
//         for(int i=index;i<nums.size();i++){          
//             if(tmp_sum + nums[i] > target)continue;
//             while(tmp_sum + nums[i] <= target)
//             {
//                 tmp.push_back(nums[i]);
//                 tmp_sum += nums[i];
//                 backtracking(res,tmp,nums,i,tmp_sum,target);
//             }
//             int n = (tmp_sum - sum)/nums[i];
//             for(int j=0;j<n;j++)
//             {
//                 tmp.pop_back();
//             }
//             tmp_sum = sum;
//         }
//     }

    
// };
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double res;
        int head1 = 0,head2 = 0, tail1 = nums1.size()-1,tail2 = nums2.size()-1;
        if(!nums1.size())
        {
            if(nums2.size()%2 == 0)
            {
                res = (nums2[nums2.size()/2]+nums2[nums2.size()/2-1])*1.0/2;
            }
            else
            {
                res = nums2[nums2.size()/2];
            }
            return res;
        }
        if(!nums2.size())
        {
            if(nums1.size()%2 == 0)
            {
                res = (nums1[nums1.size()/2]+nums1[nums1.size()/2-1])*1.0/2;
            }
            else
            {
                res = nums1[nums1.size()/2];
            }
            return res;
        }
        int middle = (tail1+tail2+2)/2;
        int evenOrodd = (tail1+tail2+2)%2;
        int mid1 = middle / 2;
        int mid2 = middle / 2;
        cout << middle << " " << evenOrodd << endl;
        while(1)
        {
            //若数组为空
            cout << head1 << " " << tail1 << " " << head2 << " " << tail2 << " " << mid1 << " " << mid2 << " " << middle << endl;
            if(mid1 > tail1){mid1 = tail1;middle = middle-tail1;}
            else if(mid2 > tail2){mid2 = tail2;middle = middle-tail2;}
            else middle = middle - mid1;
            int num1 = nums1[mid1];
            int num2 = nums2[mid2];
            if(num1<num2)
            {
                head1 = mid1;
            }
            else
            {
                head2 = mid2;
            }
            mid1 = head1 + middle / 2;
            mid2 = head2 + middle / 2;
            if(middle == 1)
            {
                if(evenOrodd == 0)
                {
                    cout << mid1 << " " << mid2 << endl;
                    res = (nums1[mid1]+nums2[mid2])*1.0/2;
                }
                else
                {
                    res = max(nums1[mid1],nums2[mid2]);
                }
                break;
            }
        }
        return res;
    }
};
int  main() {
    vector< int > nums1;
    vector< int > nums2;
    nums1.push_back(1); nums1.push_back(2);
    nums2.push_back(3); nums2.push_back(4);
    
    Solution s;
    cout << s.findMedianSortedArrays(nums1,nums2) << endl;
    return 0;
}
// class MinStack {
// public:
//     MinStack() {
//         capacity = 0;
//         min_value = INT_MAX;
//         index_min = -1;
//     }

//     void push(int val) {
//         stack.push_back(val);
//         capacity++;
//         if(val < min_value)
//         {
//             min_value = val;
//             index_min = capacity-1;
//         }
//     }

//     void pop() {
//         if(capacity == 0)return;
//         if(index_min == capacity-1)
//         {
//             min_value = INT_MAX;
//             for(int i=0;i<capacity-1;i++)
//             {
//                 if(stack[i] < min_value)
//                 {
//                     min_value = stack[i];
//                     index_min = i;
//                 }
//             }
//         }
//         stack.pop_back();
//         capacity--;
//     }

//     int top() {
//         return stack[capacity-1];
//     }

//     int getMin() {
//         return min_value;
//     }

// private:
// int capacity;
// int min_value;
// int index_min;
// vector <int> stack;

// };

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

class Solution {
public:
    string decodeString(string s) {
        string res,tmp;
        

        int num = 0;
        for(int i=0;i<s.size();)
        {

            int x = s[i]-'0';
            cout << x << endl;
            if(x>0&&x<=9){
                tmp = decode_inside(s,i);
                res += tmp;
            }
            else if(s[i]!=']')
            {
                res+=s[i];
                i++;
            }
        }
        return res;
    }
    bool Is_Alpha(char c)
    {
        if(c>='a'&&c<='z')return true;
        if(c>='A'&&c<='Z')return true;
        return false;
    }
    string decode_inside(string s,int &index)//找到括号内的字符串并返回
    {
        string res;
        //找到数字
        int num = 0;
        while(s[index]>='0'&&s[index]<='9')
        {
            num = num*10 + s[index]-'0';
            index++;
        }
        //找到左括号
        cout << index << "index " << endl;
        while(s[index]!='[')
        {
            index++;
        }
        string tmp;
        for (int i = index+1; i < s.size();)
        {
            if(s[i] >= '0' && s[i] <= '9'){
                tmp += decode_inside(s,i);
            }
            if(s[i] == ']')
            {
                index = i+1;
                break;
            }
            //如果是字母
            if(Is_Alpha(s[i]))
            {
                tmp += s[i];
                i++;
            }
        }
        while(num--)
        {
            res+=tmp;
        }
        return res;

    }
};


// class Solution {
// public:
//     bool exist(vector<vector<char>>& board, string word) {
//         vector<vector<bool> > chech_board(board.size(),vector<bool>(board[0].size(),false));
//         for(int i=0;i<board.size();i++)
//         {
//             for(int j=0;j<board[0].size();j++)
//             {
//                 if(board[i][j] == word[0])
//                 {
//                     if(back_tracking(i,j,board,chech_board,word,0))return true;
//                 }
//             }
//         }
//         return false;
//     }
//     bool back_tracking(int x,int y,vector<vector<char>>& board,vector<vector<bool> > &chech_board,string word,int index)
//     {
//         if(word.size() == index)return true;
//         //检查是否越界
//         if(x<0 || x>=board.size() || y<0 || y>=board[0].size())return false;
//         //检查是否已经访问过
//         if(chech_board[x][y])return false;
//         //检查是否匹配
//         if(board[x][y] != word[index])return false;
//         chech_board[x][y] = true;
//         //向四个方向搜索
//         if(back_tracking(x+1,y,board,chech_board,word,index+1))return true;
//         if(back_tracking(x-1,y,board,chech_board,word,index+1))return true;
//         if(back_tracking(x,y+1,board,chech_board,word,index+1))return true;
//         if(back_tracking(x,y-1,board,chech_board,word,index+1))return true;
//         chech_board[x][y] = false;
//     }
// };

// class Solution {
// public:
//     vector<vector<string>> partition(string s) {
//         vector<vector<string>> res;
//         vector<string> tmp;
//         back_tracking(res,tmp,s,0);
//         return res;
//     }
//     void back_tracking(vector<vector<string>> &res,vector<string> &tmp,string s,int index)
//     {
//         if(index == s.size()){
//             res.push_back(tmp);
//             return;
//         }
//         for(int i=index;i<s.size();i++)
//         {
//             if(check_if_palindrome(s,index,i))
//             {
//                 tmp.push_back(s.substr(index,i-index+1));
//                 back_tracking(res,tmp,s,i+1);
//                 tmp.pop_back();
//             }
//         }
//     }
//     bool check_if_palindrome(string s,int left,int right)
//     {
//         while(left<right)
//         {
//             if(s[left] != s[right])return false;
//             left++;right--;
//         }
//         return true;
//     }
// };

// class Solution {
// public:
//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string> >res;
//         vector<vector<int> > check_board(n,vector<int>(n,0));
//         //设置固定长度为n的string
//         string tmp_str(n,'.');
//         vector<string>tmp(n,tmp_str);
//         back_tracking(res,tmp,check_board,n,0);
//         return res;
//     }
//     void back_tracking(vector<vector<string>>& res,vector<string>&tmp,vector<vector<int> &check_board,int n,int index){
//         if(index == n)
//         {
//             res.push_back(tmp);
//             return;
//         }
//         for(int i=0;i<n;i++)
//         {
//             if(check_board[index][i] == 0)
//             {
//                 tmp[index][i] = 'Q';
//                 check_board[index][i] = 1;
//                 //检查是否冲突  
//                 if(check_conflict(check_board,index,i,n))
//                 {
//                     back_tracking(res,tmp,check_board,n,index+1);
//                 }
//                 check_board[index][i] = 0;
//                 tmp[index][i] = '.';
//             }
//         }
        
//     }
//     bool check_conflict(vector<vector<int> > &check_board,int x,int y,int n)
//     {
//         //检查行
//         for(int i=0;i<n;i++)
//         {
//             if(check_board[x][i] == 1)return false;
//         }
//         //检查列
//         for(int i=0;i<n;i++)
//         {
//             if(check_board[i][y] == 1)return false;
//         }
//         //检查对角线
//         for(int i=0;i<n;i++)
//         {
//             if(x+i<n && y+i<n && check_board[x+i][y+i] == 1)return false;
//         }
//         for(int i=0;i<n;i++)
//         {
//             if(x+i<n && y-i>=0 && check_board[x+i][y-i] == 1)return false;
//         }
//         for(int i=0;i<n;i++)
//         {
//             if(x-i>=0 && y-i>=0 && check_board[x-i][y-i] == 1)return false;
//         }
//         for(int i=0;i<n;i++)
//         {
//             if(x-i>=0 && y+i<n && check_board[x-i][y+i] == 1)return false;
//         }
//         return true;
//     }
// };

// class Solution {
// public:
//     int climbStairs(int n) {
//         int res;
//         vector<int> ways(n,0);
//         ways[0] = 1;
//         ways[1] = 2;
//         if(n==1)return 1;
//         if(n==2)return 2;
//         for(int i=2;i<n;i++)
//         {
//             ways[i] = ways[i-1]+ways[i-2];
//         }
//         return ways[n-1];
//     }
// };
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int length = s.size();
        vector<bool> Is_word_breakful(length,0);
        for(int i=length-1;i>=0;i++)
        {
            for(int j=0;j<wordDict.size();j++)
            {
                if(wordDict[i].size()>length-i)continue;
                if(i == length-wordDict[i].size() && s.substr(i,wordDict[i].size()) == wordDict[i])
                {
                    Is_word_breakful[i] = 1;
                }
                if(Is_word_breakful[i+wordDict[i].size()]==1 && s.substr(i,wordDict[i].size()) == wordDict[i])
                {
                    Is_word_breakful[i] = 1;
                }
            }
        }
        return Is_word_breakful[0];

    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //nlogn
        // int length = nums.size();
        // return quickSort(nums,0,length-1,length-k+1);
        //try accelerate to n
        int length = nums.size();
        // build a max heap
        for(int i=length/2-1;i>=0;i--)
        {
            adjust_heap(nums,i,length);//从第一个非叶子节点开始调整
        }
        for(int i=length-1;i>=length-k;i--)
        {
            swap(nums[0],nums[i]);
            adjust_heap(nums,0,i);
        }
        return nums[length-k];
    }
    void adjust_heap(vector<int>& nums,int i,int length)
    {
        int tmp = nums[i];//先取出当前元素
        for(int k=2*i+1;k<length;k=2*k+1)//从i节点的左子节点开始
        {
            if(k+1<length && nums[k]<nums[k+1])k++;
            if(nums[k]>tmp)
            {
                nums[i] = nums[k];
                i = k;
            }
            else break;
        }
        nums[i] = tmp;
    }

    // int quickSort(vector<int>& nums,int left,int right,int k)
    // {
    //     if(left>=right)return nums[left];//如果只有一个元素
    //     int i = left,j = right;
    //     int tmp = nums[left];
    //     while(i<j)
    //     {
    //         while(i<j && nums[j]>=tmp)j--;
    //         while(i<j && nums[i]<=tmp)i++;
    //         if(i<j)swap(nums[i],nums[j]);
    //     }
    //     swap(nums[left],nums[i]);
    //     if(i == k-1)return nums[i];
    //     if(i>k-1)return quickSort(nums,left,i-1,k);
    //     if(i<k-1)return quickSort(nums,i+1,right,k);
        
    // }
};


// void quickSort(vector<int>& nums,int left,int right)
// {
//     if(left>=right)return;
//     int i = left,j = right;
//     int tmp = nums[left];
//     while(i<j)
//     {
//         while(i<j && nums[j]>=tmp)j--;
//         while(i<j && nums[i]<=tmp)i++;
//         if(i<j)swap(nums[i],nums[j]);
//     }
//     swap(nums[left],nums[i]);
//     quickSort(nums,left,i-1);
//     quickSort(nums,i+1,right);
// }



// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         vector<int> res;
//         unordered_map<int,int> map_Num_Size;
//         for(auto x:nums)
//         {
//             map_Num_Size[x]++;
//         }
//         vector<int> cnt_num;
//         for(auto x:map_Num_Size)
//         {
//             cnt_num.push_back(x.second);
//         }
//         return res;
//     }
// };


class MedianFinder {
public:
    MedianFinder() {
        size=0;
        Is_even=1;
        median = 0;
        nums_left.clear();
        nums_right.clear();
    }
    
    void addNum(int num) {
        if(size == 0){
            median = (double)num;
            size++;
            Is_even = !Is_even;
            return;
        }
        if(Is_even)
        {
            //如果是偶数，将num插入到合适的位置，并更新中位数
            if(num>=nums_left[0]&&num<=nums_right[0]){
                median = (double)num;
            }
            else if(num<nums_left[0]){
                nums_left.push_back(num);
                swap(nums_left[0],nums_left[nums_left.size()-1]);
                median = (double)nums_left[nums_left.size()-1];
                nums_left.pop_back();
                ajust_max_heap(nums_left,0,nums_left.size());
            }
            else {
                nums_right.push_back(num);
                swap(nums_right[0],nums_right[nums_right.size()-1]);
                median = (double)nums_right[nums_right.size()-1];
                nums_right.pop_back();
                ajust_min_heap(nums_right,0,nums_right.size());
            }
        }
        else{
            if(num<median){
                //将num插入左边
                nums_left.push_back(num);
                ajust_max_heap_up(nums_left,nums_left.size()-1,nums_left.size());

                //将median插入右边
                nums_right.push_back(median);
                ajust_min_heap_up(nums_right,nums_right.size()-1,nums_right.size());
                //更新中位数为左右堆顶元素的平均值
                median = (double)(nums_left[0]+nums_right[0])/2;
            }
            else{
                //将num插入右边
                nums_right.push_back(num);
                ajust_min_heap_up(nums_right,nums_right.size()-1,nums_right.size());
                //将median插入左边
                nums_left.push_back(median);
                ajust_max_heap_up(nums_left,nums_left.size()-1,nums_left.size());
                //更新中位数为左右堆顶元素的平均值
                median = (double)(nums_left[0]+nums_right[0])/2;
            }
        }
        Is_even = !Is_even;
        size++;
    }
    
    double findMedian() {
        return median;
    }
private:
int size;
bool Is_even;
double median;
vector <int> nums_left;
vector <int> nums_right;
    void ajust_max_heap(vector<int>& nums,int i,int length){
        int tmp = nums[i];
        for(int k=2*i+1;k<length;k = 2*k+1){
            if(k+1<length&&nums[k+1]>nums[k]){k = k+1;}
            if(nums[k]>tmp)
            {
                nums[i] = nums[k];
                i=k;
            }
            else break;
        }
        nums[i] = tmp;
    }
    //自下而上调整，应该改成这样子的形式：
    void ajust_max_heap_up(vector<int>& nums,int i,int length){
        while(i>0){
            int parent = (i-1)/2;
            if(nums[i]>nums[parent]){
                swap(nums[i],nums[parent]);
                i = parent;
            }
            else break;
        }
    }

    void ajust_min_heap(vector<int>& nums,int i,int length){
        int tmp = nums[i];
        for(int k=2*i+1;k<length;k = 2*k+1){
            if(k+1<length&&nums[k+1]<nums[k]){k = k+1;}
            if(nums[k]<tmp)
            {
                nums[i] = nums[k];
                i=k;
            }
            else break;
        }
        nums[i] = tmp;
    }
    void ajust_min_heap_up(vector<int>& nums,int i,int length){
        while(i>0){
            int parent = (i-1)/2;
            if(nums[i]<nums[parent]){
                swap(nums[i],nums[parent]);
                i = parent;
            }
            else break;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */



// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         unordered_map <int,int> map;
//         for(auto x:nums){
//             if(map.find(x) == map.end()){
//                 map[x] = 1;
//             }
//             else{
//                 //如果存在，则删除
//                 map.erase(x);
//             }
//         }
//         return *map.begin();
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
//     ListNode* sortList(ListNode* head) {
//         //use quick sort,with no extra space more than O(logn)
//         ListNode* tmp = head;
//         int length = 0;
//         while(tmp){
//             length++;
//             tmp = tmp->next;
//         }
//         quickSort(head,0,length-1);
//         return head;
//     }
    
// };

// class Solution {
// public:
//     string longestPalindrome(string s) {
//         cout << s.substr(1,2) << endl;//从a开始长度为b
//         vector<int> dp(s.size()+1,1);
//         int len = s.size();
//         if(len==1)return 1;
//         else if(len==2){
//             if(s[1]==s[0])return 2;
//             else return 1;
//         }
//         dp[0] = 1;
//         vector<int> dp_even(s.size()+1,1);
//         //每一个dp代表以i为结尾的最长回文子串的长度
//         for(int i=1;i<len;i++){
//             if(s[i]==s[i-1]&&s[i-1]==1){ //如果是aa这种情况
//                 dp_even[i] = 2;
//             }
//             //如果是cbsbc这种情况
//             if(i-dp[i-1]-1>=0&&s[i]==s[i-dp[i-1]-1]){
//                 dp[i] = dp[i-1]+2;
//             }
//             if(i-dp_even[i-1]-2>=0&&s[i]==s[i-dp_even[i-1]-2]){
//                 dp_even[i] = dp_even[i-1]+2;
//             }
//         }
//         int res = 0;
//         int index = 0;
//         for(int i=0;i<len;i++){
//             if(dp[i]>res){
//                 res = dp[i];
//                 index = i;
//             }
//             if(dp_even[i]>res){
//                 res = dp_even[i];
//                 index = i;
//             }
//         }
//         s = s.substr(index-res+1,res);
//         return s;
//     }
// };

// class Solution {
// public:
//     string longestPalindrome(string s) {
//         //use n^2
//         int len = s.size();
//         if(len==1)return s;
//         if(len==2){
//             if(s[0]==s[1])return s;
//             else return s.substr(0,1);
//         }
//         int res = 0;
//         int index = 0;
//         vector<vector<int>> dp(len,vector<int>(len,1));
        
//         for(int i=0;i<len;i++){
//             for(int j=0;j<i;j++){
//                 if(s[i]==s[j]&&(i-j==1||dp[j+1][i-1]==1)){
//                     dp[j][i] = 1;
//                     if(i-j+1>res){
//                         res = i-j+1;
//                         index = j;
//                     }
//                 }
//                 else dp[j][i] = 0;
//             }
//         }
//         s = s.substr(index,res);
//         return s;
//     }
// };


// int main(){
//     vector<int> nums;
//     nums.push_back(10);
//     nums.push_back(2);
//     nums.push_back(3);
//     nums.push_back(1);
//     quickSort(nums,0,nums.size()-1);
//     for(auto x:nums){
//         cout << x << endl;
//     }
// }
// int partition(vector<int>& nums,int left,int right){
//     int i = left,j = right;
//     int tmp = nums[left];
//     while(i<j){
//         while(i<j&&nums[j]>=tmp)j--;
//         while(i<j&&nums[i]<=tmp)i++;
//         if(i<j)swap(nums[i],nums[j]);
//     }
//     swap(nums[left],nums[i]);
//     return i;
// }
// void quickSort(vector<int>& nums,int left,int right){
//     if(left>=right)return;
//     int i = partition(nums,left,right);
//     quickSort(nums,left,i-1);
//     quickSort(nums,i+1,right);
// }


class RandomizedSet {
public:
    RandomizedSet() {
        size = 0;
        map.clear();
    }
    
    bool insert(int val) {
        if(map.find(val)!=map.end())return false;
        map[val] = 1;
    }
    
    bool remove(int val) {
        if(map.find(val)==map.end())return false;
        map.erase(val);
    }
    
    int getRandom() {
        int index = rand()%size;
        for(auto x:map){
            if(index==0)return x.first;
            index--;
        }
    }
private:
unordered_map<int,int> map;
int size;

};

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(),n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int sum = 0;
                for(int k=i-1;k<=i+1;k++){
                    for(int l=j-1;l<=j+1;l++){
                        if(k>=0&&k<m&&l>=0&&l<n){
                            if(i==k&&j==l)continue;
                            if(board[k][l]==1)sum++;
                        }
                    }
                }
                if(sum==3&&board[i][j]==0)board[i][j] = 2;//0->1
                if(sum>3&&board[i][j]==1)board[i][j] = 3;
                if(sum<2&&board[i][j]==1)board[i][j] = 3;//1->0
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==2)board[i][j] = 1;
                if(board[i][j]==3)board[i][j] = 0;
            }
        }
        
    }
};