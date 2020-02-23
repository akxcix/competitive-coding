t = int(input())
t5 = list(range(0,101,5))
for testcase in range(t):
    marks = int(input())
    if marks>=38:
        if marks in t5:
            print(marks)
        elif marks+1 in t5:
            print(marks+1)
        elif marks+2 in t5:
            print(marks+2)
        else:
            print(marks)
    else:
            print(marks)
            
    
