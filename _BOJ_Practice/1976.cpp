#include <bits/stdc++.h>

using namespace std;

int unf[205];
int Find(int v){
    if(unf[v] == v) return v;
    else return unf[v] = Find(unf[v]);
}
void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a!=b) unf[a]=b;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    int N, M;
    cin >> N;
    cin >> M;
    for(int i=1;i<=N;i++) unf[i]=i;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            int x;
            cin >> x;
            if(i <= j && x == 1) Union(i, j);
        }
    }

    int city;
    cin >> city;
    int temp = Find(city);
    int flag = 0;
    for(int i=2;i<=M;i++){
        cin >> city;
        if(Find(city)!= temp) { flag=1; break; }
    }

    if(flag==1) cout << "NO";
    else cout << "YES";
    return 0;
}