// 2206 참고
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int map[1001][1001], n, m, hx, hy, ex, ey, ans=2147000000;
int visited[1001][1001][2];
int dx[]={0,1,0,-1};
int dy[]={-1,0,1,0};
queue<pair<int, pair<int, int> > > Q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    cin >> n >> m;
    cin >> hx >> hy;
    cin >> ex >> ey;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> map[i][j];
        }
    }
    vector<vector<int> > dis(n+1, vector<int>(m+1, 0));

    Q.push(make_pair(1 ,make_pair(hx, hy)));
    visited[hy][hx][1]=0;
    while(!Q.empty()){
        pair<int, pair<int, int> > tmp = Q.front();
        int block=tmp.first;
        int y=tmp.second.first;
        int x=tmp.second.second;
        Q.pop();
        
        if(x==ey && y==ex) {
            ans = min(ans, visited[y][x][block]);
        }

        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=1 && ny>=1 && nx<=m && ny<=n){
                if(map[ny][nx]==1 && block>0){
                    visited[ny][nx][block-1] = visited[y][x][block] + 1;
                    Q.push(make_pair(block-1, make_pair(ny,nx)));
                }
                if(map[ny][nx]==0 && visited[ny][nx][block]==0){
                    visited[ny][nx][block] = visited[y][x][block] + 1;
                    Q.push(make_pair(block, make_pair(ny,nx)));
                }
            }
        }
    }
    if(ans == 2147000000) ans = -1;

    cout << ans << '\n';
    return 0;
}