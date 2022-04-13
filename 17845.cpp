#include <bits/stdc++.h>

using namespace std;

int N, K, important[10005], timee[10005], dp[10005];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> N >> K;
    for(int i=0;i<K;i++){
        cin >> important[i] >> timee[i];
    }
    for(int i=0;i<K;i++){

        for(int j=N;j>=timee[i];j--){
            dp[j] = max(dp[j], dp[j - timee[i]] + important[i]);
        }
    }
    cout << dp[N];
    return 0;
}