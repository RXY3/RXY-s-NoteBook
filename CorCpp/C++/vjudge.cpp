#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
using namespace std;

// vector<long long> q;
// void solve() {
//     long long x,y,res=0;
//     cin >> x >> y;
//     long long num_of_even , num_of_odd;

//     if(x%2==1)
//     {
//         res = (y - x + 2) / 4;
//     }
//     else
//     {
//         res = (y - x + 1) / 4;
//     }
//     cout << res << endl;
//     // q.push_back(res);
// }

// void solve()
// {
//     long long n,m;
//     cin >> n >> m;
//     vector<long long> a(n);
//     vector<long long> res;
//     long long max = -1e9;
//     for (long long i = 0; i < n; i++) {
//         cin >> a[i];
//         if (a[i] > max) {
//             max = a[i];
//         }
//     }
//     for (long long i = 0; i < m; i++) {
//         char op;
//         cin >> op;
//         long long l,r;
//         cin >> l >> r;
//         if(op == '+')
//         {
//             if(max <=r && max >= l)
//             {
//                 max = max + 1;
//             }
//         }
//         else
//         {
//             if(max <=r && max >= l)
//             {
//                 max = max - 1;
//             }
//         }
//         res.push_back(max);
//     }
//     for (long long i = 0; i < res.size(); i++) 
//         cout << res[i] <<' '    ;
//     cout << endl;

// }

// void solve()
// {
//     long long n;
//     cin >> n;
//     char c;
//     unordered_map <long long,long long> mp;
//     mp[0] = n;
//     mp[1] = n;
//     mp[2] = n;
//     mp[3] = n;
//     long long res = 0;
//     for (long long i = 0; i < 4*n; i++) {
//         cin >> c;
//         if(c == 'A' && mp[0] > 0)
//         {
//             mp[0]--;
//             res++;
//         }
//         else if(c == 'B' && mp[1] > 0)
//         {
//             mp[1]--;
//             res++;
//         }
//         else if(c == 'C' && mp[2] > 0)
//         {
//             mp[2]--;
//             res++;
//         }
//         else if(c == 'D' && mp[3] > 0)
//         {
//             mp[3]--;
//             res++;
//         }
//     }
//     cout << res << endl;
    
// }


 
// void solve()
// {
//     long long n;
//     cin >> n;
//     vector<long long> a(n);
//     for(long long i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     long long flag=0;
//     for(long long i = 0; i < n-1; i++)
//     {
//         if(a[i]>a[i+1])flag+=1;
//     }
//     if(a[n-1] > a[0])flag+=1;
//     if(flag >= 2)
//     {
//         cout << "NO" << endl;
//         return;
//     }
//     cout << "YES" << endl;
    
// }
// long long get_max(long long x, long long y)
// {
//     long long res = 0;
//     while(x != 0)
//     {
//         res += (x - x/y * y);
//         x = x/y;
//     }
//     // res += x;
//     return res;
// }

// void solve()
// {
//     long long x,y;
//     cin >> x >> y;
//     if(y == 1)
//     {
//         cout << x << endl;
//         return;
//     }
//     long long res = get_max(x,y);
//     cout << res << endl;
// }
// void solve()
// {
//     long long n;
//     cin >> n;
//     long long max_pre = 0,max_suf = 0;
//     cin >> max_pre >> max_suf;
//     vector<long long> res(n+10);
//     res[max_pre] = 1;
//     res[max_suf] = 1;
//     long long flag = -1;
//     for(long long i=max_suf-1;i>0;i--)
//     {
//         res[i] = flag;
//         flag = -flag;
//     }
//     flag = -1;
//     for(long long i=max_pre+1;i<=n;i++)
//     {
//         res[i] = flag;
//         flag = -flag;
//     }
//     for(long long i=max_suf+1;i<max_pre;i++)
//     {
//         res[i] = 1;
//     }
//     for(long long i=1;i<=n;i++)
//     {
//         cout << res[i] << ' ';
//     }
//     cout << endl;
//     return;
// }

