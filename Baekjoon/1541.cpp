#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int arr[100];

// 뺄셈 이후마다 괄호를 친다... 그러면 최소값이 나오게 된다
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    string str;
    int ans=0, temp=0, j=0, sum=0;

    cin >> str;
    for(int i=0;i<str.length();i++){
        if(str[i]=='+'){
            sum += temp;
            temp = 0;
        }
        else if(str[i]=='-'){
            sum += temp;
            arr[j]= sum;
            j++;
            temp = 0;
            sum = 0;
        }
        else {
            temp = (str[i]-'0') + (temp * 10);
        }
    }
    sum += temp;
    arr[j]=sum;
    for(int i=0;i<25;i++){
        cout << arr[i] << " ";
    }
    cout << sum << endl;
    ans = arr[0];
    for(int i=1;i<25;i++){
        ans -= arr[i];
    }
    cout << ans;
    return 0;
}