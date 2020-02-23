def multi_line_input() -> list:
    variable = []
    no_of_int=input()
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
print(sum(A))
