//
// Created by iamadarshk on 9/7/18.
//
#include<iostream>
using namespace std;

main()
{
    int T=0;
    cin>>T;
    for(int testcase=0;testcase<T;testcase++)
    {
       int N,M,X,Y;
       cin>>N;
       cin>>M;
       cin>>X;
       cin>>Y;
       if(
         (((N)%X==1)&&((M)%Y==1))
         ||(((N)%X==2)&&((M)%Y==2))
         //||(((N)%X==0)&&((M)%Y==0))
         //||(((N)%X==1)&&((M)%Y==0))
         //||(((N)%X==0)&&((M)%Y==1))
         //||(((N)%X==2)&&((M)%Y==1))
         //||(((N)%X==1)&&((M)%Y==2))
         ||(N%X==1)&&(M==Y)
         ||(N==X)&&(M%Y==1)
       )
       {
         cout<<"Chefirnemo"<<endl;
       }
       else cout<<"Pofik"<<endl;
    }
}
