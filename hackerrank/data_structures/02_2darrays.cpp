#include <bits/stdc++.h>
using namespace std;

int hourglass_sum(int arr[6][6], int i, int j) {
  int sum = arr[i][j] + arr[i][j + 1] + arr[i][j + 2];
  sum = sum + arr[i+1][j+1];
  sum = sum + arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
  return sum;
}
int main() {
    int arr[6][6];
    for(int i =0; i<6 ; i++){
        for (int j=0;j<6;j++){
            cin>>arr[i][j];
        }
    }
    int max=-100000000;
    for(int i =0; i<4; i++){
        for (int j=0;j<4;j++){
            if(hourglass_sum(arr,i,j)>max){
              max = hourglass_sum(arr, i, j);
            }
        }
    }
    cout<<max;
    return 0;
}
