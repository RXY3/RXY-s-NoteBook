#include <cstddef>
#include <iostream>
#include <sys/select.h>
#include <sys/types.h>
using namespace std;
struct Listnode{
    int val;
    struct Listnode *next;
};
Listnode *divide_order(Listnode *head,Listnode *tail);
Listnode *merge_order(Listnode *node1, Listnode * node2);
int main() {
    // char str[3];
    // std::cin>>str;
    Listnode * head = new struct Listnode;
    Listnode * tmp = head;
    int len;
    cin >> len;
    for(int i=0;i<len;i++){
        if(i!=len-1)tmp->next = new struct Listnode;
        std::cin >> tmp->val;
        tmp = tmp->next;
    }
    head = divide_order(head,nullptr);

    while(head!=NULL){
        cout << head->val << endl;
        head = head->next;
    }
    // std::cout << "hello world" << std::endl;
    return 0;
}
 
// 4 -5 -6 -7 -9 -1 
Listnode *divide_order(Listnode *head,Listnode *tail){
    if(head == NULL)return head;
    else if (head->next == tail){
        head->next = NULL;
        return head;
    }
    Listnode* slow = head,*fast = head;
    while(fast != tail){
        slow = slow -> next;
        fast = fast ->next;
        if(fast != tail){
            fast = fast -> next;
        }
    }
    Listnode* mid = slow;
    return merge_order(divide_order(head,slow),divide_order(slow,tail));
}
Listnode *merge_order(Listnode *node1,Listnode* node2){
    Listnode * head = new struct Listnode;
    Listnode * tmp = head,*tmp1 = node1, *tmp2 = node2;

    // cout << head->val << endl;
    
    while(tmp1 != NULL && tmp2 != NULL){
        if(tmp1 -> val >= tmp2 -> val){
            tmp->next = tmp2;
            tmp2 = tmp2->next;
        }
        else {
            tmp->next = tmp1;
            tmp1 = tmp1->next;
        }
        tmp = tmp->next;
    }
    if(tmp1 != NULL){
        tmp ->next = tmp1;
    }
    if(tmp2 != NULL){
        tmp->next = tmp2;
    }
    return head->next;
        
} 


// 二分的写法

int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1; // 定义target在左闭右闭的区间里，[left, right]
        while (left <= right) { // 当left==right，区间[left, right]依然有效，所以用 <=
            int middle = left + ((right - left) / 2);// 防止溢出 等同于(left + right)/2
            if (nums[middle] > target) {
                right = middle - 1; // target 在左区间，所以[left, middle - 1]
            } else if (nums[middle] < target) {
                left = middle + 1; // target 在右区间，所以[middle + 1, right]
            } else { // nums[middle] == target
                return middle; // 数组中找到目标值，直接返回下标
            }
        }
        // 未找到目标值
        return -1;
    }


struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x ) : val(x),left(NULL),right(NULL){}
}

path.push_back()
path.pop_back();
unordered_map
