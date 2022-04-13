#include <bits/stdc++.h>

using namespace std;

int T, N, arr[505];
int recursive(int start, int end, vector<vector<int> >& dp) {
    if(dp[start][end] != INT_MAX) return dp[start][end];

    // cout << "call " << start << " " << end << endl;
    if(start == end) return dp[start][end] = 0;
    else if(start + 1 == end) return dp[start][end] = arr[start] + arr[end];

    int sum = 0, minSum = INT_MAX, mid = start;
    for(int i=start;i<=end;i++) sum += arr[i];
    for(int i=start;i<end;i++){
        int temp = recursive(start, i, dp) + recursive(i + 1, end, dp);
        if(minSum > temp) {
            minSum = temp;
            mid = i;
        }
    }

    return dp[start][end] = dp[start][mid] + dp[mid+1][end] + sum; 
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> T;
    while(T--) {
        cin >> N;
        for(int i=1;i<=N;i++) cin >> arr[i];
        
        vector<vector<int> > v(N+1, vector<int>(N+1, INT_MAX));
        cout << recursive(1, N, v) << '\n';
    }
    return 0;
}