#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

struct Segment {	//세그먼트 트리 구현부
	vector<int> tree;
	vector<P> range;
	vector<int> seq;
	Segment(int n) {
		++n;	
		seq.resize(n);
		int log = ceil(log2(n));
		int t = (1 << (log + 1));
		tree.resize(t);
	}

	void init(int node, int s, int e) {
		if (s == e)
			tree[node] = seq[s];
		else {
			init(node * 2, s, (s + e) / 2);
			init(node * 2 + 1, (s + e) / 2 + 1, e);
			tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
		}
	}

	int query(int node, int s, int e, int i, int j) {
		if (e < i || s > j) return -1;
		if (i <= s && e <= j) return tree[node];
		int res1 = query(node * 2, s, (s + e) / 2, i, j);
		int res2 = query(node * 2 + 1, (s + e) / 2 + 1, e, i, j);
		if (res1 == -1)
			return res2;
		else if (res2 == -1)
			return res1;
		else
			return max(res1, res2);
	}
};
int main(){
	int n, m; scanf("%d %d", &n, &m);
	Segment s(n + 1);
	for(int i = 1; i<=n; ++i)
		scanf("%d", &s.seq[i]);
	s.init(1, 1, n);
	int cnt = 0;
	ll ans = m;
	int prev = 1e9;
	for(int i = 1; i<=n; ++i){
		int res = s.query(1, 1, n, (i == n ? n : i + 1), n);	//i + 1 ~ n번째까지의 원소중 최댓값을 저장
		if(prev < s.seq[i]){	//만약 이전에 산 주식의 가격이 현재 주식의 가격보다 작다면
			prev = 1e9;
			puts("1");
		}
		else{
			if(res > s.seq[i]){	//i+1 ~ N번째 원소중 자신보다 큰 값이 있다면 주식을 구매
				prev = s.seq[i];
				puts("0");
			}
			else puts("-1");	//없다면 구매/판매를 모두 하지 않음
		}
	}
}