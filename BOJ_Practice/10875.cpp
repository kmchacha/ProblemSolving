#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    freopen("input.txt", "rt", stdin);
    int L, n, i, j, size;
    cin >> L >> n;
    int** a = (int**)malloc(sizeof(int*)*2*L+1);
    for(i=0;i<2*L+1;i++){
        a[i] = (int *)malloc(sizeof(int)*2*L+1);
    }
    size = 2 * L + 1;
    for(i=0;i<2*L+1;i++){
        for(j=0;j<2*L+1;j++){
            a[i][j] = 0;
        }
    }
    int dist, x=(2*L+1)/2, y=(2*L+1)/2;
    char direction = 'R'; // L R
    for(i=0;i<n;i++){
        cin >> dist ;
        
        
        cin >> direction;
    }

    return 0;
}