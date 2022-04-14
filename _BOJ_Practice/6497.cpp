#include <bits/stdc++.h>

using namespace std;

struct Edge{
    int start, end, value;
    Edge(int a, int b, int c) {
        start = a;
        end = b;
        value = c;
    }
    bool operator < (const Edge &e) const {
        return value < e.value;
    }
};
int Find(int v, int *unf){
    if(unf[v] == v) return v;
    else return unf[v] = Find(unf[v], unf);
}
void Union(int a, int b, int* unf){
    a = Find(a, unf);
    b = Find(b, unf);
    if(a != b) unf[a] = b;
}
int N, M;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    while(1){
        cin >> M >> N;
        if(N == 0 && M == 0) break;

        int x, y, z, sum=0, unf[200005], cnt=0, selected=0;
        vector<Edge> graph;
        for(int i=0;i<M;i++) unf[i] = i;
        for(int i=0;i<N;i++){
            cin >> x >> y >> z;
            graph.push_back(Edge(x, y, z));
            sum += z;
        }
        sort(graph.begin(), graph.end());
        for(int i=0;i<N;i++){
            int s = graph[i].start;
            int e = graph[i].end;
            int v = graph[i].value;

            if(Find(s, unf) != Find(e, unf)) {
                Union(min(s,e), max(s,e), unf);
                cnt++;
                selected += v;
                if(cnt == M-1) break;
            }
        }
        cout << sum - selected << '\n';
    }

    return 0;
}