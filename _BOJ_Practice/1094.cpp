#include <bits/stdc++.h>

using namespace std;

int X, answer;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> X;
	while(X != 0) {
        int r = 1;
        for(int i=0;;i++){
            if((r << 1) > X) break;
            else r = (r << 1); 
        }
        X -= r;
        answer++;
    }
    cout << answer;
    return 0;
}