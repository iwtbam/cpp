// 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
// 路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向
// 下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。
// 例如 a b c e s f c s a d e e 这样的3 X 4 矩阵中包含一条字符串"bcced"的路径，
// 但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子
// 之后，路径不能再次进入该格子。

#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

class Solution {

public:

    bool* visited;
    int rows;
    int cols;
    char* matrix;
    char* str;

    bool hasPathHelper(int row , int col, int step)
    {

        if(row < 0 || row >= rows || col < 0 || col >= cols)
            return false;

        int index= row * cols + col;
        
        if(visited[index])
            return false;
        
        visited[index] = true;
        
        if(step < strlen(str) && str[step] == matrix[index])
        {
            cout << step << " "<< row << " "<< col << " "<<matrix[index] << endl;
            if(step == strlen(str) - 1)
                return true;
        }
        else
        {
            visited[index] = false;
            return false;
            
        }

        
        bool result = hasPathHelper(row - 1, col, step + 1) ||
               hasPathHelper(row + 1, col, step + 1) ||
               hasPathHelper(row, col - 1, step + 1) ||
               hasPathHelper(row, col + 1, step + 1);
        
        visited[index] = false;

        return result;
    }

    bool hasPath(char* matrix,int rows, int cols, char* str)
    {
        visited = new bool[cols * rows];
        memset(visited, 0, rows * cols * sizeof(bool));

        this->rows = rows;
        this->cols = cols;
        this->matrix = matrix;
        this->str = str;

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols;j++)
            {
                cout << "---------" << endl;
                if(hasPathHelper(i, j, 0))
                    return true;
                visited[i * cols + j ] = false;
                
            }
        }

        delete[] visited;
        return false;
    }
};

int main()
{
    Solution s;
    char* matrix =  "ABCEHJIG"
                    "SFCSLOPQ"
                    "ADEEMNOE"
                    "ADIDEJFM"
                    "VCEIFGGS";

    char* str = "SLHECCEIDEJFGGFIE";
    bool result = s.hasPath(matrix, 5, 8, str);
    cout << boolalpha << result << endl; 
    return 0;
}