// void solve()
// {
//     long long n,t=1,res = 0;
//     cin >> n;
//     res = n;
//     t = sqrt(n);
//     //取整
//     t = long long(t);
//     long long temp = t;
//     n += temp;
//     while(temp<=n)
//     {
//          temp = temp + 1;
//         if(temp*temp <= n)
//         {
//             n = n + 1;
//         }
//         else {
//             break;
//         }
//     }
//     cout << n << endl;
// }

// #include <bits/stdc++.h>

// using namespace std;

// void solve()
// {
//     long long n;
//     cin >> n;
//     vector<long long> a(n);
//     for(long long i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     unordered_map<long long,long long> mp;
//     unordered_map<long long,long long> mp2;
//     long long  sum = 0;
    
//     long long max = 0;
//     long long start = 0;
//     for(long long i = 0; i < n; i++)
//     {
//         sum += a[i];
//         mp[a[i]]++;
//         if(mp[a[i]] >= 2 && a[i] > max)
//         {
//             max = a[i];
//         }
//         a[i] = max;
//         mp2[a[i]]++;
//         if(max == 0)
//         {
//             start = i;
//         }
//         sum += max;
//     }
//     if(max == 0)
//     {
//         cout << sum << endl;
//         return;
//     }
//     mp.clear();
//     //一轮后，已经是递增的了，
//     max = 0;
//     for(long long i=start+1;i<n;i++)
//     {
//         if(mp2[a[i]] < 2)
//         {
//             a[i] = a[i-1];
//             sum += a[i] * (n - i - 1);
//         }
//         else {
//             sum += a[i] * (n - i - 1);
//         }
//     }
//     // 整数形式输出
//     cout << sum << endl;
    
// }


// void solve()
// {
//     long long a,b,c,d;
//     cin >> b >> c >> d;
//     // 0 0 -》 0  a = 0 
//     // 0 0 -》 1  a = 1
//     // 0 1 -》 0  a = 0
//     // 0 1 -》 1  不可能
//     // 1 0 -》 0  不可能，此时需要进位
//     // 1 0 -》 1  a = 1
//     // 1 1 -》 0  a = 1
//     // 1 1 -》 1  a = 0
    
//     //将b,c,d转换为二进制
//     bitset <64> bit_b(b);
//     bitset <64> bit_c(c);
//     bitset <64> bit_d(d);
//     vector<long long> bit_a(64);
//     // cout << bit_b << endl;
//     for(long long i = 0; i < 64; i++)
//     {
//         if(bit_b[i] == 0 && bit_c[i] == 0 && bit_d[i] == 0)
//         {
//             bit_a[i] = 0;
//         }
//         else if(bit_b[i] == 0 && bit_c[i] == 0 && bit_d[i] == 1)
//         {
//             bit_a[i] = 1;
//         }
//         else if(bit_b[i] == 0 && bit_c[i] == 1 && bit_d[i] == 0)
//         {
//             bit_a[i] = 0;
//         }
//         else if(bit_b[i] == 0 && bit_c[i] == 1 && bit_d[i] == 1)
//         {
//             cout << -1 << endl;
//             return;
//         }
//         else if(bit_b[i] == 1 && bit_c[i] == 0 && bit_d[i] == 0)
//         {
//             cout << -1 << endl;
//             return;
//         }
//         else if(bit_b[i] == 1 && bit_c[i] == 0 && bit_d[i] == 1)
//         {
//             bit_a[i] = 1;
//         }
//         else if(bit_b[i] == 1 && bit_c[i] == 1 && bit_d[i] == 0)
//         {
//             bit_a[i] = 1;
//         }
//         else if(bit_b[i] == 1 && bit_c[i] == 1 && bit_d[i] == 1)
//         {
//             bit_a[i] = 0;
//         }
//     }
//     //将二进制转换为十进制
//     long long res = 0;
//     for(long long i = 0; i < 64; i++)
//     {
//         if(bit_a[i] == 1)
//         {
//             res += ((long long)1 << i);
//         }
//     }
//     cout << res << endl;


