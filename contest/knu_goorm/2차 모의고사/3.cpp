//#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int d[11]; // 도시
int count(int num){	//num에 켜져있는 비트를 세어주는 함수
	int res = 0;
	while(num){	//num > 0인 동안 반복
		num -= (num & -num);	//num에 켜져있는 비트 중, 최하위 비트를 제거
		++res;
	}
	return res;
}
int main() {
	int n; scanf("%d", &n);
	for(int i = 0; i<n; ++i){
		for(int j = 0; j<n; ++j){
			int num; scanf("%d", &num);
			if(i == j) num = 1;	//계산의 편의를 위해 자기 자신으로 가는 간선은 연결되어 있다고 가정
			d[i] |= (num << j);	//i번 정점과 j번 정점을 연결해주는 인접 행렬 역할
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << d[i] << " ";
		}
		cout << endl;
	}

	int ans = 0;
	for(int i = (1 << n) - 1; i; --i){	//모든 정점이 포함된 상태부터 하나의 정점만을 포함하는 상태까지 반복
		int st = i;
		for(int j = 0; j<n; ++j)
			if(i & (1 << j)) st &= d[j];	//찾고자 하는 정점 집합(i)에 포함되는 경우만 연결된 간선을 AND 연산
		if((st & i) == i)	//만약 AND 연산한 결과가 찾고자 하는 정점 집합과 같은 경우
			ans = max(ans, count(i));	//정답을 최댓값으로 업데이트
	}
	printf("%d", ans);
}