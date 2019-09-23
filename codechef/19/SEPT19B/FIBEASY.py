fib = [0,1]
for i in range(60):
    fib.append((fib[-1]+fib[-2])%10)
t = int(input())
for testcase in range(t):
    n = int(input())
    x = 0
    while n != 0:
        n = n>>1
        x +=1
#     print('1:',x)
    x = 1<<x-1
#    print('2:',x)
    x = x%60
#     print('3:',x)
    ans = fib[x-1]
#     print('4:',ans, x)    
    print(ans)