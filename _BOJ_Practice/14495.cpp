#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
#include <queue>

using namespace std;

long long dp[200];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int n;
    cin >> n;
    dp[1]=1;
    dp[2]=1;
    dp[3]=1;
    dp[4]=2;
    for(int i=5;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-3];
    }
    cout << dp[n] << '\n';
    return 0;
}