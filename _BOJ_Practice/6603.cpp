#include <bits/stdc++.h>

using namespace std;

int N, arr[105], ch[105], path[105];
void dfs(int L, int s){
    if(L == 6) {
        for(int i=0;i<6;i++){
            cout << path[i] << " ";
        }
        cout << '\n';
    }else {
        for(int i=s;i<N;i++){
            if(ch[i]==0) {
                ch[i]=1;
                path[L]=arr[i];
                dfs(L+1, i + 1);
                ch[i]=0;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    while(1){
        cin >> N;
        if(N == 0) break;

        for(int i=0;i<N;i++) cin >> arr[i];
        dfs(0, 0);
        cout << '\n';
    }
    return 0;
}