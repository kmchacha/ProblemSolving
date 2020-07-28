/*
'******************************************************************************
' 파일명    : pps89.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/28
' 문제      : 토마토(BFS 활용)
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>
using namespace std;
int m, n, tom[1010][1010], res = -2147000000, dis[1010][1010];
int dx[4] = {0, 1, 0, -1}; 
int dy[4] = {-1, 0, 1, 0};
struct Loc {
	int x, y;
	Loc(int a, int b) {
		x = a;
		y = b;
	}
};
queue<Loc> Q;
int main() {
	cin >> m >> n;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
            cin >> tom[i][j];
			if(tom[i][j] == 1) {
				Q.push(Loc(i, j));
			}
		}
	}
	while(!Q.empty()) {
		Loc tmp = Q.front();
		Q.pop();
		for(int i = 0; i < 4; i++) {
			int xx=tmp.x+dx[i];
			int yy=tmp.y+dy[i];
			if(tom[xx][yy] == 0) {
				if(xx>=1 && xx<= n && yy>=1 && yy<= m) {
					Q.push(Loc(xx, yy));
					tom[xx][yy] = 1;
					dis[xx][yy] = dis[tmp.x][tmp.y] + 1;
				}
			}
		}
	}
	int f = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(tom[i][j] == 0) f = 0;
		}
	}
	if(f == 1) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				if(res<dis[i][j]) res = dis[i][j];
			}
		}
		cout << res << endl;
	}
	else cout << "-1" << endl;
	return 0;
}