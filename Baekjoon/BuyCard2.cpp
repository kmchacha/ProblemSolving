#include <iostream>
#include <algorithm>
 using namespace std;

int dp[1001];
int a[1001];

int
main(int argc, const char* argv[]){


    int n;

    cin >> n;
    for(int i = 1 ; i <= n; i++){
        cin >> a[i];
    }

    for (int i = 1; i <= n ; i++){
        dp[i] = -1;
    }
    dp[0] = 0;

    for(int i = 1 ; i <= n ; i++){
        for (int j = 1 ; j <= i; j++) {
            if(dp[i] == -1 || dp[i] > dp[i-j] + a[j]){
                dp[i] = dp[i-j] + a[j];
            }
        }
    }

    cout << dp[n] << endl;
    
    return 0;
}