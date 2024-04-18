#include <iostream>
#include <string>
#include <vector>
using namespace std;
int trap(vector<int>& height) {
        int m=height.size();
        vector<int> left(m,0);
        vector<int> right(m,0);
        int water=0;
        int now=0;
        int h=0;
        for(int i=0;i<m;i++)
        {
            if(height[i] >= h){
                h = height[i];
                left[i] = 0;
            }
            else {
                left[i] = h - height[i];
            }
        }
        h = 0;
        for(int i=m-1;i>=0;i--)
        {
            if(height[i] >= h){
                h = height[i];
                right[i] = 0;
            }
            else {
                right[i] = h - height[i];
            }
        }
        for(int i=0;i<m;i++)
        {
            water += min(left[i],right[i]);
        }
        return water;
    }
int main()
{
    vector<int> height;
    height.push_back(4);
    height.push_back(2);
    height.push_back(0);
    height.push_back(3);
    height.push_back(2);
    height.push_back(5);

    cout << trap(height) << endl;
    return 0;
}