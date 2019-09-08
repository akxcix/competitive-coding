#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    long long n,k,c;
	    cin>>n>>k;
	    c=n/k;
	    if(c%k==0) {
	        cout<<"NO"<<endl;
	        
	    }
	    else {
	        cout<<"YES"<<endl;
	        
	    }
	}
	return 0;
}

