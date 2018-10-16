def multi_line_input() -> list:
    variable = []
    string=input()
    number=[]
    for i in range(len(string)):
        if string[i] != ' ' :
            number.append(string[i])
        if string[i]==' ' or i == len(string)-1:
            variable.append(int(''.join(number)))
            number = []
    return variable

A = multi_line_input()
B = multi_line_input()
a=0
b=0
for i in range(3):
    if A[i] > B[i]:
        a +=1
    elif A[i] < B[i]:
        b += 1

print(a,b)
