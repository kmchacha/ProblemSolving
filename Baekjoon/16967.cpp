#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int h, w , x, y;
    cin >> h >> w >> x >> y;
    // 배열 arr[h+x][w+y] 생성, 0으로 초기화
    vector<vector<int> > B(h+x+1, vector<int>(w+y+1, 0));
    // 배열 arr[h+1][w+1] 생성, 0으로 초기화
    vector<vector<int> > A(h+1, vector<int>(w+1,0));

    for(int i=1;i<=h+x;i++){
        for(int j=1;j<=w+y;j++){
            cin >> B[i][j];
        }
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(x+1<=i && y+1<=j){ // 2 <= i , 2 <= j
                A[i][j] = B[i][j] - A[i-x][j-y]; // B의 배열로 빼게 되면 값이 달라지므로 A 배열로 빼주어야한다
            }
            else A[i][j] = B[i][j];
        }
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cout << A[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}