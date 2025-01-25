#include <iostream>
#include <string>
#include <vector>
using namespace std;

int candy(vector<int>& ratings) //the reason why it
{
    int m = ratings.size();
    vector<int> left(m, 1);
    
    for (int i = 1; i < m; i++) {
        if (ratings[i] > ratings[i - 1]) {
            left[i] = left[i - 1] + 1;
        }
    }

    vector<int> right(m, 1);

    for (int i = m - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            right[i] = right[i + 1] + 1;
        }
    }

    int res = 0;
    for (int i = 0; i < m; i++) {
        res += max(left[i], right[i]);
    }

    return res;
}

int main()
{   
    vector<int> ratings;
    ratings.push_back(1);
    ratings.push_back(0);
    ratings.push_back(2);
    cout << candy(ratings) << endl;

    return 0;
}