#include <bits/stdc++.h>

using namespace std;

int N, happy[25], loss[25], dp[105];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> N;
    for(int i=0;i<N;i++) cin >> loss[i];
    for(int i=0;i<N;i++) cin >> happy[i];

    for(int i=0;i<N;i++){
        
        for(int j=100;j>=loss[i];j--){
            dp[j] = max(dp[j], dp[j - loss[i]] + happy[i]);
        }
    }
    cout << dp[99];
    return 0;
}