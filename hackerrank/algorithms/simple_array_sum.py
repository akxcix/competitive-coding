n = input()
m = input()
l = len(m)
array=[]
number=[]
for i in range(l):
    if m[i] != ' ' :
        number.append(m[i])
    if m[i]==' ' or i == l-1:
        array.append(int(''.join(number)))
        number = []

print(sum(array))
