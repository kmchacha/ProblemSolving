#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int n, map[101][101], ch[101][101], visited[101][101], ans;
queue<pair<int, int> > Q;
int dx[]={0,1,0,-1};
int dy[]={-1,0,1,0};

void DFS(int y, int x){
    visited[y][x]=1;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=1 && ny>=1 && nx<=n && ny<=n && visited[ny][nx]==0 && ch[ny][nx]==0){
            DFS(ny,nx);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int h_max=0;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> map[i][j];
            h_max = max(h_max, map[i][j]);
        }
    }

    for(int h=1; h<=h_max;h++){
        int cnt=0;

        memset(ch, 0, sizeof(ch));
        memset(visited, 0, sizeof(visited));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(map[i][j]<h) ch[i][j]=1;
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(ch[i][j]==0 && visited[i][j]==0){
                    DFS(i,j);
                    cnt++;
                }
            }
        }

        ans = max(ans, cnt);
    }
    cout << ans << '\n';
    return 0;   
}