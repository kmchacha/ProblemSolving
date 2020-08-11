#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dist[501];
struct Edge{
    int s;
    int e;
    int val;
    Edge(int a, int b, int c){
        s = a;
        e = b;
        val = c;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "rt", stdin);
    vector<Edge> Ed;
    int i, n, m, a, b, c, j, s, e;
    cin >> n >> m;
    for(i=1;i<=m;i++){
        cin >> a >> b >> c;
        Ed.push_back(Edge(a,b,c));
    }  
    for(i=1;i<=n;i++){
        dist[i]=2147000000;
    }
    s=1;
    dist[s]=0; // 출발점
    for(i=1;i<=n;i++){
        for(j=0;j<Ed.size();j++){
            int u=Ed[j].s;
            int v=Ed[j].e;
            int w=Ed[j].val;
            // Relax
            if(dist[u]!=2147000000 && dist[u]+w < dist[v]){
                dist[v] = dist[u] + w;
                if(i==v) {
                    cout << "-1" << '\n';
                    exit(0);
                }
            }
        }
    }

    for(int i=2;i<=n;i++){
        if(dist[i]==2147000000) cout <<"-1" << '\n';
        else cout << dist[i] << '\n';
    }
    return 0;
}