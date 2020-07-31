// Longest Increasing Subsequence 11053
#include <iostream>
#include <string>
#include <vector>

int
main(int argc, const char* argv[])
{
    using namespace std;

    int n;

    cin >> n;

    int a[1000];
    for(int i = 0; i < n ; i ++){
        cin >> a[i];
    }
   
    int dp[1000];
    int max= 0;
    for(int i = 0 ; i < n ; i++) {
        dp[i] = 1;
        for(int j = i-1; j >= 0; j--) {
            if(a[i] > a[j] && dp[i] <= dp[j]) {
                dp[i] = dp[j] + 1;
                if(max < dp[i]) max = dp[i];
            }
        }
    }
    for(int i = 0 ; i< n; i++){
        cout << dp[i] << endl;
    }

    cout << max << endl;

    return 0;
}