#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int map[1001][1001];
vector<vector<int> > cost(1001, vector<int>(1001, 2147000000));

queue<pair<int, int> > Q;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

// 필요한 최소 도로 건설 비용을 구하는 프로그램을 작성하라
// [0] 단위도로가 이미 존재                    [1] 단위 도로가 없고 1의 비용으로 도로 건설 가능
// [2] 단위도로가 없고 2의 비용으로 도로 건설 가능  [-1]은 x로 표시된 단위 격자로 그 위치에 단위 도로를 건설할 수 없는 상태
//  종료조건을 어떻게 해주어야할지 막막하다
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("input1.txt", "rt", stdin);
    int m, n;
    cin >> m >> n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin >> map[i][j];
        }
    }
    Q.push(make_pair(1,1));
    cost[1][1]=map[1][1];
    while(!Q.empty()){
        pair<int, int> tmp = Q.front();
        Q.pop();
        int cur_y = tmp.first;
        int cur_x = tmp.second;

        //cout << cur_y << " " << cur_x << endl;
        if(cur_y==m && cur_x==n) break;

        for(int i=0;i<4;i++){
            int ny = cur_y + dy[i];
            int nx = cur_x + dx[i];
            if(ny>=1 && nx>=1 && ny<=m && nx<=n && map[ny][nx]!=-1){
                if(cost[ny][nx] >= cost[cur_y][cur_x]+ map[ny][nx]){
                    cost[ny][nx] = cost[cur_y][cur_x] + map[ny][nx];
                    Q.push(make_pair(ny,nx));
                }
            }
        }
    }
    if(cost[m][n]==2147000000) cout << "-1" << '\n';
    else cout << cost[m][n] << '\n';
    // for(int i=1;i<=m;i++){
    //     for(int j=1;j<=n;j++){
    //         cout << map[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(cost[i][j] == 2147000000) cout << "- ";
            else cout << cost[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}