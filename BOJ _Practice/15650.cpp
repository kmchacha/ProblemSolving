#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int ch[10], a[10], n, m;
void DFS(int L, int start){
    if(L==m){
        for(int i=0;i<L;i++){
            cout << a[i] << " ";
        }
        cout << '\n'; // endl을 사용하면 시간초과 발생
        return;
    }else {
        for(int i=start;i<=n;i++){
            //if(ch[i]) continue;

            //ch[i]=1;
            a[L] = i;
            DFS(L+1, i+1);
            //ch[i]=0;
            a[L] = 0;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    DFS(0, 1);

    return 0;
}