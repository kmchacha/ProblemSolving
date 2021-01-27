#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input1.txt", "rt", stdin);
    int n, a, b, j = 0, z = 0;
    string str1, str2;
    string tmp1, tmp2;
    cin >> n;
    cin >> str1;
    cin >> str2;
    cin >> a >> b;

    for(int i=0;i<n;i++){
        if(i==a || i==b){
            tmp1 = tmp1 + str1[i];
        }else tmp2 = tmp2 + str1[i];
    }

    int flag=0;
    int size = str2.size();
    for(int i = 0; i < size; i++){
        if(tmp2[j] == str2[i]){
            cout << tmp2[j] << " " << str2[i]  << endl;
            j++;
        } else{
            if(str2[i] == tmp1[z]){
                cout << str2[i] << " " << tmp1[z] << endl;
                z++;
            }
            else{
                cout << str2[i] << " " << tmp1[z] << endl;
                flag=1;
                break;
            }
        }
    }
    if(flag==0) cout << "YES"; 
    else cout << "NO";
    return 0;
}