#include<bits/stdc++.h>
using namespace std;
int chk[5050505];	//각 숫자별로 포함된 3, 6, 9의 개수를 저장하는 배열

void go(int s, int cnt) {	//s는 현재 숫자, cnt는 현재 숫자에 포함된 3, 6, 9의 개수
	if (s > 5000000) return;	//만약 현재 숫자가 500만보다 크다면 탐색 종료
	chk[s] = cnt;	//현재 숫자의 3, 6, 9 개수를 기록
	for (int i = 0; i < 10; ++i) 	//0부터 9까지 반복하며
		if (i || (i == 0 && s)) 	//i가 0이 아니거나, i가 0이면 s가 0이 아닌 경우 탐색을 계속 진행
			go(s * 10 + i, cnt + (i && i % 3 == 0)); //현재 숫자에 i를 추가하고, i가 3, 6, 9중 하나라면 cnt를 1 증가
}

int main(){
	int n, e, c;
	scanf("%d %d %d", &n, &e, &c);
	go(0, 0);
	int ans = 0;
	
	for (int i = c; i <= e; i += n)	// 두 번째 방법을 이용한 정답 체크
		ans += chk[i];
	
	printf("%d", ans);
}