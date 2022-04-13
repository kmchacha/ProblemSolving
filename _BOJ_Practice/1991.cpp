#include <bits/stdc++.h>

using namespace std;

int N;
char arr[30][2];
void pre_dfs(int node) {
    cout << char('A' + node);

    if(arr[node][0] != '.' && arr[node][0] >= 'A' && arr[node][0] <= 'Z') pre_dfs(arr[node][0] - 'A');
    if(arr[node][1] != '.' && arr[node][1] >= 'A' && arr[node][1] <= 'Z') pre_dfs(arr[node][1] - 'A');
}
void post_dfs(int node) {
    if(arr[node][0] != '.' && arr[node][0] >= 'A' && arr[node][0] <= 'Z') post_dfs(arr[node][0] - 'A');
    if(arr[node][1] != '.' && arr[node][1] >= 'A' && arr[node][1] <= 'Z') post_dfs(arr[node][1] - 'A');
    cout << char('A' + node);
}
void dfs(int node) {
    if(arr[node][0] != '.' && arr[node][0] >= 'A' && arr[node][0] <= 'Z') dfs(arr[node][0] - 'A');
    cout << char('A' + node);
    if(arr[node][1] != '.' && arr[node][1] >= 'A' && arr[node][1] <= 'Z') dfs(arr[node][1] - 'A');
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> N;
    for(int i=0;i<N;i++){
        char alphabat;
        cin >> alphabat;
        for(int j=0;j<2;j++) cin >> arr[alphabat - 'A'][j];
    }
    pre_dfs(0); cout << '\n';
    dfs(0); cout << '\n';
    post_dfs(0);
    return 0;
}