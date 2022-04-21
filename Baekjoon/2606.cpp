#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

queue<int> Q;
int computer_ch[101], cnt;
vector<int> a[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int from, to;
        cin >> from >> to;
        a[from].push_back(to);
        a[to].push_back(from);
    }
    
    Q.push(1);
    computer_ch[1]=1;
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();
        for(int i=0;i<a[v].size();i++){
            if(computer_ch[a[v][i]]==0){
                computer_ch[a[v][i]]=1;
                cnt++;
                Q.push(a[v][i]);
            }
        }
    }
    cout << cnt << '\n';
    return 0;   
}