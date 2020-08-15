#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int dis[301][301];
int dx[]={-2,-1,1,2,2,1,-1,-2};
int dy[]={1,2,2,1,-1,-2,-2,-1};
int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
    int t;
    cin >> t;
	for(int c=0;c<t;c++){
        int n;
        cin >> n;
        int sx, sy;
        cin >> sx >> sy;
        int ex, ey;
        cin >> ex >> ey;
        memset(dis, -1, sizeof(dis));
        queue<pair<int, int> > Q;
        Q.push(make_pair(sx, sy));
        dis[sx][sy]=0;
        while(!Q.empty()) {
            pair<int, int> tmp = Q.front();
            Q.pop();
            for(int i=0; i<8; i++) {
                int x = tmp.first + dx[i];
                int y = tmp.second + dy[i];
                if(x>=0 && x<n && y>=0 && y<n && dis[x][y]==-1) {
                    Q.push(make_pair(x, y));
                    dis[x][y] = dis[tmp.first][tmp.second] + 1;
                }
            }
        }
        cout << dis[ex][ey] << '\n';
    }
	return 0;
}