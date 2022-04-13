#include <bits/stdc++.h>

using namespace std;

int N, r, c, answer;
void solve(int y1, int x1, int size){
    if(y1 == r && x1 == c) {
        cout << answer;
        return;
    } 
    
    if(r < y1 + size && r >= y1  && c < x1 + size && c >= x1) {
        solve(y1, x1, size/2);
        solve(y1+size/2, x1, size/2);
        solve(y1,x1+size/2,size/2);
        solve(y1+size/2,x1+size/2,size/2);
    }else answer += size*size;
    
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> N >> c >> r;
    solve(0, 0, (1<<N));
    return 0;   
}