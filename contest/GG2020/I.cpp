#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int n, ans=2147000000;
    cin >> n;
    vector<int> a(2*n + 1);
    for(int i=1;i<=2*n;i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for(int i=1;i<=n;i++){
        int sum=0;
        sum += (a[i] + a[n*2-i+1]);
        if(sum < ans) ans = sum;
    }
    cout << ans << '\n';
    return 0;
}