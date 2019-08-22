#include<bits/stdc++.h>
using namespace std;

main(){
	int T;
	ios_base::sync_with_stdio(false);
        cin.tie(NULL);
	cin>>T;
	for(int testcase=0;testcase<T;testcase++){
		int N,K;
		cin>>N>>K;
		int S[N];
		for(int i=0;i<N;i++)
			cin>>S[i];
		sort(S,S+N,greater<int>());
		int count = K;
		while(S[count-1]==S[count] && count<N)
			count++;
		cout<<count<<endl;
	}
}
