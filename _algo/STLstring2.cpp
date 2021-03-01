#include <bits/stdc++.h>
using namespace std;

int main(){
    string a = "It is time to study", res;

    // 길이가 가장 긴 단어를 출력한다
    int pos, max=INT_MIN;
    while((pos=a.find(' ')) != string::npos){ // 찾고자 하는 문자가 없지 않다면
        string tmp = a.substr(0, pos);
        cout << tmp << endl;

        int len = tmp.size();
        if(len > max) {
            max = len;
            res = tmp;
        }
        a = a.substr(pos+1);
    }
    cout << a << endl;

    if(a.size() > max)  res = a;

    cout << "가장 긴 단어는 = "<<res << endl;

    return 0;
}
