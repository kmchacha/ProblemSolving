#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, m;
vector<int> a[101], dis(101);
queue<int> Q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int p1, p2;
    cin >> n;
    cin >> p1 >> p2;
    cin >> m;

    for(int i=0;i<m;i++){
        int from, to;
        cin >> from >> to;
        a[from].push_back(to);
        a[to].push_back(from);
    }
    Q.push(p1);
    while(!Q.empty()){
        int v=Q.front();
        Q.pop();
        for(int i=0;i<a[v].size();i++){
            if(dis[a[v][i]]==0){
                dis[a[v][i]] = dis[v] + 1;
                Q.push(a[v][i]);
            }
        }
    }
    if(dis[p2]==0) cout << "-1" << '\n';
    else cout << dis[p2] << '\n';

    return 0;   
}