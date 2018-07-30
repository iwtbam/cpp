#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;

#define LEN 10

char maze[LEN][LEN];
int visited[LEN][LEN];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int sx, sy, ex, ey;

int N, M, T, S;

bool dfs(int cx, int cy, int step)
{

    int ans = (T-step) -abs(cx-ex) - abs(cy-ey);
    if(ans<0 || ans%2)
        return false;

    char c = maze[cy][cx];

    if(c =='D' && step == T)
        return true;

    for(int i = 0;i<4;i++)
    {
       int nx = cx + dx[i], ny = cy + dy[i];
        if(nx>=0 && nx <M && ny >=0 && ny<N && maze[ny][nx]!='X'&&!visited[ny][nx])
        {
            visited[ny][nx] = 1;
            if(dfs(nx, ny, step+1))
                return true;
            visited[ny][nx] = 0;
        }

    }

    return false;
}


int main()
{
    // freopen("data/hdu1010.txt","r",stdin);
    while(scanf("%d%d%d",&N,&M,&T)!=EOF && (N||M||T))
    {
        S = 0;
        for(int i = 0;i<N;i++)
        {          
            scanf("%s", maze[i]);
            for(int j = 0;j<M;j++)
            {
                if(maze[i][j]=='S')
                {
                    sx = j;
                    sy = i;
                }
                else if(maze[i][j]=='D')
                {
                    ex = j;
                    ey = i;
                }
                else if(maze[i][j]=='X')
                {
                    S++;
                }
            }

        }

        if(M*N-S<=T)
        {
            printf("NO\n");
            continue;
        }

        memset(visited,0,sizeof(visited));
        
        visited[sy][sx] = 1;

        bool result = dfs(sx, sy, 0);
        if(result)
            printf("YES\n");
        else
            printf("NO\n");

    }
    return 0;
}


//奇偶剪枝
// 如下图的迷宫，上下左右行进
// 0 1 0 1 0 1
// 1 0 1 0 1 0
// 0 1 0 1 0 1
// 1 0 1 0 1 0
// 0 1 0 1 0 1
// 从 0 -> 1 或 1-> 0 必经历 奇数步
// 从 0 -> 0 或 1-> 1 必经历 偶数步

//  bfs 错 不是最短时间是
// int main()
// {
//     freopen("data/hdu1010.txt","r",stdin);
    
//     int N, M, T;
//     while(scanf("%d%d%d",&N,&M,&T)!=EOF&&(N||M||T))
//     {
//         Pos sPos;
//         for(int i = 0;i<N;i++)
//         {
//             for(int j = 0; j<M; j++)
//             {
//                 char c = getchar();
//                 if(c=='\n')
//                     c = getchar();
//                 maze[i][j] = c;

//                 if(maze[i][j]=='S')
//                 {
//                     sPos.y = i;
//                     sPos.x = j;
//                 }
//             }
//         }

//         memset(seconds, 0, sizeof(seconds));
//         seconds[sPos.y][sPos.x] = 1;
//         queue<Pos> q;
//         q.push(sPos);

//         // bool isArrive = false;
//         int arriveTime = 10000000;

//         while(!q.empty())
//         {
//             Pos curPos = q.front();
//             q.pop();
//             for(int i = 0; i<4;i++)
//             {
//                 Pos nextPos = { curPos.x + dx[i], curPos.y + dy[i] };
//                 if(nextPos.y>=0 && nextPos.y < N && nextPos.x >=0 && nextPos.x < M && !seconds[nextPos.y][nextPos.x])
//                 {
//                     char block = maze[nextPos.y][nextPos.x];
//                     seconds[nextPos.y][nextPos.x] = seconds[curPos.y][curPos.x] + 1;

//                     if(block=='X')
//                     {
//                         seconds[nextPos.y][nextPos.x] = -1;
//                         continue;
//                     }

//                     if(block=='.')
//                         q.push(nextPos);
//                     else if(block=='D')
//                     {
//                         // isArrive = true;
//                         arriveTime = min(seconds[nextPos.y][nextPos.x]-1,arriveTime);
//                     }
//                 }
//             }
//         }

//         if(arriveTime<=T)
//             printf("YES\n");
//         else
//             printf("NO\n");

//     }
// }