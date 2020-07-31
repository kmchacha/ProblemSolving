// 일곱 난쟁이 2309
#include <iostream>

int
main(int argc, const char* argv[])
{   
    //freopen("input.txt", "rt", stdin);
    using namespace std;
    int i,j, a[10], temp, sum=0, n=9;
    for(i=0;i<n;i++){
        cin >> a[i];
        sum += a[i];
    }
    
    // bubble sort
    for(i=0; i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(sum - a[i] - a[j] == 100){
                for(int k=0;k<n;k++){
                    if(i==k || j==k) continue;
                    cout << a[k] << '\n';
                }
                return 0;
            }
        }
    }
}