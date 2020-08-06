#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define x first
#define y second
using namespace std;
int dx[4]={-1, 0, 1, 0};
int dy[4]={0, 1, 0, -1};
int main(){
	//ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
    int n, m;
    cin >> n >> m;
	vector<vector<int> > board(n+1, vector<int>(m+1, 0));
    vector<vector<int> > ch(n+1, vector<int>(m+1, 0));
	vector<vector<int> > dis(n+1, vector<int>(m+1, 0));
	queue<pair<int, int> > Q;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
            scanf("%1d", &board[i][j]);
		}
	}
	Q.push(make_pair(1, 1));
    ch[1][1]=1;
    dis[1][1]=1;
	while(!Q.empty()) {
		pair<int, int> tmp = Q.front();
		Q.pop();
		for(int i=0; i<4; i++) {
			int x=tmp.x + dx[i];
			int y=tmp.y + dy[i];
			if(x>=1 && x<=n && y>=1 && y<=m) {
				if(ch[x][y]==0 && board[x][y]==1){
                    Q.push(make_pair(x, y));
                    dis[x][y] = dis[tmp.x][tmp.y] + 1;
                    ch[x][y] = 1;
                }
			}
		}
	}
	// for(int i=1; i<=n; i++) {
	// 	for(int j=1; j<=m; j++) {
	// 		cout << dis[i][j] << " ";
	// 	}
    //     cout << endl;
	// }
    cout << dis[n][m] << '\n';
	return 0;
}