#include<iostream>
using namespace std;

int main(){
    int N;
    cin>>N;
    int arr[N];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    while(N--){
        cout<<arr[N]<<' ';
    }
    return 0;
}
