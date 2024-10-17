# CPP LEETCODE 刷题记录总结

## Hop100
[HOT100](https://leetcode.cn/studyplan/top-100-liked/)
### Chapter 1: Hash

#### 1. 两数之和
- [x] [1. 两数之和](https://leetcode-cn.com/problems/two-sum/)
brute的思路就是直接进行两层嵌套循环，找到两个数的和等于target的情况，时间复杂度为O(n^2)。
使用hash可以将时间复杂度降低到O(n)。
思路：
1. 遍历数组，将数组的值和索引存入hash表中。
2. 在遍历的过程中，判断target-nums[i]是否在hash表中，如果在，返回两个数的索引。
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            if (hash.find(target - nums[i]) != hash.end()) {
                return {hash[target - nums[i]], i};
            }
            hash[nums[i]] = i;
        }
        return {};
    }
};
```
#### 2.字母异位词分组
- [x] [49. 字母异位词分组](https://leetcode-cn.com/problems/group-anagrams/)

> 题目提出了一个概念，字母异位词，即两个字符串中的字符种类和数量相同，但是顺序不同。要求是将字母异位词分组，即将字母异位词放在一起。 

> 思路比较简单，首先建立一个hash表，key为排序后的字符串，value为原字符串的vector。将排序后的字符串作为key，原字符串作为value，存入hash表中。


#### 3. 最长连续序列
- [x] [128. 最长连续序列](https://leetcode-cn.com/problems/longest-consecutive-sequence/)
1. problem description:
给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
时间复杂度要求为O(n)。
2. 思路
从brute的角度来看，只需要进行排序，然后遍历一遍数组，找到最长的连续序列即可。但是这样的时间复杂度为O(nlogn)。
优化的思路是使用到hash,并建立一个struct，记录当前数字对应的最大连续序列的长度。
对于数据进行遍历，根据新的数字前后是否存在，来更新当前数字对应的最大连续序列的长度。
```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        struct Node {
            int exist;
            int max_len;
        };
        unordered_map<int, Node> map;
        int max_len = 0;
        for (int i = 0; i < nums.size(); i++) {
            if(map[nums[i]].exist) {
                continue;
            }
            map[nums[i]].exist = 1;
            map[nums[i]].max_len = 1;
            map[nums[i]].max_len = map[nums[i] - 1].exist * map[nums[i] - 1].max_len + map[nums[i] + 1].exist * map[nums[i] + 1].max_len + 1;
            if (max_len < map[nums[i]].max_len) {
                max_len = map[nums[i]].max_len;
            }
            //更新前后的最大连续序列的长度
            if(map[nums[i] - 1].exist) {
                map[nums[i] - map[nums[i] - 1].max_len].max_len = map[nums[i]].max_len;
            }
            if(map[nums[i] + 1].exist) {
                map[nums[i] + map[nums[i] + 1].max_len].max_len = map[nums[i]].max_len;
            }
        }
        return max_len;
    }
};
```

### Chapter 2: Two Pointers
本章名为双指针，主要是指针对数组进行遍历，找到符合条件的情况。这里主要是指针的移动，以及指针的更新。
比较重要的几个思想是：
1. 滑动窗口：
滑动窗口的思想是，维护一个窗口，窗口的大小是固定的，然后根据窗口的变化，来更新窗口内的数据。每次只需要根据首尾指针的变化，来更新窗口内的数据。
2. 快慢指针

#### 1. 移动零
- [x] [283. 移动零](https://leetcode-cn.com/problems/move-zeroes/)
  
1. problem description:
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
2. 思路
首先从最差的情况入手，直接新建立一个数组，然后将非零元素放入新数组中，然后将0放入新数组中。这样的时间复杂度为O(n)。空间复杂度为O(n)。
考虑到题目要求原地，可以发现对于已经识别过的数字，不需要考虑其在原位置的值的改变，所以可以直接维护一个非零元素的数量，并以此为index将非零元素放入数组中，最后将剩余的位置填充为0即可。
```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[index++] = nums[i];
            }
        }
        for (int i = index; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};
