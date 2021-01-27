#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
int n, ch[2001], path[2001], a[2001], ans;
void DFS(int L){
    if(L==n){
        int cnt = 0;
        for(int i=1;i<n;i++){
            if(path[i]>path[i-1]) cnt++;
        }

        ans = max(cnt, ans);
    }else {
        for(int i=1;i<=n;i++){
            if(ch[i]==0){
                ch[i]=1;
                path[L]=a[i];
                DFS(L+1);
                ch[i]=0;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    DFS(0);
    cout << ans << '\n';
    return 0;
}