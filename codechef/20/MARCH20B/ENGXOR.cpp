#include<iostream>
using namespace std;

#define P2(n) n, n ^ 1, n ^ 1, n 
#define P4(n) P2(n), P2(n ^ 1), P2(n ^ 1), P2(n) 
#define P6(n) P4(n), P4(n ^ 1), P4(n ^ 1), P4(n) 
#define LOOK_UP P6(0), P6(1), P6(1), P6(0) 
unsigned int table[256] = { LOOK_UP }; 
  
int parity(int num) 
{ 
    int max = 16; 
  
    while (max >= 8) { 
        num = num ^ (num >> max); 
        max = max / 2; 
    } 
  
    return table[num & 0xff]; 
} 

void fastscan(int &number)
{
    bool negative = false;
    register int c;

    number = 0;

    c = getchar();
    if (c=='-')
    {
        negative = true;

        c = getchar();
    }

    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;

    if (negative)
        number *= -1;
}

int main(){
    int t;
    fastscan(t);
    while(t--){
        int n,q;
        fastscan(n);
        fastscan(q);
        int a[n];
        int odd = 0;
        int even = 0;
        for(int i=0; i<n; i++){
            fastscan(a[i]);
            a[i] = parity(a[i]);
            if(a[i]==1){
                odd++;
            } else {
                even++;
            }
        }
        int p = 0;
        int qe=0;
        int qo=0;
        for(int i=0; i<q; i++){
            fastscan(p);
            p = parity(p);
            if(p==1){
                qe = odd;
                qo = even;
            } else {
                qe = even;
                qo = odd;
            }
            cout<<qe<<" "<<qo<<endl;
        }
    }
    return 0;
}
