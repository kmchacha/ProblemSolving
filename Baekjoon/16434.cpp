#include<cstdio>
#include<algorithm>
#include<climits>
#include<iostream>

using namespace std;

long long int HMAX=1; // 최대 생명력 
long long int HCur; //현재 용사의 생명력 
long long int HATK; // 용사의 공격력 
int N;
int monster[123457][3];
long long int ans = LLONG_MAX;
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);

   long long int first=1;
   long long int HATK_cha; // 주인공의 증감되는 공격력 
   cin >> N;
   cin >> HATK; //원래 공격력 
   long long int MID;
   long long int HP_mon; //몬스터의 남은 HP
   long long int HP_cha; //주인공의 남은 HP
   bool flag_mon; //몬스터의 생존 
   bool flag_cha; //캐릭터의 생존 
   for(int i = 0; i < N; i++){
      for(int j = 0; j<3; j++){
         cin >> monster[i][j]; // 몬스터 정보입력
      }
      if(monster[i][0]==1) HMAX += ((long long) monster[i][1]* (long long)monster[i][2]);
   }
   
   while(first<= HMAX)
   {
      MID = (first+HMAX)/2;
      flag_mon = true; //monster 생존 
      flag_cha = true; //주인공 생존 
      HATK_cha = HATK; //공격력 초기화 
      HP_cha = MID;
      
      for(int i=0; i<N;i++)
      {
         if(monster[i][0]==1)
         {
            flag_mon = true;
            HP_mon = monster[i][2];
            long long int p1 = (HP_mon / HATK_cha);
            long long int p2 = (HP_cha / monster[i][1]);

            HP_mon -= (min(p1, p2) * HATK_cha);
            HP_cha -= (min(p1, p2) * monster[i][1]);

            if(HP_mon <= 0){
               continue;
            }else if(HP_cha <=0){
               flag_cha = false;
               break;
            }

            HP_mon -= HATK_cha;
            if(HP_mon <= 0) continue;


            HP_cha -= monster[i][1];
            if(HP_cha <=0) {
               flag_cha = false;
               break;
            }
            //cout << "HP_mon :"  << HP_mon << " HATK_cha :"<< HATK_cha << endl;
            //cout << "HP_cha :"  << HP_cha << " monster :"<< monster[i][1] << endl;
            
            // while(flag_mon && flag_cha)
            // {
            //    HP_mon -= HATK_cha; //1. 용사의 공격력만큼 몬스터의 생명력을 깎는다.
            //    if(HP_mon <= 0) { flag_mon = false; break;} //2. 몬스터의 생명이 2이하이면 전투가 종료되고 다음 방으로 간다. 
            //    HP_cha -= monster[i][1]; //3.몬스터의 공격력만큼 용사의 생명력 HCurHP를 깎습니다.
            //    if(HP_cha <= 0){ flag_cha = false; break;} //4. 용사의 생명력이 0 이하이면 전투가 종료되고 용사는 사망합니다.
            // //   cout << "MID = " << MID << "n = "<< i <<"\n";
            // }
            // cout << "HP_cha :"  << HP_cha << " HP_mon :"<< HP_mon << endl;
         }
         else
         {
            HATK_cha += monster[i][1]; //공격력 증가 
            HP_cha = HP_cha + monster[i][2]; //체력 증가 
            if(HP_cha > MID ) HP_cha = MID; //한도 이상이면 체력을 MID로 맞춘다. 
         }
         
         if(!flag_cha) break; //캐릭터가 죽으면 다시 해야됨 
      }
      if(!flag_cha) first = MID+1;
      else if(flag_cha) {
         HMAX = MID-1;
      
         if(ans > MID) ans = MID;
      }
      //cout << "first = " << first <<"\n";
      //cout << "HMAX = " << HMAX <<"\n";
      
   } 
   
   cout << ans << '\n';
   
   return 0;
}