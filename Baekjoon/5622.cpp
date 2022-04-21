#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "rt", stdin);
    int res=0;
    string str;
    cin >> str;
    for(int i=0;i<str.size();i++){
        if(str[i] >= 'A' && str[i] <= 'C') res += 3;
        else if(str[i] >= 'D' && str[i] <= 'F') res += 4;
        else if(str[i] >= 'G' && str[i] <= 'I') res += 5;
        else if(str[i] >= 'J' && str[i] <= 'L') res += 6;
        else if(str[i] >= 'M' && str[i] <= 'O') res += 7;
        else if(str[i] >= 'P' && str[i] <= 'S') res += 8;
        else if(str[i] >= 'T' && str[i] <= 'V') res += 9;
        else if(str[i] >= 'W' && str[i] <= 'Z') res += 10;
    }
    cout << res;
    return 0;
}