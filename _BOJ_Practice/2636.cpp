#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int map[101][101];
int dx[]={0,1,0,-1};
int dy[]={-1,0,1,0};
queue<pair<int, int> > Q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> map[i][j];
            if(map[i][j]==1) Q.push(make_pair(i,j));
        }
    }
    int time=0, cnt;
    while(1){
        pair<int, int> tmp=Q.front();
        Q.pop();

        int flag = 0;
        for (int k = 0; k < 4; k++)
        {
            int nx = tmp.second + dx[k];
            int ny = tmp.first + dy[k];
            if (nx >= 1 && ny >= 1 && nx <= m && ny <= n && map[ny][nx] == 0)
            {
                flag = 1;
            }
        }
        if (flag == 1) map[tmp.second][tmp.first] = 0;
        else Q.push(make_pair(tmp.first, tmp.second));
        

        int flag2=0;
        cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(map[i][j]==1){
                    flag2=1;
                    cnt++;
                }
            }
        }
        if(flag2==0) break;
    }

    cout << time << '\n';
    cout << cnt << '\n';
    return 0;
}