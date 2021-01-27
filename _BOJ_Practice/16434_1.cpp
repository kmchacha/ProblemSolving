#include<cstdio>
#include<algorithm>
#include<climits>
#include<iostream>

using namespace std;

long long int HMAX = LLONG_MAX; // 최대 생명력 
long long int HCur; //현재 용사의 생명력 
long long int HATK; // 용사의 공격력 
int N;

int monster[123456][3];
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   freopen("input.txt", "rt", stdin);

   long long int first=1;
   long long int HATK_cha; // 주인공의 증감되는 공격력 
   cin >> N;
   cin >> HATK; //원래 공격력 

   long long int MID;
   long long int HP_cha; //주인공의 남은 HP
   bool flag_mon; //몬스터의 생존 
   bool flag_cha; //캐릭터의 생존 
   for(int i = 0; i < N; i++)
      for(int j = 0; j<3; j++)
         cin >> monster[i][j]; // 몬스터 정보입력
         
   
   while(first <= HMAX)
   {
      MID = (first+HMAX)/2;
      flag_mon = true; //monster 생존 
      flag_cha = true; //주인공 생존 
      HATK_cha = HATK; //공격력 초기화 
      HP_cha = MID;
      
      for(int i=0; i<N ;i++)
      {
         flag_mon = true;
         if(monster[i][0]==1)
            if(HP_cha > (monster[i][2]-1)/HATK_cha*monster[i][1])
            {
               HP_cha = HP_cha - ((monster[i][2]-1)/HATK_cha) * monster[i][1];
               flag_mon = false;
            }
            else{
               flag_cha = false;
               break;
            }
         else
         {
            HATK_cha += monster[i][1]; //공격력 증가 
            HP_cha = HP_cha + monster[i][2]; //체력 증가 
            HP_cha = min(MID, HP_cha); //한도 이상이면 체력을 MID로 맞춘다. 
         }
         //if(!flag_cha) break; //캐릭터가 죽으면 다시 해야됨 
         
      }
      if(!flag_cha) first = MID+1;
      else if(flag_cha) HMAX = MID-1;
      
   //   cout << "first = " << first <<"\n";
   //   cout << "HMAX = " << HMAX <<"\n";
      
   
   } 
   
   cout << first << "\n";
   
   return 0;
}