// }

// #include <bits/stdc++.h>

// long long get_big_2(long long a)
// {
//     long long res = 0;
//     while(a%2==0)
//     {
//         a = a/2;
//         res++;
//     }
//     return res;
// }
// void solve()
// {
//     long long n,m=0;
//     cin >> n;
//     vector<long long> an(n);
//     map<long long, long long> mp;

//     long long num_of_2 = 0;

//     for (long long i = 0; i < n; i++)
//     {
//         cin >> an[i];
//         mp[an[i]]++;
//     }
//     //m为map中元素的个数
//     m = mp.size();
    
//     for(auto it = mp.begin(); it != mp.end();)
//     {
//         if(it->first % 2 == 0)
//         {
//             long long a=it->first,res=0;
//             while(a%2==0)
//             {
//                 a = a/2;
//                 res++;
//             }
//             num_of_2 += res * it->second;
//             //删去这个it
            
//             //将a插入到map中
//             if(mp.find(a) != mp.end())
//             {
//                 mp[a] += it->second;
//             }
//             else{
//                 mp[a] = it->second;
//             }
//             it = mp.erase(it);
//         }
//         else it ++;
//     }
//     cout << num_of_2 << endl;
//     m = mp.size();

//     map<long long, long long> map_of_num_bigger_than;
//     map_of_num_bigger_than[mp.rbegin()->first] = mp.rbegin()->second;
//     vector<long long> num_prosum(m, 1);
//     vector<long long> num_val(m, 0);
//     for(auto it = mp.begin(); it != mp.end(); it++)
//     {
//         num_val[distance(mp.begin(), it)] = it->first;
//     }
//     num_prosum[m-1] = map_of_num_bigger_than[mp.rbegin()->first];
//     for (auto it = mp.rbegin(); it != mp.rend(); it++)
//     {
//         if (it == mp.rbegin())
//         {
//             continue;
//         }
//         map_of_num_bigger_than[it->first] = map_of_num_bigger_than[prev(it)->first] + it->second;
//         num_prosum[m-distance(mp.rbegin(), it)-1] = map_of_num_bigger_than[it->first];
//     }

//     for(long long i = 0; i < m; i++)
//     {
//         cout << num_val[i] << ' ' << num_prosum[i] << ' ' ;
//     }cout << endl;
//     long long res = 0;
//     for(long long i = 0; i < m; i++)
//     {
//         if(num_prosum[i] >= num_val[i])
//         {
//             res = num_val[i];
//         }
//         else{
//             if(num_val[i] >= n){
//                 break;
//             }
//             long long num2_needed = 0,index = i;long long tmp = 0;
//             long long short_of = num_val[i] - num_prosum[i];
//             while(num2_needed <= num_of_2)
//             {
//                 index --;
                
//                 long long rate = num_val[i] / num_val[index];
//                 while(rate > 1)
//                 {
//                     rate = rate / 2;
//                     tmp++;
//                 }
//                 num2_needed += tmp * mp[num_val[index]];
//                 short_of -= mp[num_val[index]];
//                 if(short_of <= 0 && num2_needed <= num_of_2)
//                 {
//                     res = num_val[index];
//                     break;
//                 }
//             }
//             if(short_of <= 0)
//             {
//                 short_of += mp[num_val[index]];
//                 short_of = short_of - (num_of_2 - num2_needed + tmp * mp[num_val[index]])/tmp;
//                 if(short_of <= 0)
//                 {
//                     res = num_val[index];
//                 }
//             }
//         }
//     }
    


    
// }
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <unordered_map>
// #include <map>
// #include <set>
// using namespace std;
// struct node
// {
//     long long sum;
//     long long len;
// };
// namespace std {
//     template <>
//     struct hash<node> {
//         size_t operator()(const node& n) const {
//             return hash<long long>()(n.sum) ^ hash<long long>()(n.len);
//         }
//     };
// }

