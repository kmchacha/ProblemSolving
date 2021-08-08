#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "rt", stdin);
    string input;
    while(1){
        cin >> input;
        if(input == "end") break;

        // 모음 하나를 반드시 포함
        int flag = 0;
        if(input.find('a') != string::npos || input.find('e') != string::npos ||
            input.find('i') != string::npos || input.find('o') != string::npos ||
                input.find('u') != string::npos ) flag = 1;
        if(!flag) {
            cout << "<" << input << "> is not acceptable.\n";
            continue;
        }

        // 모음이 3개 혹은 자음이 3개 연속으로 오면 안된다.
        int J=0, M=0;
        for(int i=0;i<input.size();i++){
            if(input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u') {
                M++;
                J=0;
            }
            else {
                J++;
                M=0;
            }
            if(J>=3 || M>=3) flag = 0;
        }
        if(!flag) {
            cout << "<" << input << "> is not acceptable.\n";
            continue;
        }

        // 같은 글자가 연속적으로 두번 오면 안된다
        for(int i=1;i<input.size();i++){
            if(input[i] == input[i-1] && input[i] != 'e' && input[i] != 'o') flag=0;
        }
        if(!flag) {
            cout << "<" << input << "> is not acceptable.\n";
            continue;
        }

         cout << "<" << input << "> is acceptable.\n";
        
    }
    return 0;
}