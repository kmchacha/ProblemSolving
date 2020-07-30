#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int ch[10], a[10], n, m;
void DFS(int L){
    if(L==m){
        for(int i=0;i<L;i++){
            cout << a[i] << " ";
        }
        cout << '\n'; // endl을 사용하면 시간초과 발생
        return;
    }else {
        for(int i=1;i<=n;i++){
            if(ch[i]) continue;
            ch[i]=1;
            a[L] = i;
            DFS(L+1);
            ch[i]=0;
            a[L] = 0;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    cin >> n >> m;
    DFS(0);

    return 0;
}