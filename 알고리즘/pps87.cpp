/*
'******************************************************************************
' 파일명    : pps87.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/28
' 문제      : 섬나라 아일랜드(BFS)
'******************************************************************************
*/
#include<iostream>
#include <vector>
#include <algorithm>
#include<queue>
using namespace std;
int n, map[30][30], cnt=0; 
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}; 
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
struct Loc{
	int x;
	int y;
	Loc(int a, int b) {
		x = a;
		y = b;
	}
};
queue<Loc> Q;
int main() {
	//freopen("input.txt", "rt", stdin);
	int i, j;
	cin >> n;
	for(i = 1; i <= n; i++) for(j = 1; j <= n; j++) scanf("%d", &map[i][j]);
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= n; j++) {
			if(map[i][j] == 1) {
				Q.push(Loc(i, j));
				map[i][j] = 0;
				while(!Q.empty()) {
					Loc tmp = Q.front();
					Q.pop();
					for(int i = 0; i < 8; i++) {
						int xx=tmp.x+dx[i];
						int yy=tmp.y+dy[i];
						if(map[xx][yy] == 1) {
							Q.push(Loc(xx, yy));
							map[xx][yy]= 0;
						}
					}
				}
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}