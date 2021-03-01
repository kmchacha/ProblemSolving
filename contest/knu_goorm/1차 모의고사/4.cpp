#include<bits/stdc++.h>
using namespace std;
int d[101010][11];
int chk[101010];	//방문 확인을 위한 배열
vector<int> cost;	//색칠 비용 
int color;	//색의 개수
vector<int> adj[101010];	//트리 구조를 관리할 인접 리스트

int go(int s, int c) {	//s: 현재 노드 번호, c: 현재 노드의 색
	int& res = d[s][c];
	if (~res) return res;	//만약 이전에 구해둔 답이 있다면 답을 반환
	res = 0;	//답을 0으로 초기화
	
	int sum = cost[c];	//현재 노드의 색칠 비용을 더해줌

	chk[s] = 1;	//방문 체크
	for (int i = 0; i < adj[s].size(); ++i) {	//모든 자식 노드를 확인
		int tmp = 2e9, next = adj[s][i];
		if (chk[next]) continue;	//이미 방문한 노드라면 스킵
		for (int j = 1; j <= color; ++j) {	//현재 자식 노드를 1번부터 color번까지의 색으로 모두 칠해봄
			if (j == c) continue;	//현재 노드와 같은 색이라면 칠하지 않고 넘어감
			tmp = min(tmp, go(next, j));	//항상 최솟값이 되도록 유지
		}
		sum += tmp;	//결과에 i번째 자식 노드를 통해 얻은 최솟값을 더해줌
	}
	res += sum;	//답을 기록
	chk[s] = 0;	//방문체크 해제 후 탐색 종료
	return res;
}
int main() {
	memset(d, -1, sizeof(d));	//모든 답을 나올 수 없는 답(-1)으로 초기화
	int n; scanf("%d %d", &n, &color);
	cost.resize(color + 1);
	for (int i = 1; i <= color; ++i)
		scanf("%d", &cost[i]);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int ans = 2e9;
	for (int i = 1; i <= color; ++i)	//1번 노드를 기준으로 모든 색을 칠해봄
		ans = min(ans, go(1, i));
	printf("%d", ans);
}