t = int(input())

def comma1():
    print(8,8)
    print(7,7)
    print(6,8)
    print(1,3)
    print(3,1)
    print(8,6)
    print(7,5)
    print(4,8)
    print(1,5)
    print(5,1)
    print(8,4)
    print(7,3)
    print(2,8)
    print(1,7)
    print(7,1)
    print(8,2)

for testCase in range(t):
    r0, c0 = [int(i) for i in input().split()]
    if (r0,c0) == (1,1):
        print(16)
        comma1()
    
    elif (r0,c0) in [(2,2), (3,3), (4,4), (5,5), (6,6), (7,7), (8,8)]:
        print(17)
        print(1,1)
        comma1()

    elif (r0,c0) in [(1,3), (3,1)]:
        print(18)
        print(2,2)
        print(1,1)
        comma1()

    elif (r0,c0) in [(5,1), (1,5), (4,2), (2,4)]:
        print(18)
        print(3,3)
        print(1,1)
        comma1()

    elif (r0,c0) in [(7,1), (1,7), (6,2), (2,6), (5,3), (3,5)]:
        print(18)
        print(4,4)
        print(1,1)
        comma1()

    elif (r0,c0) in [(8,2), (2,8), (7,3), (3,7), (6,4), (4,6)]:
        print(18)
        print(5,5)
        print(1,1)
        comma1()

    elif (r0,c0) in [(8,4), (4,8), (7,5), (5,7)]:
        print(18)
        print(6,6)
        print(1,1)
        comma1()

    elif (r0,c0) in [(8,6), (6,8)]:
        print(18)
        print(7,7)
        print(1,1)
        comma1()





