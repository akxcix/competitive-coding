T = int(input())
for testcase in range(T):
    N,K = map(int,input().split())
    S = list(map(int,input().split())) 
    S = sorted(S,reverse=True)
    count = K
    while(S[count-1]==S[count] and count<N):
        count+=1
    print(count)
