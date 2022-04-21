#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int unf[10001];
int Find(int v){
    if(unf[v]==v) return v;
    else return unf[v]=Find(unf[v]);
}
void Union(int a, int b){
    a=Find(a);
    b=Find(b);
    if(a!=b) unf[a]=b;
}
struct Edge{
    int v1;
    int v2;
    int w;
    Edge(int a, int b, int c){
        v1=a;
        v2=b;
        w=c;
    }
    bool operator < (Edge& e){
        return w < e.w;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int n, m, res=0;
    vector<Edge> Ed;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        unf[i]=i;
    }
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        Ed.push_back(Edge(a,b,c));
    }
    for(int i=0;i<m;i++){
        cout << Ed[i].v1 << " " << Ed[i].v2 << " " << Ed[i].w << endl;
    }
    sort(Ed.begin(), Ed.end());
    for(int i=0;i<m;i++){
        int fa = Find(Ed[i].v1);
        int fb = Find(Ed[i].v2);
        if(fa!=fb) {
            res += Ed[i].w;
            Union(Ed[i].v1, Ed[i].v2);
        }
    }
    cout << res << '\n';
    return 0;
}