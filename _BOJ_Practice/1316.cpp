#include <bits/stdc++.h>
using namespace std;

bool isGroup(string& str){
    bool check[26] = { false };

    string temp = str;
    while(!temp.empty()){
        if(!check[temp[0]-'a']) check[temp[0]-'a'] = true;
        else return false;

        int idx;
        for(idx=1;idx<temp.size();idx++){
            if(temp[0] != temp[idx]) break;
        }
        temp = temp.substr(idx);
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "rt", stdin);
    int N, res=0;
    string str;

    cin >> N;
    for(int i=0;i<N;i++){
        cin >> str;
        if(isGroup(str)) res++;
    }
    cout << res << '\n';
    return 0;
}