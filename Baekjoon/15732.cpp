#include <iostream>
#include <algorithm>

using namespace std;

int arr[10001][3], k, d;

bool count_check(int l){
    long long int cnt = 0;

    for(int i=0;i<k;i++){
        if(arr[i][0] > l) continue;

        int a = arr[i][0];
        int b = min(arr[i][1], l);

        cnt += (b-a)/arr[i][2] + 1;
    }
    return cnt < d;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    int rt=0;
    cin >> n >> k >> d;
    for(int i=0;i<k;i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

        rt = max(rt, arr[i][1]);
    }

    int lt = 1;
    while(lt<=rt){
        int mid = (lt+rt)/2;
        if(count_check(mid)){
            lt = mid + 1;
        }else{
            rt = mid - 1;
        }
    }
    cout << lt << '\n';

  return 0;
}