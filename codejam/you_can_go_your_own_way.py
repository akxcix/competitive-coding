def sol1(N, path_string):
    a = list(path_string)
    sol_string = []
    for char in a:
        if char == 'S':
            sol_string.append('E')
        else:
            sol_string.append('S')
    sol_string = ''.join(sol_string)
    return sol_string





T = int(input())
for testCase in range(T):
    N = int(input())
    path_string = input()
    sol_string = sol1(N, path_string)
    print('Case #'+str(testCase+1)+':',sol_string)