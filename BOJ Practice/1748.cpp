#include <iostream>
using namespace std;
int main(){
   int n, i, digit, k=1, sum=0, ans=0;
   cin >> n;
   for(digit=1;(digit*9)+sum<n;digit*=10,k++){
       ans += ((digit * 9) * k);
       sum += (digit * 9);
   }
   ans += (k * (n-digit+1));
   cout << ans << endl;
   return 0;
}