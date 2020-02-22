# def sol(n,k):
#     ones = k%n
#     zeros = n-ones
#     alt = 0
#     count = 0
#     new_arr = []
#     if ones>zeros:
#         while count<n:
#             if alt==0:
#                 new_arr.append(1)
#                 alt = (alt+1)%2
#                 ones -=1
#                 count +=1
#             else:
#                 new_arr.append(0)
#                 alt = (alt+1)%2
#                 zeros -=1
#                 count +=1
#             if zeros == 0:
#                 break
#         while count<n:
#             new_arr.append(1)
#             count+=1
#     if zeros>ones:
#         while count<n:
#             if alt==0:
#                 new_arr.append(0)
#                 alt = (alt+1)%2
#                 zeros -=1
#                 count +=1
#             else:
#                 new_arr.append(1)
#                 alt = (alt+1)%2
#                 ones -=1
#                 count +=1
#             if ones == 0:
#                 break
#         while count<n:
#             new_arr.append(0)
#             count+=1

#     B = 0
#     for i in range(n-1):
#         B += abs(new_arr[i]-new_arr[i+1])

#     return(B)
        

t = int(input())
for test_case in range(t):
    n = int(input())
    k = int(input())
    ones = k%n
    zeros = n-ones
    alt = 0
    count = 0
    new_arr = []
    if ones>zeros:
        while count<n:
            if alt==0:
                new_arr.append(1)
                alt = (alt+1)%2
                ones -=1
                count +=1
            else:
                new_arr.append(0)
                alt = (alt+1)%2
                zeros -=1
                count +=1
            if zeros == 0:
                break
        while count<n:
            new_arr.append(1)
            count+=1
    if zeros>=ones:
        while count<n:
            if alt==0:
                new_arr.append(0)
                alt = (alt+1)%2
                zeros -=1
                count +=1
            else:
                new_arr.append(1)
                alt = (alt+1)%2
                ones -=1
                count +=1
            if ones == 0:
                break
        while count<n:
            new_arr.append(0)
            count+=1
    B = 0
    for i in range(n-1):
        B += abs(new_arr[i]-new_arr[i+1])
    print(B)