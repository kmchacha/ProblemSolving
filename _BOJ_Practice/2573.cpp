#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int map[301][301], ch[301][301], tmp[301][301];
int dx[]={0,1,0,-1};
int dy[]={-1,0,1,0};
int n, m, ans=0, max_v;

queue<pair<int, int> > Q;
void BFS(int x, int y){
    Q.push(make_pair(x, y));
    ch[x][y] = 1;
    while (!Q.empty())
    {
        int xxx = Q.front().second;
        int yyy = Q.front().first;
        Q.pop();
        for (int k = 0; k < 4; k++)
        {
            int nnx = xxx + dx[k];
            int nny = yyy + dy[k];
            if (nnx >= 1 && nny >= 1 && nnx <= m && nny <= n && map[nny][nnx] > 0 && ch[nny][nnx] == 0)
            {
                ch[nny][nnx] = 1;
                Q.push(make_pair(nny, nnx));
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> map[i][j];
            max_v = max(max_v, map[i][j]);
        }
    }

    while(1){
        int count=0;
        memset(tmp, 0 , sizeof(tmp));
        memset(ch, 0 , sizeof(ch));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (map[i][j] > 0 && ch[i][j] == 0)
                {
                    BFS(i, j);
                    count++;
                }
            }
        }

        if(count >= 2) {cout << ans << '\n'; break;}
        if(count == 0) {cout << "0" << '\n'; break;}

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(map[i][j]>0){
                    int cnt=0;
                    for(int k=0;k<4;k++){
                        int nx = j + dx[k];
                        int ny = i + dy[k];
                        if(nx>=1 && ny>=1 && nx<=m && ny<=n && map[ny][nx]==0){
                            cnt++;
                        }
                    }

                    if(map[i][j]-cnt>0) tmp[i][j]=map[i][j]-cnt;
                    else tmp[i][j]=0;
                }
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                map[i][j]=tmp[i][j];
            }
        }

        ans++;
    }

    return 0;
}