#include <bits/stdc++.h>

using namespace std;

int N;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    while(cin >> N){
        int i=0;
        if(N == 1) { cout << 1 << '\n'; continue;}
        for(long long a=1;(a*10 + 1) % N; i++, a=(a*10+1)%N);
        cout << i + 2 << '\n';
    }
    return 0;
}