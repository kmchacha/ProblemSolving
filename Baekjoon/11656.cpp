#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string s[1005];
int main(int argc, char* argv[]){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "rt", stdin);
    string str;
    cin >> str;
    // 0 ~ 7/ 1~7 / 2~7 / 3~7 / 4~7 / 5~7 / 6~7
    int n = str.length();
    for(int i=0;i<n;i++){
        s[i] = str.substr(i,str.length()-i);    // str배열에서 i번쨰부터 str.length()-i 까지 잘라서 s[i]에 대입
        // cout << str << '\n';  // 모두 baekjoon이 출력됨
    }
    sort(s, s+n);
    for(int i=0;i<n; i++)   cout << s[i] << '\n';
    return 0;
}