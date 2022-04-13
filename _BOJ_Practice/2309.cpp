#include <bits/stdc++.h>

using namespace std;

int arr[10], ch[10];
void dfs(int L, int sum){
    if(L==7){
        if(sum == 100) {
            for(int i=0;i<9;i++){
                if(ch[i]==1) cout << arr[i] << '\n';
            }
            exit(0);
        }
    }else {
        for(int i=0;i<9;i++){
            if(ch[i]==0){
                ch[i] = 1;
                dfs(L + 1, sum + arr[i]);
                ch[i] = 0;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    for(int i=0;i<9;i++)    cin >> arr[i];
    sort(arr, arr + 9);
    dfs(0, 0);
    return 0;
}