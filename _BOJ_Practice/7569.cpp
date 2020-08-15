#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int dx[]={0,1,0,-1,0,0};
int dy[]={-1,0,1,0,0,0};
int dz[]={0,0,0,0,1,-1};
int map[101][101][101], dis[101][101][101];

queue<pair<pair<int, int>, int> > Q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int n, m, h;
    cin >> n >> m >> h;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=n;k++){
                cin >> map[i][j][k];
                if(map[i][j][k]==1) Q.push(make_pair(make_pair(i,j),k));
            }
        }
    }
    while(!Q.empty()){
        int cur_z = Q.front().first.first;
        int cur_x = Q.front().second;
        int cur_y = Q.front().first.second;
        Q.pop();
        //cout << cur_x << " " << cur_y << " " << cur_z << endl;
        for(int i=0;i<6;i++){
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];
            int nz = cur_z + dz[i];
            if(nx>=1 && ny>=1 && nz>=1 && nx<=n && ny<=m && nz<=h && dis[nz][ny][nx]==0 && map[nz][ny][nx]==0){
                dis[nz][ny][nx] = dis[cur_z][cur_y][cur_x]+1;
                map[nz][ny][nx] = 1;
                Q.push(make_pair(make_pair(nz,ny),nx));
            }
        }
    }
    int flag=0, ans=-2147000000;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=n;k++){
                ans = max(ans, dis[i][j][k]);
                if(map[i][j][k]==0) {
                    flag=1;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag) break;
    }

    if(flag) cout << "-1" << '\n';
    else cout << ans << '\n';   

    return 0;   
}