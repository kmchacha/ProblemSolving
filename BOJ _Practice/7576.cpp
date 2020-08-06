#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int m, n;
    cin >> m >> n;
    vector<vector<int> > a(n+1, vector<int>(m+1, 0));
    vector<vector<int> > BFS(n+1, vector<int>(m+1, 0));
    queue<pair<int, int> > Q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
            if(a[i][j]==1) { 
                BFS[i][j]=0;
                Q.push(make_pair(i,j));
            }
        }
    }

    while(!Q.empty()){
        pair<int, int> tmp = Q.front();
        Q.pop();
        for(int i=0;i<4;i++){
            int x=tmp.first+dx[i];
			int y=tmp.second+dy[i];
            if((x<=n && x>=1) && (y<=m && y>=1)){
                if(a[x][y] == 0){
                    a[x][y] = 1;
                    BFS[x][y] = BFS[tmp.first][tmp.second] + 1;
                    Q.push(make_pair(x, y));
                }
            }
        }
    }
    // 토마토가 하나라도 익지 못하는 경우
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==0) {
                cout << -1 << '\n';
                exit(0);
            }
            if(ans < BFS[i][j]) ans = BFS[i][j];
        }
    }

    cout << ans << '\n';

    return 0;
}