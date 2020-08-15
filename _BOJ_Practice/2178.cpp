#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, m, map[101][101], dis[101][101];
queue<pair<int, int> > Q;
int dx[]={0,1,0,-1};
int dy[]={-1,0,1,0};

int main() {
    //freopen("input.txt", "rt", stdin);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%1d", &map[i][j]);
        }
    }
    Q.push(make_pair(1,1));
    dis[1][1]=1;
    map[1][1]=0;
    while(!Q.empty()){
        pair<int, int> tmp=Q.front();
        Q.pop();
        for(int i=0;i<4;i++){
            int nx = tmp.second + dx[i];
            int ny = tmp.first + dy[i];

            if(ny<=n && ny>=1 && nx<=m && nx>=1 && map[ny][nx]==1 && dis[ny][nx]==0){
                Q.push(make_pair(ny,nx));
                dis[ny][nx]=dis[tmp.first][tmp.second]+1;
            }
        }
    }
    printf("%d\n", dis[n][m]);

    return 0;   
}