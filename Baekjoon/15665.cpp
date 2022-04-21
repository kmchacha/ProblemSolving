#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int ans[10], n, m;
vector<int> a;

void DFS(int L){
    if(L==m){
        for(int i=0;i<L;i++){
            cout << ans[i] << " ";
        }
        cout << '\n'; 
    }else {
        int before = -1;
        for(int i=0;i<a.size();i++){
            if(i==0 || before != a[i]){
                before = a[i];
                ans[L] = a[i];
                DFS(L+1);
            }
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
    DFS(0);

    return 0;
}