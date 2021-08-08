#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "rt", stdin);
    string str;
    cin >> str;
    for(int i=0;i<str.length();i++){
        if(i!=0 && i%10==0) cout << '\n';
        cout << str[i];
    }
    return 0;
}