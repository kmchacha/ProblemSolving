#include<bits/stdc++.h>
using namespace std;
int main() {
	int n; scanf("%d\n", &n);
	queue<int> white, blue;	//청팀, 백팀 팀원을 관리할 두 개의 큐 선언
	for (int i = 0; i < n; ++i) {
		char c; 
		scanf("%c", &c);
		if (c == 'W') white.push(i);	//청팀 백팀을 구분하여 큐에 push
		else blue.push(i);
	}
	
	while(white.size() && blue.size()){
		int a = white.front(); white.pop();
		int b = blue.front();  blue.pop();	
		if(a > b) {
			blue.push(b + n);
		}else {
			white.push(a + n);
		}
	}
	if(white.size()){
		cout << "0";
	}else cout << "1";
}