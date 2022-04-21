#include <bits/stdc++.h>
using namespace std;

int main(){
    string str = "Hello, My name is KyungMin Cha and My Student Id is 216007022";

    // for(int i=0;i<str.size();i++){
    //     //if(isupper(str[i])) cout << str[i] << ' ';
    //     //if(islower(str[i])) cout << str[i] << ' ';
    //     if(isdigit(str[i])) cout << str[i] << ' ';
    // }
    // cout << endl;

    int idx, max = INT_MIN;
    while((idx=str.find(' ')) != str.npos){
        string temp = str.substr(0, idx);
        cout << temp << endl;

        int size = temp.size();
        if(size > max) {
            max = size;
        }
        str = str.substr(idx+1);

    }
    cout << str << endl;

    if(str.size() > max){
        max = str.size();
    }
    cout << max << endl;

    return 0;
}