// void solve()
// {
    //too brute force
    // long long n;
    // cin >> n ;
    // vector<long long> nums(n);
    // for(long long i = 0; i < n; i++)
    // {
    //     cin >> nums[i];
    // }
    // vector<string> numStr(n);
    // long long res = 0;
    // for(long long i = 0; i < n; i++)
    // {
    //     numStr[i] = to_string(nums[i]);
    // }
    // unordered_map<string,vector<long long> > mp;
    // for(long long i=0;i<n;i++)
    // {
    //     string tmp = numStr[i];
    //     long long sum = 0;
    //     for(long long j=0;j<tmp.size();j++)
    //     {
    //         sum+=(numStr[i][j]-'0');
    //         mp[numStr[i]].push_back(sum);
    //     }
    // }
    // for(long long i=0;i<n;i++)
    // {
    //     for(long long j=0;j<n;j++)
    //     {
    //         if(i==j){res++;continue;}
    //         if((numStr[i].size()+numStr[j].size()) % 2 == 0)
    //         {
    //             long long len1 = numStr[i].size(),len2 = numStr[j].size();
    //             long long len = (len1 + len2)/2;
    //             if(len < len1 && mp[numStr[i]][len-1] == mp[numStr[j]][len2-1] + mp[numStr[i]][len1-1] - mp[numStr[i]][len-1])
    //             {
    //                 res++;
    //             }
    //             else if(len < len2 && mp[numStr[i]][len1-1]+2*mp[numStr[j]][len-len1-1] == mp[numStr[j]][len2-1])
    //             {
    //                 res++;
    //             }
    //             else if(mp[numStr[i]][len1-1] == mp[numStr[j]][len2-1])
    //             {
    //                 res++;
    //             }
    //         }
    //     }
    // }
    // cout << res << endl;
//     unordered_map<struct node, vector<long long> > mp;
//     long long n;
//     cin >> n;
//     vector<long long> nums(n);

//     for(long long i = 0; i < n; i++)
//     {
//         cin >> nums[i];
//     }
//     vector<string> numStr(n);
//     long long res = 0;
//     for(long long i = 0; i < n; i++)
//     {
//         numStr[i] = to_string(nums[i]);
//         long long sum = 0;
//         for(long long j = 0; j < numStr[i].size(); j++)
//         {
//             sum += (numStr[i][j] - '0');
//         }
//         //将该数存入map中
//         node currNode = {sum, numStr[i].size()};
//         mp[currNode].push_back(nums[i]);
//     }
    
// }

// signed main() {
//     long long t = 1;
//     while (t--) {
//     solve();
//     }
// }

//



// #include <bits/stdc++.h>
// using namespace std;
// void solve()
// {
//     long long n,t=1,res = 0;
//     cin >> n;
//     res = n;
//     t = sqrt(n);
//     //取整
//     t = (long long)(t);
//     long long temp = t;
//     n += temp;
//     while(temp<=n)
//     {
//         temp = temp + 1;
//         if(temp*temp <= n)
//         {
//             n = n + 1;
//         }
//         else {
//             break;
//         }
//     }
//     cout << n << endl;
// }
// signed main() {
//     long long t = 1;
//     cin >> t;
//     while (t--) {
//     solve();
//     }
 
// }

//10 2 14
// 0 1 0 1 0

// 0 0 0 1 0
// 0 1 1 1 0



// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <string>
// using namespace std;

// // 定义node结构体
// struct node {
//     long long sum;
//     long long len;
//         bool operator==(const node& other) const {
//         return sum == other.sum && len == other.len;
//     }
// };

// // 为node结构体定义哈希函数
// namespace std {
//     template <>
//     struct hash<node> {
//         size_t operator()(const node& n) const {
//             return hash<long long>()(n.sum) ^ hash<long long>()(n.len);
//         }
//     };
// }

// long long main() {
//     long long n;
//     std::cin >> n;
//     std::vector<long long> nums(n);
//     std::vector<std::string> numStr(n);
//     std::unordered_map<node, std::vector<long long> > mp;
//     long long res = 0;

