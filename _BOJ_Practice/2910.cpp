#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[1001][2];

bool compare(int*& p1, int*& p2){
    return *p1 < *p2;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "rt", stdin);
    int n, c, cnt=0, num;
    cin >> n >> c;

    for(int i=0;i<n;i++)    {
        cin >> num;

        int flag=0;
        for(int j=0;j<cnt;j++){
            if(arr[j][0] == num) {
                arr[j][1]++;
                flag=1;
                break;
            }
        }

        if(flag==0) arr[cnt++][0] = num;

    }
    sort(arr, arr + n, compare);


    for(int i=0;i<n;i++) {
        cout << arr[i][0] << " ";
    
    }
    
    return 0;
}