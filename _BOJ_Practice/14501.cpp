#include <bits/stdc++.h>

using namespace std;

struct job {
    int t, p;
    job(int a, int b){
        t = a;
        p = b;
    }
};

int N, ans;
vector<job> v;
void solve(int L, int sum){
    ans = max(ans, sum);
    if(L >= N) return;
    
    if(L + v[L].t <= N) solve(L + v[L].t, sum + v[L].p);
    if(L + 1 <= N) solve(L + 1, sum);
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> N;
    for(int i=0;i<N;i++){
        int T, P;
        cin >> T >> P;
        v.push_back(job(T, P));
    }
    solve(0, 0);
    cout << ans;
    return 0;
}