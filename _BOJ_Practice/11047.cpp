#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int n, k, ans=0;
    cin >> n >> k;
    vector<int> a(n+1, 0);
    for(int i=1;i<=n;i++)   { cin >> a[i]; }
    for(int i=n;i>0;i--){
        if(k<a[i]) continue;
        
        while(1){
            if(k-a[i] < 0) break;
            k -= a[i];
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}