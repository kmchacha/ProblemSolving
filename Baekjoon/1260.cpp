#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int map[1001][1001];
int ch[1001];
queue<int> Q;

void DFS(int v){
    cout << v << " ";
    ch[v]=1;
    for(int i=1;i<=n;i++){
        if(ch[i]==0 && map[v][i]==1){
            DFS(i);
        }
    }
}
void BFS(int v){
    ch[v]=1;
    Q.push(v);

    while(!Q.empty()){
        int k=Q.front();
        Q.pop();
        cout << k << " ";
        for(int i=1;i<=n;i++){
            if(ch[i]==0 && map[k][i]==1){
                Q.push(i);
                ch[i]=1;
            }
        }
    }
}
void init(){
    for(int i=1;i<=n;i++){
        ch[i]=0;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int s;
    cin >> n >> m >> s;
    for(int i=1;i<=m;i++){
        int from, to;
        cin >> from >> to;
        map[from][to]=1;
        map[to][from]=1;
    }

    DFS(s);
    cout << '\n';
    init();
    BFS(s);

    return 0;   
}