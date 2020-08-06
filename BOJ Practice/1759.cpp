#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int L, C, ch[20];
char a[20];
void DFS(int v, int u){
    if(v==L){
        int con=0, vow=0;
        
        for(int i=0;i<C;i++){
            if(ch[i]==1){
                if(a[i]=='a' || a[i]=='e' || a[i] == 'i' || a[i]=='o' || a[i]=='u'){
                    // 모음 갯수
                    vow++;
                }else {
                    // 자음 갯수
                    con++;
                }
            }
        }
        
        if(vow>=1 && con>=2) {
            for(int i=0;i<C;i++){
                if(ch[i]==1){
                    cout << a[i];
                }
            }
            cout << '\n';
        }
    }else{
        for(int i=u;i<C;i++){
            if(ch[i]==0){
                ch[i]=1;
                DFS(v+1, i+1);
                ch[i]=0;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    cin >> L >> C;
    for(int i=0;i<C;i++){
        cin >> a[i];
    }
    sort(a,a+C);
    DFS(0,0);
    return 0;
}