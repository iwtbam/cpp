// 地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，
// 每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标
// 和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），
// 因为3+5+3+7 = 18。但是，它不能进入方格（35,38），因为3+5+3+8 = 19。
// 请问该机器人能够达到多少个格子？

#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:

    int rows;
    int cols;
    int threshold;
    bool* visited;

    int calc(int rows)
    {
        int sum = {0};
        do{
            sum += rows % 10;
        }while(rows /= 10);
        return sum;
    }

    int movingCountHelper(int row, int col)
    {
        if(row < 0 || row >= rows || col < 0 || col >= cols)
            return 0;

        if(calc(row) + calc(col) > threshold)
            return 0;
        
        int index = row * cols + col;
        if(visited[index])
            return 0;
        
        visited[index] = true;
        
        int result =  1 + movingCountHelper(row + 1, col) 
                 + movingCountHelper(row - 1, col)
                 + movingCountHelper(row, col + 1)
                 + movingCountHelper(row, col - 1);
        
        // visited[index] = false;

        return result;
        
    }

    int movingCount(int threshold, int rows, int cols)
    {
        this->rows = rows;
        this->cols = cols;
        this->threshold = threshold;
        visited = new bool[rows * cols];
        memset(visited, 0, rows * cols * sizeof(bool));
        int result =  movingCountHelper(0, 0);
        delete[] visited;
        return result;
    }
};

int main()
{
    Solution s;
    cout << s.movingCount(50, 50, 18) << endl;
    return 0;
}