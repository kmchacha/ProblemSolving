#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int board[1010][1010];	//각 위치의 높이를 저장할 배열
ll d[1010][1010];	//d[i][j] = (i, j)에서 출발하여 얻을 수 있는 오르막 점수의 최솟값
int n;
int dx[] = { 1, 0 };	//오른쪽, 아래를 이동하기 위한 배열
int dy[] = { 0, 1 };	//오른쪽, 아래를 이동하기 위한 배열

ll go(int x, int y) {	//x, y는 현재 위치
	ll& res = d[x][y];
	if (~res) return res;	//만약 현재 위치에 이미 방문하여 답을 구해놨다면(답이 -1이 아니라면) 답을 리턴
	if (x == n - 1 && y == n - 1) 	//가장 오른쪽 아래에 도착했다면 0을 반환
		return d[x][y] = 0;

	ll tmp = 1e9;
	for (int i = 0; i < 2; ++i) {	//오른쪽과 아래를 확인
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < n) {	//다음 위치가 경계를 벗어나지 않는다면
			int cl = board[nx][ny] - board[x][y];	//높이차이 계산
			tmp = min(tmp, go(nx, ny) + (cl > 0 ? cl : 0));	//tmp에 다음 위치 중 최솟값을 저장
		}
	}
	return res = tmp;	//정답을 메모하고 반환
}
int main(){
	memset(d, -1, sizeof(d));	//모든 정답을 -1로 초기화
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &board[i][j]);
	printf("%lld", go(0, 0));
	return 0;
}