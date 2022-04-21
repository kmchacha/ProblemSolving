#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int ans[10],  n, m;
vector<int> a;

void DFS(int L, int start){
    if(L==m){
        for(int i=0;i<L;i++){
            cout << ans[i] << " ";
        }
        cout << '\n'; 
    }else {
        for(int i=start;i<n;i++){

            ans[L] = a[i];
            DFS(L + 1, i + 1);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int k;
        cin >> k;
        a.push_back(k);
    }
    sort(a.begin(), a.end());

    DFS(0,0);

    return 0;
}