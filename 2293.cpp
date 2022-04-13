#include <bits/stdc++.h>

using namespace std;

int coin[105], dp[10005];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    int N, K;
    cin >> N >> K;
    for(int i=0;i<N;i++) cin >> coin[i];
    dp[0] = 1;
    for(int i=0;i<N;i++){
        for(int j=1;j<=K;j++){
            if(j - coin[i] >= 0) {
                dp[j] = dp[j] + dp[j - coin[i]];
            }
        }
    }
    cout << dp[K];
    return 0;
}