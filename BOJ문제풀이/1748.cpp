#include <iostream>
using namespace std;
int main(){
   int n, cnt=1, sum = 0, digit=1;
   cin >> n;
   while((sum + 9*digit) < n){
       sum += (9 * digit) * cnt;
       cnt++;
       digit *= 10;
   }
   sum = sum + (cnt * (n-digit+1));
   cout << sum << endl;
   return 0;
}