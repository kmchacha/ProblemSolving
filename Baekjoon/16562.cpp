#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int unf[10001], cost[10001];

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
    freopen("input.txt", "rt", stdin);
    int n, m, k, sum=0;
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        cin >> cost[i];
    }
    for(int i=1;i<=n;i++){
        unf[i]=i;
    }
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        Union(a, b);
    }
    for(int i=1;i<=n;i++){
        int v = 2147000000;
        for(int j=1;j<=n;j++){
            if(i==Find(j) && v>cost[j]){
                v = cost[j];
            }
        }

        if(v!=2147000000) sum += v;
    }

    if(sum > k) cout << "Oh no" << '\n';
    else cout << sum << '\n';

    return 0;
}