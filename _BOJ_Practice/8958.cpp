#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "rt", stdin);
    int T;
    string str;
    cin >> T;
    for(int i=0;i<T;i++){
        int sum=0, cnt=0;
        
        cin >> str;
        for(int j=0;j<str.size();j++){
            if(str[j] == 'O') {
                cnt++;
                sum+=cnt;
            }else cnt=0;
        }

        cout << sum << '\n';
    }
    return 0;
}