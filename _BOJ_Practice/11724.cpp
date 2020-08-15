#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, ch[1001];
vector<int> a[1001];
void DFS(int L){
    ch[L] = 1;
    for(int i=0;i<a[L].size();i++){
        int next = a[L][i];
        if(ch[next]==0){
            DFS(next);
        }
    }
}
int main(){
    //freopen("input.txt", "rt", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt=0;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int from, to;
        cin >> from >> to;
        a[from].push_back(to);
        a[to].push_back(from);
    }

    for(int i=1;i<=n;i++){
        if(ch[i]==0){
            DFS(i);
            cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}