```

#### 2. 盛水最多的容器
- [x] [11. 盛最多水的容器](https://leetcode-cn.com/problems/container-with-most-water/)

1. problem description:
给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i])   
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。  
返回容器可以储存的最大水量。  
2. 思路
同样的，我们先给出一个brute 的思路：  
我们可以直接进行两层的循环，找到所有的情况，然后找到最大的容量。时间复杂度为O(n^2)。  
要进行优化的话，需要明确的是，对于某一个容器的情况，我们具体将会怎么去优化他，也就是找到一个贪心的思路 。  
从最大的容器，也就是首尾开始，我们首先明确的是，容器的大小可以用公式：(j-i) * min(height[i], height[j])来表示。 
很显然的可以发现，我们应当去移动较小的那一边，因为如果移动较大的一边，容器的大小只会变小。  
因此思路非常清晰，我们可以使用双指针，分别指向首尾，然后根据上述的公式来更新容器的大小。  
```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int water=0;
        while(i<j)
        {
            water = max(water,(j-i)*min(height[i],height[j]));
            if(height[i]<height[j])i++;
            else j--;
        }
        return water;
    }
};
```

#### 3. 三数之和

- [x] [15. 三数之和](https://leetcode-cn.com/problems/3sum/)

1. problem description:

给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。

2. 思路
还是先给出一个brute的思路：  
> 三层循环，找到所有的情况，然后找到符合条件的情况。时间复杂度为O(n^3)。

优化的思路：
首先，由于有3个数字要找，复杂度不可避免较高，因此可以考虑先进行排序

在排序后，我们想将复杂度降低到n^2，可以考虑使用双指针的思想，即固定一个数，然后使用双指针来找到另外两个数。

细节上需要注意，由于不能有重复的三元组，因此在找到符合条件的三元组后，需要跳过重复的数字。

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()<3) return res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {
            if(i>0&&nums[i]==nums[i-1]) continue;
            int l=i+1,r=nums.size()-1;
            while(l<r)
            {
                if(nums[i]+nums[l]+nums[r]==0)
                {
                    res.push_back({nums[i],nums[l],nums[r]});
                    while(l<r&&nums[l]==nums[l+1]) l++;
                    while(l<r&&nums[r]==nums[r-1]) r--;
                    l++;
                    r--;
                }
                else if(nums[i]+nums[l]+nums[r]<0) l++;
                else r--;
            }
        }
        return res;
    }
};
```

#### 4. 接雨水
- [x] [42. 接雨水](https://leetcode-cn.com/problems/trapping-rain-water/)

1. problem description:
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

2. 思路

首先，我们可以先给出一个brute的思路：
> 对于每一个柱子，我们都可以找到其左右两边的最大值，然后取两者的最小值，减去当前柱子的高度，即为当前柱子能接到的雨水。时间复杂度为O(n^2)。

优化的思路：
首先明确一个思路，对于每次能够接水的首尾部分，当尾部的高度大于等于首部时，这部分的接水便结束了。因此我们可以使用双指针的思想，分别指向首尾，然后根据上述的思路来更新接水的情况。

同时需要注意的是，从前往后和从后往前的两种情况，需要分别进行处理。

还有就是对于最高柱子在最后的情况需要进一步考虑

```cpp

class Solution {
public:
    int trap(vector<int>& height) {
        int head = 0, tail = height.size() - 1,sum = 0;
        if(tail<=1)return 0;
        //找到第一个不为0的柱子
        while(height[head]==0) head++;
        while(height[tail]==0)tail--;
        int index;
        //从前往后，直到最高的柱子
        while(head < tail){
            int tmp_sum = 0;
            index = head+1;
            while(height[index] < height[head] && index < tail){
                tmp_sum += height[head] - height[index];
                index++;
            }
            if(index < tail || index==tail&&height[head] < height[tail])//此处的特判是为了处理最高柱子在最后的情况
            {
                sum += tmp_sum;      
                head = index;
                tmp_sum = 0;
            }
            else break;
        }
        //从后往前，直到最高的柱子
        while(head < tail){
            int tmp_sum = 0;
            int index = tail-1;
            while(height[index] <= height[tail] && index > head){
                tmp_sum += height[tail] - height[index];
                index--;
            }
            if(index >= head)//此处可以直接使用>=，因为最高柱子在最后的情况已经处理过了
            {
                sum += tmp_sum;
                tail = index;
                tmp_sum = 0;
            }
            else break;
        }
        return sum;
    }
};
```


### 滑动窗口


