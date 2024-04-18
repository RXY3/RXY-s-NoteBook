#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<int> gas;
    vector<int> cost;
    gas.push_back(1);
    gas.push_back(2);
    gas.push_back(3);
    gas.push_back(4);
    gas.push_back(5);
    cost.push_back(3);
    cost.push_back(4);
    cost.push_back(5);
    cost.push_back(1);
    cost.push_back(2);
    int n = gas.size();
    int sum = 0;
    int min = 0;
    int start = 0;
    for (int i = 0; i < n; i++)
    {
        sum += gas[i] - cost[i];
        if (sum < min)
        {
            min = sum;
            start = i + 1;
        }
    }
    if (sum < 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << start << endl;
    }

    return 0;
}