#include <bits/stdc++.h>

using namespace std;

bool isright(int A, int B, int C){
    vector<int> v(3, 0);
    v[0] = A;
    v[1] = B;
    v[2] = C;
    sort(v.begin(), v.end());

    if(v[2] * v[2] == (v[0] * v[0] + v[1] * v[1])) return true;
    else return false;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    int A, B, C;
    cin >> A >> B >> C;
    while(A != 0 && B != 0 && C != 0) {
        if(isright(A, B, C)) cout << "right\n";
        else cout << "wrong\n";

        cin >> A >> B >> C;
    }    
    return 0;
}