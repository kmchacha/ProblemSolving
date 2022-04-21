#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "rt", stdin);
    int res[30] = { 0 };
    string str;
    cin >> str;
    for(int i=0;i<str.size();i++){
        if(islower(str[i])) str[i] = str[i] - 'a' + 'A';

        res[str[i]-'A']++;
    }
    int Idx = 0, isOne=0;
    for(int i=0;i<26;i++){
        if(res[i] > res[Idx]) Idx=i;
    }

    for(int i=0;i<26;i++){
        if(res[i] == res[Idx]) isOne++;
    }
    if(isOne > 1) cout << "?" << '\n';
    else cout << char('A'+Idx) << '\n';

    
    return 0;
}