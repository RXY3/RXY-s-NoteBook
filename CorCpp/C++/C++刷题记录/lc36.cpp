#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9, vector<int>(9, 0));
        vector<vector<int>> col(9, vector<int>(9, 0));
        vector<vector<int>> box(9, vector<int>(9, 0));
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;
                int num = board[i][j] - '0' - 1;
                int box_index = (i / 3) * 3 + j / 3;
                if (row[i][num] || col[j][num] || box[box_index][num])
                    return false;
                row[i][num] = 1;
                col[j][num] = 1;
                box[box_index][num] = 1;
            }
        }
        return true;
    }
};
int main()
{
int n;
cin >> n;
for (int i = 0; i < n; i++)
{

}
    return 0;
}
class Solution {
public:
    void rotate_inside(vector<vector<int>>& matrix, int len,int i,int j)
    {
        if(len==1)
            return;
        int a,b,c,d;
        a = matrix[i][j];
        b = matrix[j][len-i-1];
        c = matrix[len-i-1][len-j-1];
        d = matrix[len-j-1][i];
        matrix[i][j] = d;
        matrix[j][len-i-1] = a;
        matrix[len-i-1][len-j-1] = b;
        matrix[len-j-1][i] = c;
        return;
    }
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size()/2;i++)
        {
            for(int j=i;j<matrix.size()-i-1;j++)
            {
                rotate_inside(matrix,matrix.size(),i,j);
            }
        }
        return;
    }
};