#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, r, ch[20];

void dfs(int s, int L){
	int i, j;
	if(L==r){
		for(j=0; j<L; j++){
			cout << ch[j] << " ";
		}
		cout << endl;
	}
	else{
		for(i=s; i<n; i++){
				ch[L]=i;
				dfs(i+1, L+1);
		}
	}
}

int main(){
	cin >> n >> r;
	dfs(0, 0);
	return 0;
}