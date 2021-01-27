#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string str[101];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","rt",stdin);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> str[i];
    }
    char ch = str[1][0];
    int flag = 0;
    for(int i=1;i<=n;i++){
        if(str[i][0] != ch || str[i][str[i].size()-1] != ch) flag=1;
    }

    if(flag==1) cout << 0;
    else cout << 1;

    return 0;
}