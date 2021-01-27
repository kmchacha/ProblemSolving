#include <iostream>
#include <algorithm>

using namespace std;

int a[100002];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","rt",stdin);
    int n;
    long long ans=0;
    cin >> n;
    for(int i=1;i<=n;i++)   cin >> a[i];
    for(int i=1;i<n;i++){
        long long sum = a[i], minn=a[i];
        for(int j=i+1;j<=n;j++){
            sum += a[j];
            minn = min(minn, (long long)a[j]);
            ans = max(ans, sum*minn);
        }
    }
    cout << ans;
    return 0;
}