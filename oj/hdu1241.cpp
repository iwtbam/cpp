#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

#define LEN 101

char grid[LEN][LEN];

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};

int N, M;

typedef pair<int,int>  point;

void bfs(point start)
{
    queue<point> q;
    q.push(start);
    while(!q.empty())
    {
        point curPos = q.front();
        q.pop();
        for(int i = 0;i<8;i++)
        {
            point nextPos = {curPos.first + dx[i],curPos.second + dy[i]};
            int x = nextPos.first;
            int y = nextPos.second;
            if(x>=0 && x<N && y>=0 && y<M && grid[x][y]=='@')
            {
                grid[x][y] = '*';
                q.push(nextPos);
            }
        }
    }
}

int main()
{
    // freopen("data/hdu1241.txt","r",stdin);
    while(scanf("%d%d",&N,&M)!=EOF)
    {
        if(N==0)
            break;

        for(int i = 0;i<N;i++)
            scanf("%s",grid[i]);
        
        int num = 0;
        for(int i = 0;i<N;i++)
        {
            for(int j = 0;j<M;j++)
            {
                if(grid[i][j]=='@')
                {
                    num++;
                    grid[i][j]='*';
                    bfs(point(i,j));
                }
            }
        }
        printf("%d\n",num);
    }
}


// 简单的bfs, 没啥意思