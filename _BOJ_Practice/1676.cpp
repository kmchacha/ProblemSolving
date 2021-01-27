#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main(){
    int n, i, j, temp, cnt2=0, cnt5=0;
    cin >> n;
    
    for(int i=2;i<=n;i++){
        temp = i;
        j=2;
        while(1){
            if(temp%j==0){
                if(j==2) cnt2++;
                else if(j==5) cnt5++;
                temp = temp/j;
            }
            else j++;

            if(temp==1) break;
        }
    }
    cout << min(cnt2,cnt5) << endl;

    return 0;
}