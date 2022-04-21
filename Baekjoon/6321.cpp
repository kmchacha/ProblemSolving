#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "rt", stdin);
    int N;
    string str;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> str;
        
        cout << "String #" << i+1 << '\n';
        for(int j=0;j<str.length();j++){
            if('A' <= str[j] && str[j]<'Z') ++str[j];
            else if(str[j] == 'Z') str[j] = 'A';

            cout << str[j];
        }
        cout << "\n\n";

    }

    return 0;
}