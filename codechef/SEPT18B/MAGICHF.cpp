//
// Created by beerbongs on 9/7/18.
//
#include<iostream>
using namespace std;

main()
{
    int T=0;
    cin>>T;
    for(int testcase=0;testcase<T;testcase++)
    {
       int N,X,S;
       cin>>N;
       cin>>X;
       cin>>S;
       int goldcoin = X;
       for(int swaps=0; swaps<S; swaps++)
       {
           int A,B;
           cin>>A;
           cin>>B;
           if(goldcoin==A)
               goldcoin=B;
           else if(goldcoin==B)
               goldcoin=A;
           else continue;
       }
       cout<<goldcoin<<endl;
    }
}

