#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int sum[10];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int n=5, m=4;
    int a[10][10], idx=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
            sum[i] += a[i][j];
        }

        if(sum[i] > sum[idx]) idx=i;
    }
    cout << idx << " " << sum[idx];
    return 0;
}