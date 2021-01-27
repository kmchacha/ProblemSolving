#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool compare(string& s1, string& s2){
    if(s1.length() != s2.length()){
        return s1.length() < s2.length();
    }else{
        int n = s1.length();
        int cnt1=0, cnt2=0;
        for(int i=0;i<n;i++){
            if(s1[i]>=0+'0' && s1[i]<=9+'0') cnt1+=s1[i]-'0';
            if(s2[i]>=0+'0' && s2[i]<=9+'0') cnt2+=s2[i]-'0';
        }

        if(cnt1!=cnt2){
            if(cnt1 < cnt2) return cnt1 < cnt2;
            else return cnt1 < cnt2;
        }else {

            for(int i=0;i<n;i++){
                if((s1[i]>= 0+'0' && s1[i]<=9 + '0') && (s2[i]>='A' && s2[i] <= 'Z')){
                    return true;
                }else if((s2[i]>= 0+'0' && s2[i]<=9 + '0') && (s1[i]>='A' && s1[i]<='Z')){
                    return false;
                }else{
                    if(s1[i] > s2[i]) return false;
                    else if(s1[i] < s2[i]) return true;
                }
            }
        }

        return s1 < s2;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "rt", stdin);
    int n;
    cin >> n;
    string str[1001];
    for(int i=0;i<n;i++){
        cin >> str[i];
    }
    sort(str, str+n, compare);
    for(int i=0;i<n;i++) cout << str[i] << '\n';
    return 0;
}