#include <bits/stdc++.h>

using namespace std;

int N, answer[100005];
vector<int> graph[100005];
void dfs(int v){

    for(int i=0;i<graph[v].size();i++){
        int next = graph[v][i];
        if(answer[next] == 0) {
            answer[next] = v;
            dfs(next);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> N;
    for(int i=0;i<N-1;i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1);
    for(int i=2;i<=N;i++) cout << answer[i] << '\n';
    return 0;
}