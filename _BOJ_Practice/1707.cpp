#include <bits/stdc++.h>

using namespace std;


bool isBipartiteGraph(vector<int> graph[], int v){
    vector<int> ch(v + 1, 0);
    int flag = 0;
    for(int i=1;i<=v;i++){
        if(ch[i] == 0) {
            queue<int> q;
            q.push(i);
            ch[i] = 1;
            while(!q.empty()){
                int size = q.size();
                int cur = q.front(); q.pop();

                for(int j=0;j<graph[cur].size();j++){
                    int next = graph[cur][j];
                    if(ch[next] == 0) {
                        ch[next] = (ch[cur] % 2) + 1;
                        q.push(next);
                    }else if(ch[next] == ch[cur]) flag = 1;
                }
            }
        }
    }
    if(flag == 1) return false;
    else return true;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    int T;
    cin >> T;
    while(T--){
        int V, E;
        cin >> V >> E;
        vector<int> graph[20005];
        for(int i=0;i<E;i++){
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        if(isBipartiteGraph(graph, V)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}