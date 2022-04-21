#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int map[1001][1001], n, m;
int visited[1001][1001][2];
int dx[]={0,1,0,-1};
int dy[]={-1,0,1,0};
queue <pair<int, pair<int, int>> > Q;

int main() {
    freopen("input.txt", "rt", stdin);
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%1d", &map[i][j]);
        }
    }

    Q.push(make_pair(1, make_pair(1,1)));
    visited[1][1][1]=1;
    
    while(!Q.empty()){
        pair<int, pair<int, int> > tmp=Q.front();
        int b = tmp.first;
        int y = tmp.second.first;
        int x = tmp.second.second;
        
        Q.pop();
        if(y==n && x==m){
            printf("%d\n", visited[y][x][b]);
            exit(0);
        }

        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<1 || ny<1 || ny>n || nx>m) continue;

            if(map[ny][nx]==1 && b>0){
                visited[ny][nx][b-1] = visited[y][x][b] + 1;
                Q.push(make_pair(b-1, make_pair(ny,nx)));
            }
            if(map[ny][nx]==0 && visited[ny][nx][b]==0){
                visited[ny][nx][b] = visited[y][x][b] + 1;
                Q.push(make_pair(b, make_pair(ny,nx)));
            }
        }
    }
    printf("-1\n");

    return 0;   
}