#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "rt", stdin);
    long long N;
    int init;
    cin >> N;
    cin >> init;
    if(N >= 6) cout << "Love is open door";
    else {
        for(long long i=2;i<=N;i++){
            if(i % 2 == 1) cout << init << '\n';
            else cout << (init+1)%2 << '\n';
        }
    }
    return 0;
}