/* Author: Adarsh Kumar
 * GitHub/GitLab: @iamadarshk
 */

#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int d;
        cin>>d;
        char s[d];
        cin>>s;
        int count=0;
        for(int i=0;i<d;i++){
            if(s[i]=='P'){
                count++;
            }
        }
        double att=static_cast<double>(count)/d;
        if(att>=0.75){
            cout<<0<<endl;
        }
        else{
            cout<<ceil(0.75*d)-count<<endl;
        }
    }
    
    return 0;
}

