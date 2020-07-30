#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[1001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, i;
    cin >> n;
    dp[0]=1;
    dp[1]=1;
    for(i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
        dp[i] %= 10007;
    }
    cout << dp[n] << endl;
    return 0;
}
