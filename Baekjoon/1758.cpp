#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>

using namespace std;

int compare(int a, int b){
    return a>b;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int n;
    long long ans=0;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a.begin()+1,a.end(), compare);
    // 생각했던 돈 - (받은 등수 -1)
    for(int i=1;i<=n;i++){
        long long rst = a[i] - (i-1);
        if(rst > 0) ans += rst;
    }
    cout << ans << '\n';
    return 0;
}