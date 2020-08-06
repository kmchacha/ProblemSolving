#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[10], n, m;
void DFS(int L, int start){
    if(L==m){
        for(int i=0;i<L;i++){
            cout << a[i] << " ";
        }
        cout << '\n'; // endl을 사용하면 시간초과 발생
        return;
    }else {
        for(int i=start;i<=n;i++){
            a[L] = i;
            DFS(L+1,start);
            a[L] = 0;
            start+=1;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    DFS(0,1);

    return 0;
}