//     for (long long i = 0; i < n; i++) {
//         std::cin >> nums[i];
//         numStr[i] = std::to_string(nums[i]);
//         long long sum = 0;
//         for (long long j = 0; j < numStr[i].size(); j++) {
//             sum += (numStr[i][j] - '0');
//         }
//         // 创建一个node实例并将其添加到map中
//         node currNode = {sum, numStr[i].size()};
//         mp[currNode].push_back(nums[i]);
//     }

//     // 打印map中的内容以验证
//     for(long long i=0;i<n;i++)
//     {
//         long long numx = nums[i];
//         long long sum = 0;
//         long long len = 0;
//         while(numx)
//         {
//             sum += numx % 10;
//             numx /= 10;
//             len++;
//         }
//         numx = nums[i];
//         //对于map中的每一个元素，根据其sum和len判定是否符合条件
//         for(auto it = mp.begin(); it != mp.end(); it++)
//         {
//             if((it->first.sum + sum)%2 == 0 && (it->first.len + len)%2 == 0)
//             {
//                 for(auto num : it->second)
//                 {
//                     // num在前，numx在后
//                     string numStr1 = to_string(num);
//                     string numStr2 = to_string(numx);
//                     string StrX = numStr1 + numStr2;
//                     long long lenHalf = StrX.size() / 2;
//                     long long sum1 = 0,sum2 = 0;
//                     for(long long i = 0; i < lenHalf; i++)
//                     {
//                         sum1 += StrX[i] - '0';
//                     }
//                     for(long long i = lenHalf; i < StrX.size(); i++)
//                     {
//                         sum2 += StrX[i] - '0';
//                     }
//                     if(sum1 == sum2)
//                     {
//                         res++;
//                     }
//                     // numx在前，num在后
//                     StrX = numStr2 + numStr1;
//                     sum1 = 0; sum2 = 0;
//                     for(long long i = 0; i < lenHalf; i++)
//                     {
//                         sum1 += StrX[i] - '0';
//                     }
//                     for(long long i = lenHalf; i < StrX.size(); i++)
//                     {
//                         sum2 += StrX[i] - '0';
//                     }
//                     if(sum1 == sum2)
//                     {
//                         res++;
//                     }
//                 }
//             }
//         }
//     }
//     std::cout << res/2  << std::endl;

//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
using namespace std;
vector<long long> q;
void solve()
{
    long long num;
    long long mon;
    cin >> num >> mon;
    vector<long long> a(num);
    for (long long i = 0; i < num; i++) {
        cin >> a[i];
    }
    unordered_map<long long,long long> mp;
    for(long long i = 0; i < num; i++)
    {
        mp[a[i]]++;
    }
    long long res = 0;
    long long numCnt = mp.size();
    // a*x  a+1 * y  找最接近mon的x和y   
    for(auto it = mp.begin(); it != mp.end(); it++)
    {
        long long cur = it->first;
        long long cnt = it->second;
        //在map中找cur+1
        auto it2 = mp.find(cur+1);
        if(it2 == mp.end())
        {
            res =max ((min(mon / cur, cnt) * cur) , res );
            continue;   
        }
        long long cnt2 = it2->second;
        long long rate = mon / (cur+1);
        if(mon >= cur*cnt + (cur+1)*cnt2)
        {
            res  = max(res,cur*cnt + (cur+1)*cnt2);
        }
        else{
            if(rate == mon / cur)
            {
                int tmp =min(cnt2,(mon - rate * cur)); 
                res = max(res,rate * cur + tmp);
            }
            else{
                if(mon / cur <= cnt)
                {
                    res = max(res,mon / cur * cur);
                }
                else{
                    if(rate-cnt2>=0)tmp = 
                    res = max(res, min(rate,cnt2) * (cur+1) + tmp * cur);
                }
            }
        }
    }
    cout << res << endl;
}

signed main() {
    long long t = 1;
    cin >> t;
    while (t--) {
    solve();
    }

}