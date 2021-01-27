#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int unf[500001];

int Find(int v){
    if(v==unf[v]) return v;
    else return unf[v]=Find(unf[v]);
}
void Union(int a, int b){
    a=Find(a);
    b=Find(b);
    if(a!=b) unf[a]=b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int n, m, cnt=0, ans=0;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        unf[i]=i;
    }
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        if(Find(a)==Find(b)) {
            if(ans==0) ans = cnt;
        }
        Union(a,b);
        cnt++;
    }
    if(ans != 0) {
        cout << ans+1 << '\n';
    }
    else cout << 0 << '\n';
    return 0;
}