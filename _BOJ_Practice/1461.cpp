#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int n, m, ans=0;
    cin >> n >> m;
    vector<int> loc(n+1);
    for(int i=1;i<=n;i++){
        cin >> loc[i];
    }
    // -37 2 -6 -39 -29 11 -28
    // -39 -37 -29 -28 -6 2 11
    sort(loc.begin()+1, loc.end());
    for(int i=1;i<=n;i+=m){
        ans += (loc[n-i+1]>0) * loc[n-i+1] - (loc[i] < 0)* loc[i];
        //cout << (loc[n-i+1]>0) << " * " << loc[n-i+1] << " - " << (loc[i] < 0) << " * " << loc[i] << '\n';
    }
    ans = ans * 2 - max(abs(loc[1]), abs(loc[n]));
    // for(int i=1;i<=n;i++){
    //     if(loc[i] > 0) q_plus.push(loc[i]);
    //     else q_minus.push(loc[i]);
    // }
    // if(abs(loc[1]) > abs(loc[n])) {
    //     ans += abs(loc[1]);
    //     int i;
    //     for(i=3;i<=n;i+=m){
    //         ans += (abs(loc[i]) * 2);
    //     }
    //     for(int i=2;i<q_minus.size();i++){

    //     }
    // }
    // else {
    //     ans += abs(loc[n]);
    //     for(int i=1;i<n;i+=m){

    //     }
    // }
    cout << ans << '\n';
    return 0;
}