#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "rt", stdin);
    string str;
    cin >> str;
    for(int i=0;i<str.length();i++){
        str[i] = str[i] - 3;
        if(str[i] >= 'A' && str[i] <= 'Z') cout << str[i];
        else {
            str[i] = str[i] + 26;
            cout << str[i];
        }
    }
    return 0;
}