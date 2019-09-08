# Doesn't work, will see it some other time
# Output: Wrong Answer
# url: codechef.com/JULY18B/problems/MGCSET


def sub_lists(list1):
    sublist = []
    for i in range(len(list1)):
        for j in range(i + 1, len(list1)+1):
            sub = list1[i:j]
            sublist.append(sub)
    return sublist


T = int(input())
for test_case in range(T):
    n, m = map(int, input().split(" "))
    a = map(int, input().split(" "))
    a = list(a)
    sub_a = sub_lists(a)
    counter = 0
    for sub in sub_a:
        sub_b = sub_lists(sub)
        flag = 0
        for newsub in sub_b:
            if sum(newsub) % m != 0 or newsub == sub_b:
                flag += 1
        if flag == 0:
            counter += 1
    print(counter)
