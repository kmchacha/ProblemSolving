#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

string str[20001];

bool compare(string& s1, string& s2){
    if(s1.length() != s2.length()) return s1.length() < s2.length();
    else {
        int n = s1.length();
        for(int i=0;i<n;i++){
            if(s1[i] != s2[i]) return s1[i] < s2[i];
            else continue;
        }
        return s1 < s2;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "rt", stdin);
    int n;
    cin >> n;
    for(int i=0;i<n;i++)    cin >> str[i];
    sort(str, str+n, compare);
    cout << str[0] << '\n';
    for(int i=1;i<n;i++)    {
        if(str[i] != str[i-1])  cout << str[i] << '\n';
    }
    return 0;
}