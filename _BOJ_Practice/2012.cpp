#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int n;
    long long ans=0;
    cin >> n;
    vector<int> a(n+1, 0);
    
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a.begin()+1, a.end());
    for(int i=1;i<=n;i++){
        ans += abs(i-a[i]);
    }
    cout << ans << '\n';
    return 0;
}