#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int ans[10], a[10], ch[10], n, m;
void DFS(int L){
    if(L==m){
        for(int i=0;i<L;i++){
            cout << ans[i] << " ";
        }
        cout << '\n'; // endl을 사용하면 시간초과 발생
        return;
    }else {
        for(int i=1;i<=n;i++){
            if(ch[i]) continue;
            
            ch[i]=1;
            ans[L] = a[i];
            DFS(L+1);
            ch[i]=0;
            ans[L] = 0;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);

    DFS(0);

    return 0;
}