#include<bits/stdc++.h>
using namespace std;
struct EDGE {	//간선의 정보를 저장할 구조체
	int from, to;
    EDGE(int a, int b){
        from = a;
        to = b;
    }
};
int n;	//정점의 개수
int dist[2020];	//트리의 지름을 구할 때 사용하기 위한 거리 저장 배열
bool chk[2020];	//트리의 지름을 구할 때 사용하기 위한 방문 체크 배열
vector<int> adj[2020];	//트리 구조를 인접 리스트로 표현
vector<EDGE> edges;	//간선 정보를 저장할 배열
 
//DFS
void go(int s, int w, int e) {	//s: 현재 정점, w: 현재까지 거리, e: 사용하지 않을 간선 번호
	if (chk[s]) return;	//이미 방문한 정점이라면 탐색 중단
	chk[s] = 1;	//현재 위치 방문 체크
	dist[s] = w;	//현재 위치의 거리 기록
	for (int i = 0; i < adj[s].size(); ++i) {	//현재 정점과 연결된 모든 정점 확인
		if ((edges[e].from == s && edges[e].to == adj[s][i])	//만약 사용하지 않는 간선이라면 탐색 중단
			|| (edges[e].from == adj[s][i] && edges[e].to == s)) continue;
		go(adj[s][i], w + 1, e);
	}
}
 
int GetD(int s) {	//두 트리의 지름을 구하여 두 지름의 곱을 구해주는 함수, s는 사용하지 않을 간선의 번호
	memset(dist, 0, sizeof(dist));	//모든 정점의 거리를 0으로 초기화
	memset(chk, 0, sizeof(chk));	//모든 방문 체크를 방문 안했음으로 초기화
	
	go(edges[s].from, 1, s);	//DFS 수행(1)
	
	int ans = 0, ansI = 0;	//DFS를 시작한 정점으로부터 가장 멀리 떨어진 점을 구함
	for (int i = 1; i <= n; ++i)
		if (dist[i] > ans)
			ans = dist[i], ansI = i;

	memset(dist, 0, sizeof(dist));
	memset(chk, 0, sizeof(chk));
	
	go(ansI, 1, s);	//처음 시작한 정점에서 가장 멀리 떨어진 정점에서 다시 DFS 수행
	ans = 0;
	for (int i = 1; i <= n; ++i)	//첫 번째 트리의 지름은 해당 정점에서 가장 멀리 떨어진 정점까지의 거리
		ans = max(ans, dist[i]);
	int ans1 = ans - 1;
 
	memset(dist, 0, sizeof(dist));
	memset(chk, 0, sizeof(chk));
	
	//두 번째 트리의 지름을 구함
	go(edges[s].to, 1, s);
	ans = 0, ansI = 0;
	
	for (int i = 1; i <= n; ++i)
		if (dist[i] > ans)
			ans = dist[i], ansI = i;
	
	memset(dist, 0, sizeof(dist));
	memset(chk, 0, sizeof(chk));
	
	go(ansI, 1, s);
	ans = 0;
	
	for (int i = 1; i <= n; ++i)
		ans = max(ans, dist[i]);
	
	int ans2 = ans - 1;
	return ans1 * ans2;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		adj[a].push_back(b);	//a, b를 입력받아 인접 리스트 / 간선 정보에 저장
		adj[b].push_back(a);
		edges.push_back(EDGE(a, b));
	}
	int ans = 0;
	for (int i = 0; i < edges.size(); ++i)	//모든 간선을 하나씩 지워보며 정답을 구함
		ans = max(ans, GetD(i));
	printf("%d", ans);
}